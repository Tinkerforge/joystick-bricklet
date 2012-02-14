/* joystick-bricklet
 * Copyright (C) 2010-2011 Olaf Lüke <olaf@tinkerforge.com>
 *
 * joystick.c: Implementation of Joystick Bricklet messages
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "joystick.h"

#include "brickletlib/bricklet_entry.h"
#include "bricklib/bricklet/bricklet_communication.h"
#include "bricklib/drivers/adc/adc.h"
#include "bricklib/utility/util_definitions.h"
#include "bricklib/bricklet/bricklet_config.h"
#include "bricklib/utility/init.h"
#include "bricklib/com/i2c/i2c_eeprom/i2c_eeprom_common.h"
#include "config.h"

#define MAX_ADC_VALUE ((1  << 12) - 1)
#define MAX_JOYSTICK_POSITION 200
#define AVERAGE 10

#define SIMPLE_UNIT_POSITION 0
#define SIMPLE_UNIT_ANALOG_VALUE 1
#define EEPROM_POSITION (I2C_EEPROM_INTERNAL_ADDRESS_PLUGIN + \
                         BRICKLET_PLUGIN_MAX_SIZE)

const SimpleMessageProperty smp[] = {
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_VALUE, SIMPLE_DIRECTION_GET}, // TYPE_GET_POSITION
	{0, 0, 0}, // TYPE_IS_PRESSED
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_VALUE, SIMPLE_DIRECTION_GET}, // TYPE_GET_ANALOG_VALUE
	{0, 0, 0}, // TYPE_CALIBRATE
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_SET}, // TYPE_SET_POSITION_CALLBACK_PERIOD
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_GET}, // TYPE_GET_POSITION_CALLBACK_PERIOD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_SET}, // TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_PERIOD, SIMPLE_DIRECTION_GET}, // TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_SET}, // TYPE_SET_POSITION_CALLBACK_THRESHOLD
	{SIMPLE_UNIT_POSITION, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_GET}, // TYPE_GET_POSITION_CALLBACK_THRESHOLD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_SET}, // TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD
	{SIMPLE_UNIT_ANALOG_VALUE, SIMPLE_TRANSFER_THRESHOLD, SIMPLE_DIRECTION_GET}, // TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD
	{0, SIMPLE_TRANSFER_DEBOUNCE, SIMPLE_DIRECTION_SET}, // TYPE_SET_DEBOUNCE_PERIOD
	{0, SIMPLE_TRANSFER_DEBOUNCE, SIMPLE_DIRECTION_GET}, // TYPE_GET_DEBOUNCE_PERIOD
};

const SimpleUnitProperty sup[] = {
	{position_from_analog_value_x, position_from_analog_value_y, SIMPLE_SIGNEDNESS_INT, TYPE_POSITION, TYPE_POSITION_REACHED, SIMPLE_UNIT_ANALOG_VALUE}, // position
	{analog_value_from_mc_x, analog_value_from_mc_y, SIMPLE_SIGNEDNESS_UINT, TYPE_ANALOG_VALUE, TYPE_ANALOG_VALUE_REACHED, SIMPLE_UNIT_ANALOG_VALUE}, // analog value
};

void invocation(uint8_t com, uint8_t *data) {
	switch(((SimpleStandardMessage*)data)->type) {
		case TYPE_IS_PRESSED:
			is_pressed(com, (StandardMessage*)data);
			return;
		case TYPE_CALIBRATE:
			calibrate();
			return;
	}

	simple_invocation(com, data);
}

void is_pressed(uint8_t com, StandardMessage *sm) {
	BoolMessage bm = {
		sm->stack_id,
		sm->type,
		sizeof(BoolMessage),
		PIN_SWITCH.pio->PIO_PDSR & PIN_SWITCH.mask
	};

	BA->send_blocking_with_timeout(&bm,
	                               sizeof(BoolMessage),
	                               com);
}

void calibrate(void) {
	uint32_t value_x = 0;
	uint32_t value_y = 0;

	PIN_ANALOG_X.pio->PIO_CODR = PIN_ANALOG_X.mask;
	PIN_ANALOG_Y.pio->PIO_SODR = PIN_ANALOG_Y.mask;

	SLEEP_MS(1);
	for(uint8_t i = 0; i < 100; i++) {
		value_x += BA->adc_channel_get_data(BS->adc_channel);
		SLEEP_NS(100);
	}

	PIN_ANALOG_Y.pio->PIO_CODR = PIN_ANALOG_Y.mask;
	PIN_ANALOG_X.pio->PIO_SODR = PIN_ANALOG_X.mask;

	SLEEP_MS(1);
	for(uint8_t i = 0; i < 100; i++) {
		value_y += BA->adc_channel_get_data(BS->adc_channel);
		SLEEP_NS(100);
	}

	BC->offset_x = ADC_MAX_VALUE/2 - value_x/100;
	BC->offset_y = ADC_MAX_VALUE/2 - value_y/100;

	uint16_t data = BC->offset_x | (BC->offset_y << 8);

    BA->bricklet_select(BS->port - 'a');
    BA->i2c_eeprom_master_write(BA->twid->pTwi,
                                EEPROM_POSITION,
                                (char *)&data,
                                2);
    BA->bricklet_deselect(BS->port - 'a');
}

int32_t analog_value_from_mc_x(int32_t value) {
	int32_t ret_value;
	if(BC->current_joystick_direction == JOYSTICK_DIRECTION_X) {
		ret_value = BA->adc_channel_get_data(BS->adc_channel);
	} else {
		ret_value = BC->last_value1[0];
	}

	PIN_ANALOG_Y.pio->PIO_CODR = PIN_ANALOG_Y.mask;
	PIN_ANALOG_X.pio->PIO_SODR = PIN_ANALOG_X.mask;
	BC->current_joystick_direction = JOYSTICK_DIRECTION_Y;

	return ret_value;
}

int32_t analog_value_from_mc_y(int32_t value) {
	int32_t ret_value;
	if(BC->current_joystick_direction == JOYSTICK_DIRECTION_Y) {
		ret_value = BA->adc_channel_get_data(BS->adc_channel);
	} else {
		ret_value = BC->last_value2[0];
	}

	PIN_ANALOG_X.pio->PIO_CODR = PIN_ANALOG_X.mask;
	PIN_ANALOG_Y.pio->PIO_SODR = PIN_ANALOG_Y.mask;
	BC->current_joystick_direction = JOYSTICK_DIRECTION_X;

	return ret_value;
}

int32_t position_from_analog_value_x(int32_t value) {
	if(value > MAX_ADC_VALUE/4 && value < MAX_ADC_VALUE*3/4) {
		value += BC->offset_x;
	}

	BC->avg_sum_x += value;
	BC->avg_counter_x++;

	if(BC->avg_counter_x == AVERAGE) {
		BC->avg_sum_x += AVERAGE*(MAX_ADC_VALUE/MAX_JOYSTICK_POSITION)/2;

		if(BC->avg_sum_x > MAX_ADC_VALUE*AVERAGE) {
			BC->avg_sum_x = MAX_ADC_VALUE*AVERAGE;
		}

		BC->avg_x = -MAX_JOYSTICK_POSITION/2 +
				    SCALE(BC->avg_sum_x/AVERAGE,
                          0,
                          MAX_ADC_VALUE,
                          0,
                          MAX_JOYSTICK_POSITION);
		BC->avg_sum_x = 0;
		BC->avg_counter_x = 0;
	}

	return BC->avg_x;
}

int32_t position_from_analog_value_y(int32_t value) {
	if(value > MAX_ADC_VALUE/4 && value < MAX_ADC_VALUE*3/4) {
		value += BC->offset_y;
	}

	BC->avg_sum_y += value;
	BC->avg_counter_y++;

	if(BC->avg_counter_y == AVERAGE) {
		BC->avg_sum_y += AVERAGE*(MAX_ADC_VALUE/MAX_JOYSTICK_POSITION)/2;

		if(BC->avg_sum_y > MAX_ADC_VALUE*AVERAGE) {
			BC->avg_sum_y = MAX_ADC_VALUE*AVERAGE;
		}

		BC->avg_y = MAX_JOYSTICK_POSITION/2 -
				    SCALE(BC->avg_sum_y/AVERAGE,
                          0,
                          MAX_ADC_VALUE,
                          0,
                          MAX_JOYSTICK_POSITION);
		BC->avg_sum_y = 0;
		BC->avg_counter_y = 0;
	}

	return BC->avg_y;
}

void constructor(void) {
	adc_channel_enable(BS->adc_channel);

	PIN_SWITCH.type = PIO_INPUT;
	PIN_SWITCH.attribute = PIO_DEFAULT;
    BA->PIO_Configure(&PIN_SWITCH, 1);

    PIN_ANALOG_X.type = PIO_OUTPUT_1;
    PIN_ANALOG_Y.type = PIO_OUTPUT_0;

    BA->PIO_Configure(&PIN_ANALOG_X, 1);
    BA->PIO_Configure(&PIN_ANALOG_Y, 1);

    BC->current_joystick_direction = JOYSTICK_DIRECTION_X;

    uint16_t data;

    BA->bricklet_select(BS->port - 'a');
    BA->i2c_eeprom_master_read(BA->twid->pTwi,
                               EEPROM_POSITION,
                               (char *)&data,
                               2);
    BA->bricklet_deselect(BS->port - 'a');

    if(data == 0xFFFF) {
    	BC->offset_x = 0;
    	BC->offset_y = 0;
    } else {
    	BC->offset_x = data & 0xFF;
    	BC->offset_y = data >> 8;
    }

    BC->pressed = false;
	simple_constructor();
}

void destructor(void) {
	simple_destructor();
	adc_channel_disable(BS->adc_channel);
}

void tick(uint8_t tick_type) {
	if(tick_type & TICK_TASK_TYPE_MESSAGE) {
		if(PIN_SWITCH.pio->PIO_PDSR & PIN_SWITCH.mask) {
			if(!BC->pressed) {
				BC->pressed = true;
				StandardMessage sm = {
					BS->stack_id,
					TYPE_PRESSED,
					sizeof(StandardMessage),
				};
				BA->send_blocking_with_timeout(&sm,
											   sizeof(StandardMessage),
											   *BA->com_current);
			}
		} else {
			if(BC->pressed) {
				BC->pressed = false;
				StandardMessage sm = {
					BS->stack_id,
					TYPE_RELEASED,
					sizeof(StandardMessage),
				};
				BA->send_blocking_with_timeout(&sm,
											   sizeof(StandardMessage),
											   *BA->com_current);
			}
		}
	}


	simple_tick(tick_type);
}
