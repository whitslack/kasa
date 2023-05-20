#include <stdint.h>
#include <stdio.h>

#include <err.h>
#include <netdb.h>
#include <sysexits.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/uio.h>


static void xor171_enc(unsigned char buf[], size_t n) {
	int key = 171;
	for (unsigned char *p = buf, *e = buf + n; p != e; ++p) {
		*p = (key ^= *p);
	}
}

static void xor171_dec(unsigned char buf[], size_t n) {
	int key = 171;
	for (unsigned char *p = buf, *e = buf + n; p != e; ++p) {
		*p ^= key;
		key ^= *p;
	}
}

static void read_fully(int fd, void *buf, size_t n) {
	while (n) {
		ssize_t r = read(fd, buf, n);
		if (r < 0) {
			err(EX_IOERR, "read");
		}
		buf = (unsigned char *) buf + r;
		n -= r;
	}
}

static void writev_fully(int fd, struct iovec iov[], int iovcnt) {
	for (struct iovec *end = iov + iovcnt; iov != end;) {
		ssize_t w = writev(fd, iov, (int) (end - iov));
		if (w < 0) {
			err(EX_IOERR, "write");
		}
		for (; w > 0; ++iov) {
			if (iov->iov_len > (size_t) w) {
				iov->iov_base = (unsigned char *) iov->iov_base + w;
				iov->iov_len -= w;
				break;
			}
			w -= iov->iov_len;
			iov->iov_base = (unsigned char *) iov->iov_base + iov->iov_len;
			iov->iov_len = 0;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <host>\n", argc > 0 ? argv[0] : "kasa");
		return EX_USAGE;
	}

	struct addrinfo hints = {
		.ai_family = AF_INET,
		.ai_socktype = SOCK_STREAM,
	}, *info, *pai;
	int e;
	if ((e = getaddrinfo(argv[1], NULL, &hints, &info)) != 0) {
		if (e == EAI_SYSTEM) {
			err(EX_OSERR, "getaddrinfo: %s", argv[1]);
		}
		fprintf(stderr, "%s: %s: %s: %s\n", argv[0], "getaddrinfo", argv[1], gai_strerror(e));
		return EX_NOHOST;
	}

	int sock = -1;
	for (pai = info; pai != NULL; pai = pai->ai_next) {
		if ((sock = socket(pai->ai_family, pai->ai_socktype, pai->ai_protocol)) < 0) {
			err(EX_OSERR, "socket");
		}
		((struct sockaddr_in *) pai->ai_addr)->sin_port = htons(9999);
		if (connect(sock, pai->ai_addr, pai->ai_addrlen) == 0) {
			goto connected;
		}
		if (close(sock) < 0) {
			err(EX_OSERR, "close");
		}
	}
	err(EX_UNAVAILABLE, "connect");

connected:
	freeaddrinfo(info);

	struct timeval timeout = {
		.tv_sec = 15,
	};
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof timeout) < 0) {
		err(EX_OSERR, "setsockopt");
	}

	unsigned char buf[4096], *p = buf;
	for (;;) {
		int c = getchar();
		if (c == EOF) {
			return p == buf ? EX_OK : EX_IOERR;
		}
		if (c != '\n') {
			if (p == buf + sizeof buf) {
				return EX_DATAERR;
			}
			*p++ = (unsigned char) c;
		}
		else if (p != buf) {
			size_t n = p - buf;
			uint32_t len_be = htonl((uint32_t) n);
			xor171_enc(buf, n);
			struct iovec iov[2] = {
				{ .iov_base = &len_be, .iov_len = sizeof len_be },
				{ .iov_base = buf, .iov_len = n }
			};
			writev_fully(sock, iov, sizeof iov / sizeof *iov);
			read_fully(sock, &len_be, sizeof len_be);
			n = ntohl(len_be);
			if (n > sizeof buf) {
				return EX_PROTOCOL;
			}
			read_fully(sock, buf, n);
			xor171_dec(buf, n);
			fwrite(buf, 1, n, stdout);
			putchar('\n');
			p = buf;
		}
	}
}
