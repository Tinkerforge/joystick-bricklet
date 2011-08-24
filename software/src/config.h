/* joystick-bricklet
 * Copyright (C) 2010-2011 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config.h: Joystick Bricklet specific configuration
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

#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib/drivers/board/sam3s/SAM3S.h"

#include "joystick.h"

#define BOARD_MCK 64000000 // Frequency of brick

#define PIN_SWITCH   (BS->pin2_da)
#define PIN_ANALOG_X (BS->pin4_io)
#define PIN_ANALOG_Y (BS->pin3_pwm)

#define JOYSTICK_DIRECTION_X 1
#define JOYSTICK_DIRECTION_Y 2

#define LOGGING_LEVEL LOGGING_DEBUG
#define DEBUG_BRICKLET 0

#define BRICKLET_HAS_SIMPLE_SENSOR_X2
#define INVOCATION_IN_BRICKLET_CODE
#define NUM_SIMPLE_VALUES 2

typedef struct {
	int32_t value1[NUM_SIMPLE_VALUES];
	int32_t value2[NUM_SIMPLE_VALUES];
	int32_t last_value1[NUM_SIMPLE_VALUES];
	int32_t last_value2[NUM_SIMPLE_VALUES];
	int16_t avg_x;
	int16_t avg_y;
	int32_t avg_sum_x;
	int32_t avg_sum_y;
	uint8_t avg_counter_x;
	uint8_t avg_counter_y;

	uint32_t signal_period[NUM_SIMPLE_VALUES];
	uint32_t signal_period_counter[NUM_SIMPLE_VALUES];

	uint32_t threshold_debounce;
	uint32_t threshold_period_current[NUM_SIMPLE_VALUES];
	int32_t  threshold_min1[NUM_SIMPLE_VALUES];
	int32_t  threshold_max1[NUM_SIMPLE_VALUES];
	int32_t  threshold_min2[NUM_SIMPLE_VALUES];
	int32_t  threshold_max2[NUM_SIMPLE_VALUES];
	char     threshold_option[NUM_SIMPLE_VALUES];

	int32_t  threshold_min_save1[NUM_SIMPLE_VALUES];
	int32_t  threshold_max_save1[NUM_SIMPLE_VALUES];
	int32_t  threshold_min_save2[NUM_SIMPLE_VALUES];
	int32_t  threshold_max_save2[NUM_SIMPLE_VALUES];
	char     threshold_option_save[NUM_SIMPLE_VALUES];

	bool pressed;
	uint8_t current_joystick_direction;
	int8_t offset_x;
	int8_t offset_y;

	uint32_t tick;
} BrickContext;

#endif
