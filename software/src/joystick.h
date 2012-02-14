/* joystick-bricklet
 * Copyright (C) 2010-2011 Olaf Lüke <olaf@tinkerforge.com>
 *
 * joystick.h: Implementation of Joystick Bricklet messages
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

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdint.h>

#define TYPE_GET_POSITION 1
#define TYPE_IS_PRESSED 2
#define TYPE_GET_ANALOG_VALUE 3
#define TYPE_CALIBRATE 4
#define TYPE_SET_POSITION_SIGNAL_PERIOD 5
#define TYPE_GET_POSITION_SIGNAL_PERIOD 6
#define TYPE_SET_ANALOG_VALUE_SIGNAL_PERIOD 7
#define TYPE_GET_ANALOG_VALUE_SIGNAL_PERIOD 8
#define TYPE_SET_POSITION_SIGNAL_THRESHOLD 9
#define TYPE_GET_POSITION_SIGNAL_THRESHOLD 10
#define TYPE_SET_ANALOG_VALUE_SIGNAL_THRESHOLD 11
#define TYPE_GET_ANALOG_VALUE_SIGNAL_THRESHOLD 12
#define TYPE_SET_DEBOUNCE_PERIOD 13
#define TYPE_GET_DEBOUNCE_PERIOD 14
#define TYPE_POSITION 15
#define TYPE_ANALOG_VALUE 16
#define TYPE_POSITION_REACHED 17
#define TYPE_ANALOG_VALUE_REACHED 18
#define TYPE_PRESSED 19
#define TYPE_RELEASED 20

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool value;
} __attribute__((__packed__)) BoolMessage;


typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} __attribute__((__packed__)) StandardMessage;

int32_t analog_value_from_mc_x(int32_t value);
int32_t analog_value_from_mc_y(int32_t value);
int32_t position_from_analog_value_x(int32_t value);
int32_t position_from_analog_value_y(int32_t value);
void is_pressed(uint8_t com, StandardMessage *sm);
void calibrate(void);
void invocation(uint8_t com, uint8_t *data);
void constructor(void);
void destructor(void);
void tick(uint8_t tick_type);

#endif
