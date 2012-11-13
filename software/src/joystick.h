/* joystick-bricklet
 * Copyright (C) 2010-2012 Olaf Lüke <olaf@tinkerforge.com>
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
#include <stdbool.h>

#include "bricklib/com/com_common.h"

#define FID_GET_POSITION 1
#define FID_IS_PRESSED 2
#define FID_GET_ANALOG_VALUE 3
#define FID_CALIBRATE 4
#define FID_SET_POSITION_SIGNAL_PERIOD 5
#define FID_GET_POSITION_SIGNAL_PERIOD 6
#define FID_SET_ANALOG_VALUE_SIGNAL_PERIOD 7
#define FID_GET_ANALOG_VALUE_SIGNAL_PERIOD 8
#define FID_SET_POSITION_SIGNAL_THRESHOLD 9
#define FID_GET_POSITION_SIGNAL_THRESHOLD 10
#define FID_SET_ANALOG_VALUE_SIGNAL_THRESHOLD 11
#define FID_GET_ANALOG_VALUE_SIGNAL_THRESHOLD 12
#define FID_SET_DEBOUNCE_PERIOD 13
#define FID_GET_DEBOUNCE_PERIOD 14
#define FID_POSITION 15
#define FID_ANALOG_VALUE 16
#define FID_POSITION_REACHED 17
#define FID_ANALOG_VALUE_REACHED 18
#define FID_PRESSED 19
#define FID_RELEASED 20

#define FID_LAST 20

typedef struct {
	MessageHeader header;
	bool value;
} __attribute__((__packed__)) BoolMessage;


typedef struct {
	MessageHeader header;
} __attribute__((__packed__)) StandardMessage;

int32_t analog_value_from_mc_x(const int32_t value);
int32_t analog_value_from_mc_y(const int32_t value);
int32_t position_from_analog_value_x(const int32_t value);
int32_t position_from_analog_value_y(const int32_t value);
void is_pressed(const ComType com, const StandardMessage *sm);
void calibrate(const ComType com, const StandardMessage *sm);
void invocation(const ComType com, const uint8_t *data);
void constructor(void);
void destructor(void);
void tick(const uint8_t tick_type);

#endif
