/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_joystick.h"

#include <string.h>

#define TYPE_GET_POSITION 1
#define TYPE_IS_PRESSED 2
#define TYPE_GET_ANALOG_VALUE 3
#define TYPE_CALIBRATE 4
#define TYPE_SET_POSITION_CALLBACK_PERIOD 5
#define TYPE_GET_POSITION_CALLBACK_PERIOD 6
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 7
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 8
#define TYPE_SET_POSITION_CALLBACK_THRESHOLD 9
#define TYPE_GET_POSITION_CALLBACK_THRESHOLD 10
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 11
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 12
#define TYPE_SET_DEBOUNCE_PERIOD 13
#define TYPE_GET_DEBOUNCE_PERIOD 14
#define TYPE_POSITION 15
#define TYPE_ANALOG_VALUE 16
#define TYPE_POSITION_REACHED 17
#define TYPE_ANALOG_VALUE_REACHED 18
#define TYPE_PRESSED 19
#define TYPE_RELEASED 20

typedef void (*position_func_t)(int16_t, int16_t);
typedef void (*analog_value_func_t)(uint16_t, uint16_t);
typedef void (*position_reached_func_t)(int16_t, int16_t);
typedef void (*analog_value_reached_func_t)(uint16_t, uint16_t);
typedef void (*pressed_func_t)();
typedef void (*released_func_t)();

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPosition;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t x;
	int16_t y;
} PACKED GetPositionReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED IsPressed;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool pressed;
} PACKED IsPressedReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValue;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t x;
	uint16_t y;
} PACKED GetAnalogValueReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED Calibrate;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetPositionCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPositionCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetPositionCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetAnalogValueCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min_x;
	int16_t max_x;
	int16_t min_y;
	int16_t max_y;
} PACKED SetPositionCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetPositionCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min_x;
	int16_t max_x;
	int16_t min_y;
	int16_t max_y;
} PACKED GetPositionCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min_x;
	uint16_t max_x;
	uint16_t min_y;
	uint16_t max_y;
} PACKED SetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min_x;
	uint16_t max_x;
	uint16_t min_y;
	uint16_t max_y;
} PACKED GetAnalogValueCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED SetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED GetDebouncePeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t x;
	int16_t y;
} PACKED PositionCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t x;
	uint16_t y;
} PACKED AnalogValueCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t x;
	int16_t y;
} PACKED PositionReachedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t x;
	uint16_t y;
} PACKED AnalogValueReachedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED PressedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED ReleasedCallback;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int joystick_get_position(Joystick *joystick, int16_t *ret_x, int16_t *ret_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_GET_POSITION;
	joystick->answer.length = sizeof(GetPositionReturn);
	GetPosition gp;
	gp.stack_id = joystick->stack_id;
	gp.type = TYPE_GET_POSITION;
	gp.length = sizeof(GetPosition);

	ipcon_device_write(joystick, (char *)&gp, sizeof(GetPosition));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetPositionReturn *gpr = (GetPositionReturn *)joystick->answer.buffer;
	*ret_x = gpr->x;
	*ret_y = gpr->y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_is_pressed(Joystick *joystick, bool *ret_pressed) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_IS_PRESSED;
	joystick->answer.length = sizeof(IsPressedReturn);
	IsPressed ip;
	ip.stack_id = joystick->stack_id;
	ip.type = TYPE_IS_PRESSED;
	ip.length = sizeof(IsPressed);

	ipcon_device_write(joystick, (char *)&ip, sizeof(IsPressed));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	IsPressedReturn *ipr = (IsPressedReturn *)joystick->answer.buffer;
	*ret_pressed = ipr->pressed;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_analog_value(Joystick *joystick, uint16_t *ret_x, uint16_t *ret_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_GET_ANALOG_VALUE;
	joystick->answer.length = sizeof(GetAnalogValueReturn);
	GetAnalogValue gav;
	gav.stack_id = joystick->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue);

	ipcon_device_write(joystick, (char *)&gav, sizeof(GetAnalogValue));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn *gavr = (GetAnalogValueReturn *)joystick->answer.buffer;
	*ret_x = gavr->x;
	*ret_y = gavr->y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_calibrate(Joystick *joystick) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	Calibrate c;
	c.stack_id = joystick->stack_id;
	c.type = TYPE_CALIBRATE;
	c.length = sizeof(Calibrate);

	ipcon_device_write(joystick, (char *)&c, sizeof(Calibrate));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_position_callback_period(Joystick *joystick, uint32_t period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetPositionCallbackPeriod spcp;
	spcp.stack_id = joystick->stack_id;
	spcp.type = TYPE_SET_POSITION_CALLBACK_PERIOD;
	spcp.length = sizeof(SetPositionCallbackPeriod);
	spcp.period = period;

	ipcon_device_write(joystick, (char *)&spcp, sizeof(SetPositionCallbackPeriod));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_position_callback_period(Joystick *joystick, uint32_t *ret_period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_GET_POSITION_CALLBACK_PERIOD;
	joystick->answer.length = sizeof(GetPositionCallbackPeriodReturn);
	GetPositionCallbackPeriod gpcp;
	gpcp.stack_id = joystick->stack_id;
	gpcp.type = TYPE_GET_POSITION_CALLBACK_PERIOD;
	gpcp.length = sizeof(GetPositionCallbackPeriod);

	ipcon_device_write(joystick, (char *)&gpcp, sizeof(GetPositionCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetPositionCallbackPeriodReturn *gpcpr = (GetPositionCallbackPeriodReturn *)joystick->answer.buffer;
	*ret_period = gpcpr->period;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_analog_value_callback_period(Joystick *joystick, uint32_t period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetAnalogValueCallbackPeriod savcp;
	savcp.stack_id = joystick->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod);
	savcp.period = period;

	ipcon_device_write(joystick, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_analog_value_callback_period(Joystick *joystick, uint32_t *ret_period) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	joystick->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn);
	GetAnalogValueCallbackPeriod gavcp;
	gavcp.stack_id = joystick->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod);

	ipcon_device_write(joystick, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn *gavcpr = (GetAnalogValueCallbackPeriodReturn *)joystick->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_position_callback_threshold(Joystick *joystick, char option, int16_t min_x, int16_t max_x, int16_t min_y, int16_t max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetPositionCallbackThreshold spct;
	spct.stack_id = joystick->stack_id;
	spct.type = TYPE_SET_POSITION_CALLBACK_THRESHOLD;
	spct.length = sizeof(SetPositionCallbackThreshold);
	spct.option = option;
	spct.min_x = min_x;
	spct.max_x = max_x;
	spct.min_y = min_y;
	spct.max_y = max_y;

	ipcon_device_write(joystick, (char *)&spct, sizeof(SetPositionCallbackThreshold));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_position_callback_threshold(Joystick *joystick, char *ret_option, int16_t *ret_min_x, int16_t *ret_max_x, int16_t *ret_min_y, int16_t *ret_max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_GET_POSITION_CALLBACK_THRESHOLD;
	joystick->answer.length = sizeof(GetPositionCallbackThresholdReturn);
	GetPositionCallbackThreshold gpct;
	gpct.stack_id = joystick->stack_id;
	gpct.type = TYPE_GET_POSITION_CALLBACK_THRESHOLD;
	gpct.length = sizeof(GetPositionCallbackThreshold);

	ipcon_device_write(joystick, (char *)&gpct, sizeof(GetPositionCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetPositionCallbackThresholdReturn *gpctr = (GetPositionCallbackThresholdReturn *)joystick->answer.buffer;
	*ret_option = gpctr->option;
	*ret_min_x = gpctr->min_x;
	*ret_max_x = gpctr->max_x;
	*ret_min_y = gpctr->min_y;
	*ret_max_y = gpctr->max_y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_analog_value_callback_threshold(Joystick *joystick, char option, uint16_t min_x, uint16_t max_x, uint16_t min_y, uint16_t max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetAnalogValueCallbackThreshold savct;
	savct.stack_id = joystick->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold);
	savct.option = option;
	savct.min_x = min_x;
	savct.max_x = max_x;
	savct.min_y = min_y;
	savct.max_y = max_y;

	ipcon_device_write(joystick, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_analog_value_callback_threshold(Joystick *joystick, char *ret_option, uint16_t *ret_min_x, uint16_t *ret_max_x, uint16_t *ret_min_y, uint16_t *ret_max_y) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	joystick->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn);
	GetAnalogValueCallbackThreshold gavct;
	gavct.stack_id = joystick->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold);

	ipcon_device_write(joystick, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn *gavctr = (GetAnalogValueCallbackThresholdReturn *)joystick->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min_x = gavctr->min_x;
	*ret_max_x = gavctr->max_x;
	*ret_min_y = gavctr->min_y;
	*ret_max_y = gavctr->max_y;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_set_debounce_period(Joystick *joystick, uint32_t debounce) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	SetDebouncePeriod sdp;
	sdp.stack_id = joystick->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod);
	sdp.debounce = debounce;

	ipcon_device_write(joystick, (char *)&sdp, sizeof(SetDebouncePeriod));

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_get_debounce_period(Joystick *joystick, uint32_t *ret_debounce) {
	if(joystick->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(joystick);

	joystick->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	joystick->answer.length = sizeof(GetDebouncePeriodReturn);
	GetDebouncePeriod gdp;
	gdp.stack_id = joystick->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod);

	ipcon_device_write(joystick, (char *)&gdp, sizeof(GetDebouncePeriod));

	if(ipcon_answer_sem_wait_timeout(joystick) != 0) {
		ipcon_sem_post_write(joystick);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn *gdpr = (GetDebouncePeriodReturn *)joystick->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(joystick);

	return E_OK;
}

int joystick_callback_position(Joystick *joystick, const unsigned char *buffer) {
	PositionCallback *pc = (PositionCallback *)buffer;
	((position_func_t)joystick->callbacks[pc->type])(pc->x, pc->y);
	return sizeof(PositionCallback);
}

int joystick_callback_analog_value(Joystick *joystick, const unsigned char *buffer) {
	AnalogValueCallback *avc = (AnalogValueCallback *)buffer;
	((analog_value_func_t)joystick->callbacks[avc->type])(avc->x, avc->y);
	return sizeof(AnalogValueCallback);
}

int joystick_callback_position_reached(Joystick *joystick, const unsigned char *buffer) {
	PositionReachedCallback *prc = (PositionReachedCallback *)buffer;
	((position_reached_func_t)joystick->callbacks[prc->type])(prc->x, prc->y);
	return sizeof(PositionReachedCallback);
}

int joystick_callback_analog_value_reached(Joystick *joystick, const unsigned char *buffer) {
	AnalogValueReachedCallback *avrc = (AnalogValueReachedCallback *)buffer;
	((analog_value_reached_func_t)joystick->callbacks[avrc->type])(avrc->x, avrc->y);
	return sizeof(AnalogValueReachedCallback);
}

int joystick_callback_pressed(Joystick *joystick, const unsigned char *buffer) {
	PressedCallback *pc = (PressedCallback *)buffer;
	((pressed_func_t)joystick->callbacks[pc->type])();
	return sizeof(PressedCallback);
}

int joystick_callback_released(Joystick *joystick, const unsigned char *buffer) {
	ReleasedCallback *rc = (ReleasedCallback *)buffer;
	((released_func_t)joystick->callbacks[rc->type])();
	return sizeof(ReleasedCallback);
}

void joystick_register_callback(Joystick *joystick, uint8_t cb, void *func) {
    joystick->callbacks[cb] = func;
}

void joystick_create(Joystick *joystick, const char *uid) {
	ipcon_device_create(joystick, uid);

	joystick->device_callbacks[TYPE_POSITION] = joystick_callback_position;
	joystick->device_callbacks[TYPE_ANALOG_VALUE] = joystick_callback_analog_value;
	joystick->device_callbacks[TYPE_POSITION_REACHED] = joystick_callback_position_reached;
	joystick->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = joystick_callback_analog_value_reached;
	joystick->device_callbacks[TYPE_PRESSED] = joystick_callback_pressed;
	joystick->device_callbacks[TYPE_RELEASED] = joystick_callback_released;
}
