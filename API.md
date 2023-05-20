This is the document that I wish existed when I began tinkering with Kasa Smart devices.



# `anti_theft`

Away Mode module.


## `add_rule` / `edit_rule`

Adds/edits an Away Mode rule.

### Request

```json
{
	"anti_theft": {
		"edit_rule": {
			"id": "…",
			"name": "…",
			"enable": 1,
			"wday": [1, 1, 1, 1, 1, 1, 1],
			"stime_opt": 2,
			"soffset": 0,
			"smin": 0,
			"etime_opt": 0,
			"eoffset": 0,
			"emin": 0,
			"frequency": 5,
			"repeat": 1,
			"year": 2000,
			"month": 1,
			"day": 1,
			"force": 0,
			"duration": 2,
			"lastFor": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | The device-assigned identifier of the Away Mode rule to edit. Omitted in `add_rule`. |
| `name` | string | A user-specified name for the rule. |
| `enable` | enum | 0 = disable rule <br/> 1 = enable rule |
| `wday` | array | Weekdays on which the rule repeats. The first element corresponds to Sunday. |
| `stime_opt` | enum | 0 = rule begins at `smin` minutes past midnight <br/> 1 = rule begins at sunrise + `soffset` <br/> 2 = rule begins at sunset + `soffset` |
| `smin` | integer | The time of day at which the rule is to begin, in minutes past midnight. Omitted unless `stime_opt` is 0. |
| `soffset` | integer | The offset from sunrise/sunset at which the rule is to begin, in minutes. May be negative. Omitted if `stime_opt` is 0. |
| `etime_opt` | enum | 0 = rule ends at `emin` minutes past midnight <br/> 1 = rule ends at sunrise + `eoffset` <br/> 2 = rule ends at sunset + `eoffset` |
| `emin` | integer | The time of day at which the rule is to end, in minutes past midnight. Omitted unless `etime_opt` is 0. |
| `eoffset` | integer | The offset from sunrise/sunset at which the rule is to end, in minutes. May be negative. Omitted if `etime_opt` is 0. |
| `frequency` | integer | ??? Maybe the number of times to turn on the load during the rule interval? |
| `repeat` | enum | 0 = rule does not repeat <br/> 1 = rule repeats |
| `year` | integer | The four-digit year in which the rule is to begin. Omitted if `repeat` is 1. |
| `month` | enum | The month of the year in which the rule is to begin. Omitted if `repeat` is 1. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `day` | integer | The day of the month on which the rule is to begin, 1-31. Omitted if `repeat` is 1. |
| `force` | enum | ??? |
| `duration` | integer | ??? Maybe the duration that the load is switched on, in minutes? Not returned from `get_rules`. |
| `lastFor` | integer | ??? Maybe the number of days that the rule runs for? Not returned from `get_rules`. |

### Response

```json
{
	"anti_theft": {
		"add_rule": {
			"id": "…",
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | A device-assigned identifier for the new rule. Omitted in the response to `edit_rule`. |


## `delete_all_rules`

Deletes all Away Mode rules.

### Request

```json
{
	"anti_theft": {
		"delete_all_rules": {}
	}
}
```

### Response

```json
{
	"anti_theft": {
		"delete_all_rules": {
			"err_code": 0
		}
	}
}
```


## `delete_rule`

Deletes an Away Mode rule.

### Request

```json
{
	"anti_theft": {
		"delete_rule": {
			"id": "…"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | The device-assigned identifier of the Away Mode rule to delete. |

### Response

```json
{
	"anti_theft": {
		"delete_rule": {
			"err_code": 0
		}
	}
}
```


## `get_rules`

Returns the configured Away Mode rules.

### Request

```json
{
	"anti_theft": {
		"get_rules": {}
	}
}
```

### Response

```json
{
	"anti_theft": {
		"get_rules": {
			"rule_list": [
				{
					"id": "…",
					"name": "…",
					"enable": 1,
					"wday": [1, 1, 1, 1, 1, 1, 1],
					"stime_opt": 2,
					"soffset": 0,
					"smin": 0,
					"etime_opt": 0,
					"eoffset": 0,
					"emin": 0,
					"frequency": 5,
					"repeat": 1,
					"year": 2000,
					"month": 1,
					"day": 1
				}
			],
			"version": 2,
			"enable": 1,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `rule_list` | array | A list of configured Away Mode rules. |
| `id` | string | The device-assigned identifier of an Away Mode rule. |
| `name` | string | The user-specified name of the rule. |
| `enable` | enum | 0 = rule is disabled <br/> 1 = rule is enabled |
| `wday` | array | Weekdays on which the rule repeats. The first element corresponds to Sunday. |
| `stime_opt` | enum | 0 = rule begins at `smin` minutes past midnight <br/> 1 = rule begins at sunrise + `soffset` <br/> 2 = rule begins at sunset + `soffset` |
| `smin` | integer | The time of day at which the rule begins, in minutes past midnight. |
| `soffset` | integer | The offset from sunrise/sunset at which the rule begins, in minutes. May be negative. Omitted if `stime_opt` is 0. |
| `etime_opt` | enum | 0 = rule ends at `emin` minutes past midnight <br/> 1 = rule ends at sunrise + `eoffset` <br/> 2 = rule ends at sunset + `eoffset` |
| `emin` | integer | The time of day at which the rule ends, in minutes past midnight. |
| `eoffset` | integer | The offset from sunrise/sunset at which the rule ends, in minutes. May be negative. Omitted if `etime_opt` is 0. |
| `frequency` | integer | ??? Maybe the number of times to turn on the load during the rule interval? |
| `repeat` | enum | 0 = rule does not repeat <br/> 1 = rule repeats |
| `year` | integer | The four-digit year in which the rule begins. Omitted if `repeat` is 1. |
| `month` | enum | The month of the year in which the rule begins. Omitted if `repeat` is 1. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `day` | integer | The day of the month on which the rule begins, 1-31. Omitted if `repeat` is 1. |
| `version` | integer | ??? |
| `enable` | enum | 0 = Away Mode is disabled <br/> 1 = Away Mode is enabled |


## `set_overall_enable`

Enables or disables Away Mode.

### Request

```json
{
	"anti_theft": {
		"set_overall_enable": {
			"enable": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `enable` | enum | 0 = disable Away Mode <br/> 1 = enable Away Mode |

### Response

```json
{
	"anti_theft": {
		"set_overall_enable": {
			"err_code": 0
		}
	}
}
```



# `cnCloud`

Cloud service module.

**Note:** This module is named `smartlife.iot.common.cloud` in some devices.


## `bind`

Binds the device to the cloud service.

### Request

```json
{
	"cnCloud": {
		"bind": {
			"username": "…",
			"password": "…"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `username` | string | The username of the TP-Link Kasa account to which to bind the device. |
| `password` | string | The password of the specified account. |

### Response

???


## `get_info`

Returns the device's current cloud configuration.

### Request

```json
{
	"cnCloud": {
		"get_info": {}
	}
}
```

### Response

```json
{
	"cnCloud": {
		"get_info": {
			"username": "",
			"server": "n-devs.tplinkcloud.com",
			"binded": 0,
			"cld_connection": 0,
			"illegalType": 0,
			"stopConnect": 0,
			"tcspStatus": 0,
			"fwDlPage": "",
			"tcspInfo": "",
			"fwNotifyType": -1,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `username` | string | The username of the TP-Link Kasa account to which the device is bound. |
| `server` | string | The host name of the cloud service. |
| `binded` | enum | 0 = not bound <br/> 1 = bound |
| `cld_connection` | enum | ??? |
| `illegalType` | enum | ??? |
| `stopConnect` | enum | ??? |
| `tcspStatus` | enum | ??? |
| `fwDlPage` | string | ??? |
| `tcspInfo` | string | ??? |
| `fwNotifyType` | enum | ??? |


## `get_intl_fw_list`

Returns a list of firmwares for the device from the cloud.

### Request

```json
{
	"cnCloud": {
		"get_intl_fw_list": {}
	}
}
```

### Response

???


## `set_server_url`

Specifies the URL of the cloud service.

### Request

```json
{
	"cnCloud": {
		"set_server_url": {
			"server": "…"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `server` | string | The URL of the cloud service. |

### Response

???


## `unbind`

Unbinds the device from the cloud service.

### Request

```json
{
	"cnCloud": {
		"unbind": {}
	}
}
```

### Response

???



# `count_down`

Count-down timer module.


## `add_rule` / `edit_rule`

Adds/edits a count-down timer rule.

### Request

```json
{
	"count_down": {
		"edit_rule": {
			"id": "…",
			"name": "…",
			"enable": 1,
			"delay": 60,
			"act": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | The device-assigned identifier of the count-down timer rule to edit. Omitted in `add_rule`. |
| `name` | string | A user-specified name for the rule. |
| `enable` | enum | 0 = disable rule <br/> 1 = enable rule |
| `delay` | integer | The initial count-down time, in seconds. |
| `act` | enum | Action to take when count-down timer lapses. <br/> 0 = turn off switch <br/> 1 = turn on switch |

### Response

```json
{
	"count_down": {
		"add_rule": {
			"id": "…",
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | A device-assigned identifier for the new rule. Omitted in the response to `edit_rule`. |


## `delete_all_rules`

Deletes all count-down timer rules.

### Request

```json
{
	"count_down": {
		"delete_all_rules": {}
	}
}
```

### Response

```json
{
	"count_down": {
		"delete_all_rules": {
			"err_code": 0
		}
	}
}
```


## `delete_rule`

Deletes a count-down timer rule.

### Request

```json
{
	"count_down": {
		"delete_rule": {
			"id": "…"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | The device-assigned identifier of the count-down timer rule to delete. |

### Response

```json
{
	"count_down": {
		"delete_rule": {
			"err_code": 0
		}
	}
}
```


## `get_rules`

Returns the configured count-down timer rules.

### Request

```json
{
	"count_down": {
		"get_rules": {}
	}
}
```

### Response

```json
{
	"count_down": {
		"get_rules": {
			"rule_list": [
				{
					"id": "…",
					"name": "…",
					"enable": 1,
					"delay": 60,
					"act": 1,
					"remain": 42
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `rule_list` | array | A list of configured count-down timer rules. |
| `id` | string | The device-assigned identifier of a count-down timer rule. |
| `name` | string | The user-specified name of the rule. |
| `enable` | enum | 0 = rule is disabled <br/> 1 = rule is enabled |
| `delay` | integer | The initial count-down time, in seconds. |
| `act` | enum | Action to take when count-down timer lapses. <br/> 0 = turn off switch <br/> 1 = turn on switch |
| `remain` | integer | The count-down time remaining, in seconds. |


# `emeter`

Energy meter module.

**Note:** This module is named `smartlife.iot.common.emeter` in some devices.


## `erase_emeter_stat`

Erases all historical energy consumption records.

### Request

```json
{
	"emeter": {
		"erase_emeter_stat": {}
	}
}
```

### Response

```json
{
	"emeter": {
		"erase_emeter_stat": {
			"err_code": 0
		}
	}
}
```


## `get_realtime`

Returns instantaneous power consumption readings.

### Request

```json
{
	"emeter": {
		"get_realtime": {}
	}
}
```

### Response

```json
{
	"emeter": {
		"get_realtime": {
			"current_ma": 0,
			"voltage_mv": 120000,
			"power_mw": 0,
			"total_wh": 0,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `current_ma` | integer | The instantaneous current reading, in milliamps. |
| `voltage_mv` | integer | The instantaneous voltage reading, in millivolts. |
| `power_mw` | integer | The instantaneous power reading, in milliwatts. |
| `total_wh` | integer | The cumulative energy consumption, in watt-hours. |


## `get_daystat`

Returns historical energy consumption per day in a specified year and month.

### Request

```json
{
	"emeter": {
		"get_daystat": {
			"year": 2000,
			"month": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `year` | integer | The four-digit year from which to return historical energy consumption. |
| `month` | enum | The month from which to return historical energy consumption. <br/> 1 = January <br/> ⋮ <br/> 12 = December |

### Response

```json
{
	"emeter": {
		"get_daystat": {
			"day_list": [
				{
					"year": 2000,
					"month": 1,
					"day": 1,
					"energy_wh": 42
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `day_list` | array | A list of per-day historical energy consumption records. |
| `year` | integer | The four-digit year of an energy consumption record. |
| `month` | enum | The month of an energy consumption record. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `day` | integer | The day of the month of an energy consumption record, 1-31. |
| `energy_wh` | integer | The historical energy consumption recorded on the indicated day, in watt-hours. |


## `get_monthstat`

Returns historical energy consumption per month in a specified year.

### Request

```json
{
	"emeter": {
		"get_monthstat": {
			"year": 2000
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `year` | integer | The four-digit year from which to return historical energy consumption. |

### Response

```json
{
	"emeter": {
		"get_monthstat": {
			"month_list": [
				{
					"year": 2000,
					"month": 1,
					"energy_wh": 4269
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `month_list` | array | A list of per-month historical energy consumption records. |
| `year` | integer | The four-digit year of an energy consumption record. |
| `month` | enum | The month of an energy consumption record. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `energy_wh` | integer | The historical energy consumption recorded in the indicated month, in watt-hours. |



# `netif`

Network interface module.

**Note:** This module is named `smartlife.iot.common.softaponboarding` in some devices.


## `get_scaninfo`

Returns a survey of Wi-Fi networks visible to the device.

### Request

```json
{
	"netif": {
		"get_scaninfo": {
			"refresh": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `refresh` | enum | 0 = return previously cached results <br/> 1 = perform fresh scan |

### Response

```json
{
	"netif": {
		"get_scaninfo": {
			"ap_list": [
				{
					"ssid": "…",
					"key_type": 3,
					"rssi": -42
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `ap_list` | array | A list of Wi-Fi networks visible to the device. |
| `ssid` | string | The SSID of a visible Wi-Fi network. |
| `key_type` | enum | 0 = open network <br/> 3 = WPA2 Personal |
| `rssi` | integer | Received signal strength of the Wi-Fi network, in dBm. <br/> Not all devices report this. |


## `get_stainfo`

Returns the Wi-Fi station configuration.

### Request

```json
{
	"netif": {
		"get_stainfo": {}
	}
}
```

### Response

```json
{
	"netif": {
		"get_stainfo": {
			"ssid": "…",
			"key_type": 3,
			"rssi": -42,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `ssid` | string | The SSID of the Wi-Fi network. |
| `key_type` | enum | 0 = open network <br/> 3 = WPA2 Personal |
| `rssi` | integer | Received signal strength of the Wi-Fi network, in dBm. |


## `set_stainfo`

Specifies the SSID and passphrase of the Wi-Fi network to which the device should connect.

### Request

```json
{
	"netif": {
		"set_stainfo": {
			"ssid": "…",
			"password": "…",
			"key_type": 3
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `ssid` | string | The SSID of the Wi-Fi network. |
| `password` | string | The passphrase of the Wi-Fi network. |
| `key_type` | enum | 0 = open network <br/> 3 = WPA2 Personal |

### Response

```json
{
	"netif": {
		"set_stainfo": {
			"err_code": 0
		}
	}
}
```


# `schedule`

Schedule module.

**Note:** This module is named `smartlife.iot.common.schedule` in some devices.


## `add_rule` / `edit_rule`

Adds/edits a schedule rule.

### Request

```json
{
	"schedule": {
		"edit_rule": {
			"id": "…",
			"name": "…",
			"enable": 1,
			"wday": [1, 1, 1, 1, 1, 1, 1],
			"stime_opt": 1,
			"smin": 0,
			"soffset": 0,
			"sact": 1,
			"s_light": {
				"on_off": 1,
				"mode": "customize_preset",
				"hue": 0,
				"saturation": 0,
				"color_temp": 2700,
				"brightness": 25,
				"transition_period": 1000
			},
			"etime_opt": 2,
			"emin": 0,
			"eoffset": 0,
			"eact": 0,
			"e_light": {
				"on_off": 0,
				"mode": "customize_preset",
				"hue": 0,
				"saturation": 0,
				"color_temp": 2700,
				"brightness": 0,
				"transition_period": 1000
			},
			"repeat": 0,
			"year": 2000,
			"month": 1,
			"day": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | The device-assigned identifier of the schedule rule to edit. Omitted in `add_rule`. |
| `name` | string | A user-specified name for the rule. |
| `enable` | enum | 0 = disable rule <br/> 1 = enable rule |
| `wday` | array | Weekdays on which the rule is to repeat. The first element corresponds to Sunday. |
| `stime_opt` | enum | -1 = rule does not begin <br/> 0 = rule begins at `smin` minutes past midnight <br/> 1 = rule begins at sunrise + `soffset` <br/> 2 = rule begins at sunset + `soffset` |
| `smin` | integer | The time of day at which the rule is to begin, in minutes past midnight. Omitted unless `stime_opt` is 0. |
| `soffset` | integer | The offset from sunrise/sunset at which the rule is to begin, in minutes. May be negative. Omitted if `stime_opt` is -1 or 0. |
| `sact` | enum | The action to take when the rule begins. <br/> -1 = no action <br/> 0 = turn switch off <br/> 1 = turn switch on <br/> 2 = *(bulbs only)* transition light state |
| `s_light` | object | *(bulbs only)* The light state to which to transition when the rule begins. See `transition_light_state`. |
| `etime_opt` | enum | -1 = rule does not end <br/> 0 = rule ends at `emin` minutes past midnight <br/> 1 = rule ends at sunrise + `eoffset` <br/> 2 = rule ends at sunset + `eoffset` |
| `emin` | integer | The time of day at which the rule is to end, in minutes past midnight. Omitted unless `etime_opt` is 0. |
| `eoffset` | integer | The offset from sunrise/sunset at which the rule is to end, in minutes. May be negative. Omitted if `etime_opt` is -1 or 0. |
| `eact` | enum | The action to take when the rule ends. <br/> -1 = no action <br/> 0 = turn switch off <br/> 1 = turn switch on <br/> 2 = *(bulbs only)* transition light state |
| `e_light` | object | *(bulbs only)* The light state to which to transition when the rule ends. See `transition_light_state`. |
| `repeat` | enum | 0 = rule does not repeat <br/> 1 = rule repeats |
| `year` | integer | The four-digit year in which the rule is to begin. Omitted if `repeat` is 1. |
| `month` | enum | The month of the year in which the rule is to begin. Omitted if `repeat` is 1. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `day` | integer | The day of the month on which the rule is to begin, 1-31. Omitted if `repeat` is 1. |

### Response

```json
{
	"schedule": {
		"add_rule": {
			"id": "…",
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | A device-assigned identifier for the new rule. Omitted in the response to `edit_rule`. |


## `delete_all_rules`

Deletes all schedule rules.

### Request

```json
{
	"schedule": {
		"delete_all_rules": {}
	}
}
```

### Response

```json
{
	"schedule": {
		"delete_all_rules": {
			"err_code": 0
		}
	}
}
```


## `delete_rule`

Deletes a schedule rule.

### Request

```json
{
	"schedule": {
		"delete_rule": {
			"id": "…"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | The device-assigned identifier of the schedule rule to delete. |

### Response

```json
{
	"schedule": {
		"delete_rule": {
			"err_code": 0
		}
	}
}
```


## `get_daystat`

Returns historical usage per day in a specified year and month.

### Request

```json
{
	"schedule": {
		"get_daystat": {
			"year": 2000,
			"month": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `year` | integer | The four-digit year from which to return historical usage. |
| `month` | enum | The month from which to return historical usage. <br/> 1 = January <br/> ⋮ <br/> 12 = December |

### Response

```json
{
	"schedule": {
		"get_daystat": {
			"day_list": [
				{
					"year": 2000,
					"month": 1,
					"day": 1,
					"time": 42
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `day_list` | array | A list of per-day historical usage records. |
| `year` | integer | The four-digit year of a usage record. |
| `month` | enum | The month of a usage record. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `day` | integer | The day of the month of a usage record, 1-31. |
| `time` | integer | The historical usage recorded on the indicated day, in minutes. |


## `get_monthstat`

Returns historical usage per month in a specified year.

### Request

```json
{
	"schedule": {
		"get_monthstat": {
			"year": 2000
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `year` | integer | The four-digit year from which to return historical usage. |

### Response

```json
{
	"schedule": {
		"get_monthstat": {
			"month_list": [
				{
					"year": 2000,
					"month": 1,
					"time": 4269
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `month_list` | array | A list of per-month historical usage records. |
| `year` | integer | The four-digit year of a usage record. |
| `month` | enum | The month of a usage record. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `time` | integer | The historical usage recorded in the indicated month, in minutes. |


## `get_rules`

Returns the configured schedule rules.

### Request

```json
{
	"schedule": {
		"get_rules": {}
	}
}
```

### Response

```json
{
	"schedule": {
		"get_rules": {
			"rule_list": [
				{
					"id": "…",
					"name": "…",
					"enable": 1,
					"wday": [1, 1, 1, 1, 1, 1, 1],
					"stime_opt": 1,
					"smin": 0,
					"soffset": 0,
					"sact": 1,
					"s_light": {
						"on_off": 1,
						"mode": "customize_preset",
						"hue": 0,
						"saturation": 0,
						"color_temp": 2700,
						"brightness": 25,
						"transition_period": 1000
					},
					"etime_opt": 2,
					"emin": 0,
					"eoffset": 0,
					"eact": 0,
					"e_light": {
						"on_off": 0,
						"mode": "customize_preset",
						"hue": 0,
						"saturation": 0,
						"color_temp": 2700,
						"brightness": 0,
						"transition_period": 1000
					},
					"repeat": 0,
					"year": 2000,
					"month": 1,
					"day": 1
				}
			],
			"version": 2,
			"enable": 1,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `rule_list` | array | A list of configured schedule rules. |
| `id` | string | The device-assigned identifier of a schedule rule. |
| `name` | string | The user-specified name of the rule. |
| `enable` | enum | 0 = rule is disabled <br/> 1 = rule is enabled |
| `wday` | array | Weekdays on which the rule repeats. The first element corresponds to Sunday. |
| `stime_opt` | enum | -1 = rule does not begin <br/> 0 = rule begins at `smin` minutes past midnight <br/> 1 = rule begins at sunrise + `soffset` <br/> 2 = rule begins at sunset + `soffset` |
| `smin` | integer | The time of day at which the rule begins, in minutes past midnight. |
| `soffset` | integer | The offset from sunrise/sunset at which the rule begins, in minutes. May be negative. Omitted if `stime_opt` is -1 or 0. |
| `sact` | enum | The action to take when the rule begins. <br/> -1 = no action <br/> 0 = turn switch off <br/> 1 = turn switch on <br/> 2 = *(bulbs only)* transition light state |
| `s_light` | object | *(bulbs only)* The light state to which to transition when the rule begins. See `transition_light_state`. |
| `etime_opt` | enum | -1 = rule does not end <br/> 0 = rule ends at `emin` minutes past midnight <br/> 1 = rule ends at sunrise + `eoffset` <br/> 2 = rule ends at sunset + `eoffset` |
| `emin` | integer | The time of day at which the rule ends, in minutes past midnight. |
| `eoffset` | integer | The offset from sunrise/sunset at which the rule ends, in minutes. May be negative. Omitted if `etime_opt` is -1 or 0. |
| `eact` | enum | The action to take when the rule ends. <br/> -1 = no action <br/> 0 = turn switch off <br/> 1 = turn switch on <br/> 2 = *(bulbs only)* transition light state |
| `e_light` | object | *(bulbs only)* The light state to which to transition when the rule ends. See `transition_light_state`. |
| `repeat` | enum | 0 = rule does not repeat <br/> 1 = rule repeats |
| `year` | integer | The four-digit year in which the rule begins. Omitted if `repeat` is 1. |
| `month` | enum | The month of the year in which the rule begins. Omitted if `repeat` is 1. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `day` | integer | The day of the month on which the rule begins, 1-31. Omitted if `repeat` is 1. |
| `version` | integer | ??? |
| `enable` | enum | 0 = schedule is disabled <br/> 1 = schedule is enabled |


## `set_overall_enable`

Enables or disables the schedule.

### Request

```json
{
	"schedule": {
		"set_overall_enable": {
			"enable": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `enable` | enum | 0 = disable the schedule <br/> 1 = enable the schedule |

### Response

```json
{
	"schedule": {
		"set_overall_enable": {
			"err_code": 0
		}
	}
}
```



# `smartlife.iot.LAS`

Ambient light sensor module.


## `get_config`

Returns the current configuration of the ambient light sensor.

### Request

```json
{
	"smartlife.iot.LAS": {
		"get_config": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.LAS": {
		"get_config": {
			"devs": [
				{
					"hw_id": 0,
					"enable": 1,
					"dark_index": 0,
					"min_adc": 0,
					"max_adc": 2450,
					"level_array": [
						{
							"name": "cloudy",
							"adc": 390,
							"value": 15
						}
					]
				}
			],
			"ver": "1.0",
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `devs` | array | A list of ambient light sensors. |
| `hw_id` | integer | The unique identifier of an ambient light sensor within the device. |
| `enable` | enum | 0 = ambient light sensor is disabled <br/> 1 = ambient light sensor is enabled |
| `dark_index` | integer | The zero-based index into `level_array` of the light level below which the sensor will report darkness. |
| `min_adc` | integer | The minimum possible reading from the light sensor's analog-to-digital converter. |
| `max_adc` | integer | The maximum possible reading from the light sensor's analog-to-digital converter. |
| `level_array` | array | A list of ambient light levels. |
| `name` | string | A loose description of an ambient light level. |
| `adc` | integer | The raw analog-to-digital converter value of an ambient light level. |
| `value` | integer | The normalized ambient light level as a percentage: (`adc` − `min_adc`) ÷ (`max_adc` − `min_adc`) × 100. |
| `ver` | string | ??? |


## `get_current_brt`

Returns the current brightness seen by the ambient light sensor.

### Request

```json
{
	"smartlife.iot.LAS": {
		"get_current_brt": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.LAS": {
		"get_current_brt": {
			"value": 0,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `value` | integer | The normalized ambient light level currently seen by the sensor. |


## `set_brt_level`

Modifies a predefined brightness level.

### Request

```json
{
	"smartlife.iot.LAS": {
		"set_brt_level": {
			"index": 5,
			"value": 42
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `index` | integer | A zero-based index into the `level_array` returned from `get_config`. |
| `value` | integer | The normalized ambient light level to associate with the specified index. |

### Response

```json
{
	"smartlife.iot.LAS": {
		"set_brt_level": {
			"err_code": 0
		}
	}
}
```


## `set_dark_index`

Sets the brightness level below which the ambient light sensor will report darkness.

### Request

```json
{
	"smartlife.iot.LAS": {
		"set_dark_index": {
			"dark_index": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `dark_index` | integer | The zero-based index into `level_array` returned from `get_config` of the light level below which the sensor is to report darkness. |

### Response

```json
{
	"smartlife.iot.LAS": {
		"set_dark_index": {
			"err_code": 0
		}
	}
}
```


## `set_enable`

Sets whether the ambient light sensor is enabled.

### Request

```json
{
	"smartlife.iot.LAS": {
		"set_enable": {
			"enable": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `enable` | enum | 0 = disable the ambient light sensor <br/> 1 = enable the ambient light sensor |

### Response

```json
{
	"smartlife.iot.LAS": {
		"set_enable": {
			"err_code": 0
		}
	}
}
```



# `smartlife.iot.lighting_effect`

Lighting effect module.



# `smartlife.iot.PIR`

Passive infrared motion sensor module.


## `get_config`

Returns the current configuration of the motion sensor.

### Request

```json
{
	"smartlife.iot.PIR": {
		"get_config": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.PIR": {
		"get_config": {
			"enable": 1,
			"version": "1.0",
			"trigger_index": 1,
			"cold_time": 60000,
			"min_adc": 0,
			"max_adc": 4095,
			"array": [80, 50, 20, 0],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `enable` | enum | 0 = motion sensor is disabled <br/> 1 = motion sensor is enabled |
| `version` | string | ??? |
| `trigger_index` | integer | The zero-based index into `array` of the current trigger sensitivity. |
| `cold_time` | integer | The duration of no motion events detected after which the sensor goes "cold," in milliseconds. |
| `min_adc` | integer | The minimum possible reading from the motion sensor's analog-to-digital converter. |
| `max_adx` | integer | The maximum possible reading from the motion sensor's analog-to-digital converter. |
| `array` | array | A list of motion sensor sensitivities, roughly in units of decimeters. |


## `set_cold_time`

Sets the duration of no motion events detected after which the motion sensor goes "cold."

**Note:** Smart Control rules will modify this setting.

### Request

```json
{
	"smartlife.iot.PIR": {
		"set_cold_time": {
			"cold_time": 60000
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `cold_time` | integer | The duration of no motion events detected after which the sensor is to go "cold," in milliseconds. |

### Response

```json
{
	"smartlife.iot.PIR": {
		"set_cold_time": {
			"err_code": 0
		}
	}
}
```


## `set_enable`

Sets whether the motion sensor is enabled.

### Request

```json
{
	"smartlife.iot.PIR": {
		"set_enable": {
			"enable": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `enable` | enum | 0 = disable the motion sensor <br/> 1 = enable the motion sensor |

### Response

```json
{
	"smartlife.iot.PIR": {
		"set_enable": {
			"err_code": 0
		}
	}
}
```


## `set_trigger_sens`

Sets the motion sensor trigger sensitivity.

### Request

```json
{
	"smartlife.iot.PIR": {
		"set_trigger_sens": {
			"index": 3,
			"value": 42
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `index` | integer | A zero-based index into the `array` returned by `get_config`. |
| `value` | integer | The motion sensor sensitivity to associate with the specified index, roughly in units of decimeters. |

### Response

```json
{
	"smartlife.iot.PIR": {
		"set_trigger_sens": {
			"err_code": 0
		}
	}
}
```



# `smartlife.iot.sensor_trigger`

Smart Control module.


## `add_weekday_routine` / `edit_weekday_routine`

Adds/edits a Smart Control rule.

### Request

```json
{
	"smartlife.iot.sensor_trigger": {
		"edit_weekday_routine": {
			"en": 1,
			"name": "",
			"id": "0",
			"wday": [1, 1, 1, 1, 1, 1, 1],
			"array": [
				{
					"sT": 0,
					"eT": 1440,
					"clr": 0,
					"onTT": 2,
					"offTT": 2,
					"offWT": 60
				}
			]
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `en` | enum | 0 = disable rule <br/> 1 = enable rule |
| `name` | string | A user-specified name for the rule. |
| `id` | string | The device-assigned identifier of the Smart Control rule to edit. Omitted in `add_weekday_routine`. |
| `wday` | array | ??? Maybe specifies on which weekdays the rule applies? |
| `array` | array | A list of rule segments. |
| `sT` | integer | Start time of the segment, in minutes past midnight. |
| `eT` | integer | End time of the segment, in minutes past midnight. |
| `clr` | enum | Color in which to display the segment in the UI. |
| `onTT` | enum | "On" trigger type. <br/> 0 = manual only <br/> 1 = motion detected <br/> 2 = dark and motion detected |
| `offTT` | enum | "Off" trigger type. <br/> 0 = manual only <br/> 2 = no motion detected for `offWT` seconds |
| `offWT` | integer | If `offTT` is 2, the time after which the switch will turn off if no motion is detected, in seconds. |

### Response

```json
{
	"smartlife.iot.sensor_trigger": {
		"add_weekday_routine": {
			"id": "0",
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | A device-assigned identifier for the new rule. Omitted in the response to `edit_weekday_routine`. |


## `delete_weekday_routine`

Deletes a Smart Control rule.

### Request

```json
{
	"smartlife.iot.sensor_trigger": {
		"delete_weekday_routine": {
			"id": "0"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `id` | string | The device-assigned identifier of the Smart Control rule to delete. |

### Response

```json
{
	"smartlife.iot.sensor_trigger": {
		"delete_weekday_routine": {
			"err_code": 0
		}
	}
}
```


## `get_default_manual_action`

Returns the configured default manual actions.

### Request

```json
{
	"smartlife.iot.sensor_trigger": {
		"get_default_manual_action": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.sensor_trigger": {
		"get_default_manual_action": {
			"onToT": 0,
			"onToM": 0,
			"onToS": 10,
			"offToT": 0,
			"offToM": 0,
			"offToS": 60,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `onToT` | integer | ??? |
| `onToM` | integer | ??? |
| `onToS` | integer | ??? |
| `offToT` | integer | ??? |
| `offToM` | integer | ??? |
| `offToS` | integer | The time after the switch is manually turned off until sensor triggers reactivate, in seconds. |


## `get_weekday_routine`

Returns the configured Smart Control rules.

### Request

```json
{
	"smartlife.iot.sensor_trigger": {
		"get_weekday_routine": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.sensor_trigger": {
		"get_weekday_routine": {
			"array": [
				{
					"en": 1,
					"name": "",
					"id": "0",
					"wday": [1, 1, 1, 1, 1, 1, 1],
					"array": [
						{
							"sT": 0,
							"eT": 1440,
							"clr": 0,
							"onTT": 2,
							"offTT": 2,
							"offWT": 60
						}
					]
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `array` | array | A list of configured Smart Control rules. |
| `en` | enum | 0 = rule is disabled <br/> 1 = rule is enabled |
| `name` | string | The user-specified name of the rule. |
| `id` | string | The device-assigned identifier of a Smart Control rule. |
| `wday` | array | ??? Maybe specifies on which weekdays the rule applies? |
| `array` | array | A list of rule segments. |
| `sT` | integer | Start time of the segment, in minutes past midnight. |
| `eT` | integer | End time of the segment, in minutes past midnight. |
| `clr` | enum | Color in which to display the segment in the UI. |
| `onTT` | enum | "On" trigger type. <br/> 0 = manual only <br/> 1 = motion detected <br/> 2 = dark and motion detected |
| `offTT` | enum | "Off" trigger type. <br/> 0 = manual only <br/> 2 = no motion detected for `offWT` seconds |
| `offWT` | integer | If `offTT` is 2, the time after which the switch will turn off if no motion is detected, in seconds. |


## `set_default_manual_action`

Configures the default manual actions.

### Request

```json
{
	"smartlife.iot.sensor_trigger": {
		"set_default_manual_action": {
			"offToS": 15
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `offToS` | integer | The time after the switch is manually turned off until sensor triggers reactivate, in seconds. |

### Response

```json
{
	"smartlife.iot.sensor_trigger": {
		"set_default_manual_action": {
			"err_code": 0
		}
	}
}
```



# `smartlife.iot.smartbulb.lightingservice`

Smart bulb module.


## `get_default_behavior`

Returns the default behavior of the bulb when switching on.

### Request

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_default_behavior": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_default_behavior": {
			"soft_on": {
				"mode": "last_status"
			},
			"hard_on": {
				"mode": "customize_preset",
				"index": 0,
				"hue": 0,
				"saturation": 0,
				"color_temp": 2700,
				"brightness": 50
			},
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `soft_on` | object | The default behavior when the bulb is switched on by command. |
| `hard_on` | object | The default behavior when the bulb receives power. |
| `mode` | string | `last_status` = restore most recently used light state <br/> `customize_preset` = load specified preset <br/> `circadian` = set automatic white color temperature |
| `index` | integer | The zero-based index of a customizable light state preset. Omitted if `mode` is `last_status`. |
| `hue` | integer | A color hue, in degrees. Only used if `color_temp` is 0. Omitted if `mode` is `last_status`. |
| `saturation` | integer | Color saturation, in percent. Only used if `color_temp` is 0. Omitted if `mode` is `last_status`. |
| `color_temp` | integer | White color temperature, in kelvin, or 0 to use `hue` and `saturation` instead. Omitted if `mode` is `last_status`. |
| `brightness` | integer | Brightness, in percent. Omitted if `mode` is `last_status`. |


## `get_light_details`

Returns physical bulb specifications.

### Request

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_light_details": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_light_details": {
			"lamp_beam_angle": 180,
			"min_voltage": 100,
			"max_voltage": 120,
			"wattage": 10,
			"incandescent_equivalent": 60,
			"max_lumens": 800,
			"color_rendering_index": 80,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `lamp_beam_angle` | integer | The lamp beam angle, in degrees. |
| `min_voltage` | integer | The minimum operating voltage, in volts. |
| `max_voltage` | integer | The maximum operating voltage, in volts. |
| `wattage` | integer | The maximum power consumption, in watts. |
| `incandescent_equivalent` | integer | The power consumption of an incandescent bulb of equivalent light output, in watts. |
| `max_lumens` | integer | The maximum light output, in lumens. |
| `color_rendering_index` | integer | Color rendering index, relative to incandescent light, in percent. |


## `get_light_state`

Returns the current light state.

### Request

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_light_state": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_light_state": {
			"dft_on_state": {
				"hue": 0,
				"saturation": 0,
				"color_temp": 2700,
				"brightness": 50,
				"mode": "normal"
			},
			"on_off": 1,
			"hue": 0,
			"saturation": 0,
			"color_temp": 2700,
			"brightness": 50,
			"mode": "normal",
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `dft_on_state` | object | The most recent "on" state. Omitted if `on_off` is 1. |
| `on_off` | enum | 0 = bulb is off <br/> 1 = bulb is on |
| `hue` | integer | A color hue, in degrees. Only used if `color_temp` is 0. Omitted if `on_off` is 0. |
| `saturation` | integer | Color saturation, in percent. Only used if `color_temp` is 0. Omitted if `on_off` is 0. |
| `color_temp` | integer | White color temperature, in kelvin, or 0 to use `hue` and `saturation` instead. Omitted if `on_off` is 0. |
| `brightness` | integer | Brightness, in percent. Omitted if `on_off` is 0. |
| `mode` | string | Omitted if `on_off` is 0. <br/> `normal` = fixed color <br/> `circadian` = automatic white color temperature |


## `get_preferred_state`

Returns the current configuration of customizable preset light states.

### Request

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_preferred_state": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"get_preferred_state": {
			"states": [
				{
					"index": 0,
					"hue": 0,
					"saturation": 0,
					"color_temp": 2700,
					"brightness": 50
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `states` | array | A list of customizable preset light states. |
| `index` | integer | The zero-based index of a preset. |
| `hue` | integer | A color hue, in degrees. Only used if `color_temp` is 0. |
| `saturation` | integer | Color saturation, in percent. Only used if `color_temp` is 0. |
| `color_temp` | integer | White color temperature, in kelvin, or 0 to use `hue` and `saturation` instead. |
| `brightness` | integer | Brightness, in percent. |


## `set_default_behavior`

Sets the default behavior of the bulb when switching on.

### Request

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"set_default_behavior": {
			"soft_on": {
				"mode": "last_status"
			},
			"hard_on": {
				"mode": "customize_preset",
				"index": 0
			}
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `soft_on` | object | The default behavior when the bulb is switched on by command. |
| `hard_on` | object | The default behavior when the bulb receives power. |
| `mode` | string | `last_status` = restore most recently used light state <br/> `customize_preset` = load specified preset <br/> `circadian` = set automatic white color temperature |
| `index` | integer | The zero-based index of a customizable light state preset. Omitted if `mode` is `last_status`. |

### Response

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"set_default_behavior": {
			"err_code": 0
		}
	}
}
```


## `set_preferred_state`

Change the configuration of a customizable preset light state.

### Request

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"set_preferred_state": {
			"index": 0,
			"hue": 0,
			"saturation": 0,
			"color_temp": 2700,
			"brightness": 50
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `index` | integer | The zero-based index of the preset to change. |
| `hue` | integer | A color hue, in degrees. Only used if `color_temp` is 0. |
| `saturation` | integer | Color saturation, in percent. Only used if `color_temp` is 0. |
| `color_temp` | integer | White color temperature, in kelvin, or 0 to use `hue` and `saturation` instead. |
| `brightness` | integer | Brightness, in percent. |

### Response

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"set_preferred_state": {
			"err_code": 0
		}
	}
}
```


## `transition_light_state`

Transition the bulb smoothly to a new light state.

### Request

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"transition_light_state": {
			"on_off": 1,
			"mode": "normal",
			"hue": 0,
			"saturation": 0,
			"color_temp": 2700,
			"brightness": 50,
			"transition_period": 1000,
			"ignore_default": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `on_off` | enum | 0 = switch bulb off <br/> 1 = switch bulb on |
| `mode` | string | `normal` = fixed color <br/> `circadian` = automatic white color temperature |
| `hue` | integer | A color hue, in degrees. Only used if `color_temp` is 0. |
| `saturation` | integer | Color saturation, in percent. Only used if `color_temp` is 0. |
| `color_temp` | integer | White color temperature, in kelvin, or 0 to use `hue` and `saturation` instead. |
| `brightness` | integer | Brightness, in percent. |
| `transition_period` | integer | Duration over which to apply transition, in milliseconds. |
| `ignore_default` | enum | When transitioning from "off" to "on" state: <br/> 0 = default `soft_on` setting overrides method parameters <br/> 1 = method parameters override default `soft_on` setting |

### Response

```json
{
	"smartlife.iot.smartbulb.lightingservice": {
		"transition_light_state": {
			"err_code": 0
		}
	}
}
```



# `smartlife.iot.smartpowerstrip.manage`

Smart power strip module.


## `get_relationship`

Returns the relationship of child devices to hardware slots.

### Request

```json
{
	"smartlife.iot.smartpowerstrip.manage": {
		"get_relationship": {}
	}
}
```

### Response

```json
{
	"smartlife.iot.smartpowerstrip.manage": {
		"get_relationship": {
			"data": [
				{
					"child_id": "…",
					"hw_slot": 0
				}
			],
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `data` | array | A list of child devices. |
| `child_id` | string | The unique identifier of a child device. |
| `hw_slot` | integer | The hardware slot number of a child device. |



# `system`

System module.


## `download_firmware`

Initiates a download of new firmware to the device.
If the download completes successfully, the device will automatically flash it.

### Request

```json
{
	"system": {
		"download_firmware": {
			"url": "http://download.tplinkcloud.com/firmware/…"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `url` | string | An HTTP URL from which to download the new firmware image. It does not need to be on TP-Link's servers and in fact may be hosted on the local network. |

### Response

```json
{
	"system": {
		"download_firmware": {
			"err_code": 0
		}
	}
}
```


## `get_download_state`

Returns the current state of a firmware download.

### Request

```json
{
	"system": {
		"get_download_state": {}
	}
}
```

### Response

```json
{
	"system": {
		"get_download_state": {
			"status": 0,
			"ratio": 0,
			"reboot_time": 5,
			"flash_time": 5,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `status` | enum | 0 = idle <br/> 1 = downloading <br/> 2 = flashing <br/> 6 = error |
| `ratio` | integer | Percentage completed, 0-100. |
| `reboot_time` | integer | ??? |
| `flash_time` | integer | ??? |


## `get_sysinfo`

Returns system information.

### Request

```json
{
	"system": {
		"get_sysinfo": {}
	}
}
```

### Response

```json
{
	"system": {
		"get_sysinfo": {
			"sw_ver": "…",
			"hw_ver": "…",
			"model": "…",
			"deviceId": "…",
			"oemId": "…",
			"hwId": "…",
			"rssi": -42,
			"latitude_i": 0,
			"longitude_i": 0,
			"alias": "…",
			"status": "new",
			"obd_src": "tplink",
			"mic_type": "…",
			"feature": "…",
			"mic_mac": "XXXXXXXXXXXX",
			"mac": "XX:XX:XX:XX:XX:XX",
			"dev_state": "normal",
			"is_factory": false,
			"disco_ver": "…",
			"ctrl_protocols": {
				"name": "…",
				"version": "…"
			},
			"updating": 0,
			"led_off": 0,
			"is_dimmable": 1,
			"is_color": 1,
			"is_variable_color_temp": 1,
			"LEF": 0,
			"light_state": {
				"dft_on_state": {
					"hue": 0,
					"saturation": 0,
					"color_temp": 2700,
					"brightness": 50,
					"mode": "normal"
				},
				"on_off": 1,
				"hue": 0,
				"saturation": 0,
				"color_temp": 2700,
				"brightness": 50,
				"mode": "normal"
			},
			"preferred_state": [
				{
					"index": 0,
					"hue": 0,
					"saturation": 0,
					"color_temp": 2700,
					"brightness": 50
				}
			],
			"relay_state": 0,
			"on_time": 0,
			"icon_hash": "",
			"description": "…",
			"dev_name": "…",
			"active_mode": "none",
			"next_action": {
				"type": -1
			},
			"children": [
				{
					"id": "…",
					"state": 0,
					"alias": "…",
					"on_time": 0,
					"next_action": {
						"type": -1
					}
				}
			],
			"child_num": 1,
			"ntc_state": 0,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `sw_ver` | string | The firmware version. |
| `hw_ver` | string | The hardware version. |
| `model` | string | The device model number. |
| `deviceId` | string | A hex string uniquely identifying the device instance. |
| `oemId` | string | A hex string, purpose unknown. |
| `hwId` | string | A hex string uniquely identifying the hardware configuration. |
| `rssi` | integer | The current Wi-Fi signal strength, in dBm. |
| `latitude_i` | integer | The latitude of the device, in ten-thousandths of a degree. |
| `longitude_i` | integer | The longitude of the device, in ten-thousandths of a degree. |
| `alias` | string | A user-specified label for the device. |
| `status` | string | ??? |
| `obd_src` | string | ??? |
| `mic_type` | string | `IOT.SMARTBULB` <br/> `IOT.SMARTPLUGSWITCH` |
| `feature` | string | A colon-separated list of features: <br/> `ENE` = energy meter <br/> `TIM` = countdown timer |
| `mic_mac` <br/> `mac` | string | The MAC address of the device. |
| `dev_state` | string | The device state. |
| `is_factory` | boolean | ??? |
| `disco_ver` | string | Version of the discovery protocol supported. |
| `ctrl_protocols` | object | Control protocols supported. |
| `updating` | enum | ??? |
| `led_off` | enum | 0 = LED functions normally <br/> 1 = LED function is suppressed |
| `icon_hash` | string | The hash of the icon to display in the UI. |
| `description` <br/> `dev_name` | string | An English description of the device. |
| `active_mode` | string | ??? |
| `next_action` | object | ??? |

If `mic_type` is `IOT.SMARTBULB`:

| Parameter | Type | Description |
| --- | --- | --- |
| `is_dimmable` | enum | 0 = bulb is not dimmable <br/> 1 = bulb is dimmable |
| `is_color` | enum | 0 = bulb is white only <br/> 1 = bulb is multi-color |
| `is_variable_color_temp` | enum | 0 = bulb has fixed white color temperature <br/> 1 = bulb has variable white color temperature |
| `LEF` | enum | ??? Maybe bulb supports Lighting Effect Feature? |
| `light_state` | object | See `smartlife.iot.smartbulb.lightingservice/get_light_state`. |
| `preferred_state` | array | See `smartlife.iot.smartbulb.lightingservice/get_preferred_state`. |

If `mic_type` is `IOT.SMARTPLUGSWITCH`:

| Parameter | Type | Description |
| --- | --- | --- |
| `relay_state` | enum | *(plugs and switches only)* <br/> 0 = relay is open (off) <br/> 1 = relay is closed (on) |
| `on_time` | integer | Elapsed time since the relay was closed, in seconds. |
| `children` | array | *(plug strips only)* A list of child devices. |
| `id` | string | A unique identifier for the child device. |
| `state` | enum | 0 = child device is switched off <br/> 1 = child device is switched on |
| `child_num` | integer | *(plug strips only)* The number of child devices. |
| `ntc_state` | enum | *(plugs and plug strips only)* The current state of the negative temperature coefficient sensor. <br/> 0 = normal |


## `reboot`

Reboots the device.

### Request

```json
{
	"system": {
		"reboot": {
			"delay": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `delay` | integer | The time to delay before rebooting the device, in seconds. If 0, the device may reboot before it can send a response. |

### Response

```json
{
	"system": {
		"reboot": {
			"err_code": 0
		}
	}
}
```


## `reset`

Resets the device configuration to factory defaults and reboots the device.

### Request

```json
{
	"system": {
		"reset": {
			"delay": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `delay` | integer | The time to delay before rebooting the device, in seconds. If 0, the device may reboot before it can send a response. |

### Response

```json
{
	"system": {
		"reset": {
			"err_code": 0
		}
	}
}
```


## `set_dev_alias`

Changes the device alias, which is a user-specified label for the device.

### Request

```json
{
	"context": {
		"child_ids": ["..."]
	},
	"system": {
		"set_dev_alias": {
			"alias": "…"
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `child_ids` | array | *(plug strips only)* A list of the identifiers of the child devices whose alias is to be changed. |
| `alias` | string | A user-specified label for the device. |

### Response

```json
{
	"system": {
		"set_dev_alias": {
			"err_code": 0
		}
	}
}
```


## `set_dev_location`

Sets the geographical location of the device.

### Request

```json
{
	"system": {
		"set_dev_location": {
			"latitude_i": 0,
			"longitude_i": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `latitude_i` | integer | The latitude of the device, in ten-thousandths of a degree. |
| `longitude_i` | integer | The longitude of the device, in ten-thousandths of a degree. |

### Response

```json
{
	"system": {
		"set_dev_location": {
			"err_code": 0
		}
	}
}
```


## `set_mac_addr`

Changes the MAC address of the device.

### Request

```json
{
	"system": {
		"set_mac_addr": {
			"mac": "00:00:5E:00:53:00"
		}
	}
}
```

### Response

```json
{
	"system": {
		"set_mac_addr": {
			"err_code": 0
		}
	}
}
```


## `set_led_off`

Sets whether the function of the LED indicator on the device is suppressed.

### Request

```json
{
	"system": {
		"set_led_off": {
			"off": 1
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `off` | enum | 0 = configure LED to function normally <br/> 1 = suppress LED function |

### Response

```json
{
	"system": {
		"set_led_off": {
			"err_code": 0
		}
	}
}
```


## `set_relay_state`

*(plugs, plug strips, and switches only)*

Sets the state of the relay, controlling whether the load is connected to the line.

### Request

```json
{
	"context": {
		"child_ids": ["..."]
	},
	"system": {
		"set_relay_state": {
			"state": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `child_ids` | array | *(plug strips only)* A list of the identifiers of the child devices whose relay state is to be set. |
| `state` | enum | 0 = set relay open (off) <br/> 1 = set relay closed (on) |

### Response

```json
{
	"system": {
		"set_relay_state": {
			"err_code": 0
		}
	}
}
```



# `time`

Real-time clock module.

**Note:** This module is named `smartlife.iot.common.timesetting` in some devices.


## `get_time`

Returns the current time according to the device's real-time clock.

### Request

```json
{
	"time": {
		"get_time": {}
	}
}
```

### Response

```json
{
	"time": {
		"get_time": {
			"year": 2000,
			"month": 1,
			"mday": 1,
			"hour": 0,
			"min": 0,
			"sec": 0,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `year` | integer | The current four-digit year. |
| `month` | enum | The current month of the year. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `mday` | integer | The current day of the month, 1-31. |
| `hour` | integer | The current hour of the day, 0-23. |
| `min` | integer | The current minute of the hour, 0-59. |
| `sec` | integer | The current second of the minute, 0-59. |


## `get_timezone`

Returns the configured time zone of the device.

### Request

```json
{
	"time": {
		"get_timezone": {}
	}
}
```

### Response

```json
{
	"time": {
		"get_timezone": {
			"index": 38,
			"err_code": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `index` | enum | The time zone index. See `set_timezone` for the possible values. |


## `set_time`

**Note:** Some devices always return `{"err_code":-3,"err_msg":"invalid argument"}` from this method.
Set these device's clocks using the `set_timezone` method.

### Request

```json
{
	"time": {
		"set_time": {
			"year": 2000,
			"month": 1,
			"mday": 1,
			"hour": 0,
			"min": 0,
			"sec": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `year` | integer | The current four-digit year. |
| `month` | enum | The current month of the year. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `mday` | integer | The current day of the month, 1-31. |
| `hour` | integer | The current hour of the day, 0-23. |
| `min` | integer | The current minute of the hour, 0-59. |
| `sec` | integer | The current second of the minute, 0-59. |

### Response

```json
{
	"time": {
		"set_time": {
			"err_code": 0
		}
	}
}
```


## `set_timezone`

Sets the device's time zone and real-time clock.

**Note:** Kasa devices automatically set their real-time clocks from the Internet, but if you have disallowed them Internet access, then you will need to set their clocks manually. There is no battery backing the clock, so the clock must be set whenever power has been interrupted.

### Request

```json
{
	"time": {
		"set_timezone": {
			"index": 38,
			"year": 2000,
			"month": 1,
			"mday": 1,
			"hour": 0,
			"min": 0,
			"sec": 0
		}
	}
}
```

| Parameter | Type | Description |
| --- | --- | --- |
| `index` | enum | The time zone index. <br/> 0 = UTC-12:00 – International Date Line West <br/> 1 = UTC-11:00 – Coordinated Universal Time <br/> 2 = UTC-10:00 – Hawaii <br/> 3 = UTC-09:00 – Alaska <br/> 4 = UTC-08:00 – Baji California <br/> 5 = UTC-08:00 – Pacific Standard Time <br/> 6 = UTC-08:00 – Pacific Daylight Time <br/> 7 = UTC-07:00 – Arizona <br/> 8 = UTC-07:00 – Chihuahua, La Paz, Mazatlan <br/> 9 = UTC-07:00 – Mountain Standard Time <br/> 10 = UTC-07:00 – Mountain Daylight Time <br/> 11 = UTC-06:00 – Central America <br/> 12 = UTC-06:00 – Central Standard Time <br/> 13 = UTC-06:00 – Central Daylight Time <br/> 14 = UTC-06:00 – Guadalajara, Mexico City <br/> 15 = UTC-06:00 – Saskatchewan <br/> 16 = UTC-05:00 – Bogota, Lima, Quito <br/> 17 = UTC-05:00 – Eastern Standard Time <br/> 18 = UTC-05:00 – Eastern Daylight Time <br/> 19 = UTC-05:00 – Indiana (East) <br/> 20 = UTC-04:30 – Caracas <br/> 21 = UTC-04:00 – Asunicion <br/> 22 = UTC-04:00 – Atlantic Standard Time <br/> 23 = UTC-04:00 – Atlantic Daylight Time <br/> 24 = UTC-04:00 – Cuiaba <br/> 25 = UTC-04:00 – Georgetown <br/> 26 = UTC-04:00 – Santiago <br/> 27 = UTC-03:30 – Newfoundland <br/> 28 = UTC-03:00 – Brasilia <br/> 29 = UTC-03:00 – Buenos Aires <br/> 30 = UTC-03:00 – Cayenne, Fortaleza <br/> 31 = UTC-03:00 – Greenland <br/> 32 = UTC-03:00 – Montevideo <br/> 33 = UTC-03:00 – Salvador <br/> 34 = UTC-02:00 – Coordindated Universal Time <br/> 35 = UTC-01:00 – Azores <br/> 36 = UTC-01:00 – Cabo Verde Is. <br/> 37 = UTC – Casablanca <br/> 38 = UTC – Coordindated Universal Time <br/> 39 = UTC – Dublin, Edinburgh, Lisbon, London <br/> 40 = UTC – Monrovia, Reykjavik <br/> 41 = UTC+01:00 – Amsterdam, Berlin, Bern <br/> 42 = UTC+01:00 – Belgrade, Bratislava <br/> 43 = UTC+01:00 – Brussels, Copenhagen <br/> 44 = UTC+01:00 – Sarajevo, Skopje, Warsaw <br/> 45 = UTC+01:00 – West Central Africa <br/> 46 = UTC+01:00 – Windkoek <br/> 47 = UTC+02:00 – Amman <br/> 48 = UTC+02:00 – Athens, Bucharest <br/> 49 = UTC+02:00 – Beirut <br/> 50 = UTC+02:00 – Cairo <br/> 51 = UTC+02:00 – Damascus <br/> 52 = UTC+02:00 – E. Europe <br/> 53 = UTC+02:00 – Harare, Pretoria <br/> 54 = UTC+02:00 – Helsinki, Kyiv, Riga, Sofia <br/> 55 = UTC+02:00 – Istanbul <br/> 56 = UTC+02:00 – Jerusalem <br/> 57 = UTC+02:00 – Kalinigrad (RTZ 1) <br/> 58 = UTC+02:00 – Tripoli <br/> 59 = UTC+02:00 – Baghdad <br/> 60 = UTC+03:00 – Kuwait, Riyadh <br/> 61 = UTC+03:00 – Minsk <br/> 62 = UTC+03:00 – Moscow, St. Petersburg <br/> 63 = UTC+03:00 – Nairobi <br/> 64 = UTC+03:30 – Tehran <br/> 65 = UTC+04:00 – Abu Dhabi, Muscat <br/> 66 = UTC+04:00 – Baku <br/> 67 = UTC+04:00 – Izhevsk, Samara (RTZ 3) <br/> 68 = UTC+04:00 – Port Louis <br/> 69 = UTC+04:00 – Tbilisi <br/> 70 = UTC+04:00 – Yerevan <br/> 71 = UTC+04:30 – Kabal <br/> 72 = UTC+05:00 – Ashgabat, Tashkent <br/> 73 = UTC+05:00 – Ekaterinburg (RTZ 4) <br/> 74 = UTC+05:00 – Islamabad, Karachi <br/> 75 = UTC+05:30 – Chennai, Kolkata, Mumbai <br/> 76 = UTC+05:30 – Sri Jayawardenepura <br/> 77 = UTC+05:45 – Kathmandu <br/> 78 = UTC+06:00 – Astana <br/> 79 = UTC+06:00 – Dhaka <br/> 80 = UTC+06:00 – Novosibirsk (RTZ 5) <br/> 81 = UTC+06:30 – Yangon (Rangoon) <br/> 82 = UTC+07:00 – Bankok, Hanoi, Jakarta <br/> 83 = UTC+07:00 – Kransnoyarsk (RTZ 6) <br/> 84 = UTC+08:00 – Beijing, Chongqing, Hong Kong <br/> 85 = UTC+08:00 – Irkutsk (RTZ 7) <br/> 86 = UTC+08:00 – Kuala Lumpur, Singapore <br/> 87 = UTC+08:00 – Perth <br/> 88 = UTC+08:00 – Taipei <br/> 89 = UTC+08:00 – Ulaanbaatar <br/> 90 = UTC+09:00 – Osaka, Sapporo, Tokyo <br/> 91 = UTC+09:00 – Seoul <br/> 92 = UTC+09:00 – Yakutsk (RTZ 8) <br/> 93 = UTC+09:30 – Adelaide <br/> 94 = UTC+09:30 – Darwin <br/> 95 = UTC+10:00 – Brisbane <br/> 96 = UTC+10:00 – Canberra, Melbourne, Sydney <br/> 97 = UTC+10:00 – Guam, Port Moresby <br/> 98 = UTC+10:00 – Hobart <br/> 99 = UTC+10:00 – Magadan <br/> 100 = UTC+10:00 – Vladivostok, Magadan (RTZ 9) <br/> 101 = UTC+11:00 – Chokurdakh (RTZ 10) <br/> 102 = UTC+11:00 – Solomon Is., New Caledonia <br/> 103 = UTC+12:00 – Anadyr, Petropavlovsk <br/> 104 = UTC+12:00 – Auckland, Wellington <br/> 105 = UTC+12:00 – Corrdinated Universal Time <br/> 106 = UTC+12:00 – Fiji <br/> 107 = UTC+13:00 – Nukuʻalofa <br/> 108 = UTC+13:00 – Samoa <br/> 109 = UTC+14:00 – Kiritimati Island |
| `year` | integer | The current four-digit year. |
| `month` | enum | The current month of the year. <br/> 1 = January <br/> ⋮ <br/> 12 = December |
| `mday` | integer | The current day of the month, 1-31. |
| `hour` | integer | The current hour of the day, 0-23. |
| `min` | integer | The current minute of the hour, 0-59. |
| `sec` | integer | The current second of the minute, 0-59. |

Thanks to [Brian Dorey](https://www.briandorey.com/post/tp-link-lb130-smart-wi-fi-led-bulb-python-control) for the list of timezone indices.

### Response

```json
{
	"time": {
		"set_timezone": {
			"err_code": 0
		}
	}
}
```
