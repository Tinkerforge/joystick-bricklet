/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_JOYSTICK_H
#define BRICKLET_JOYSTICK_H

#include "ip_connection.h"

typedef Device Joystick;

#define JOYSTICK_CALLBACK_POSITION 15
#define JOYSTICK_CALLBACK_ANALOG_VALUE 16
#define JOYSTICK_CALLBACK_POSITION_REACHED 17
#define JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED 18
#define JOYSTICK_CALLBACK_PRESSED 19
#define JOYSTICK_CALLBACK_RELEASED 20

void joystick_create(Joystick *joystick, const char *uid);

int joystick_get_position(Joystick *joystick, int16_t *ret_x, int16_t *ret_y);
int joystick_is_pressed(Joystick *joystick, bool *ret_pressed);
int joystick_get_analog_value(Joystick *joystick, uint16_t *ret_x, uint16_t *ret_y);
int joystick_calibrate(Joystick *joystick);
int joystick_set_position_callback_period(Joystick *joystick, uint32_t period);
int joystick_get_position_callback_period(Joystick *joystick, uint32_t *ret_period);
int joystick_set_analog_value_callback_period(Joystick *joystick, uint32_t period);
int joystick_get_analog_value_callback_period(Joystick *joystick, uint32_t *ret_period);
int joystick_set_position_callback_threshold(Joystick *joystick, char option, int16_t min_x, int16_t max_x, int16_t min_y, int16_t max_y);
int joystick_get_position_callback_threshold(Joystick *joystick, char *ret_option, int16_t *ret_min_x, int16_t *ret_max_x, int16_t *ret_min_y, int16_t *ret_max_y);
int joystick_set_analog_value_callback_threshold(Joystick *joystick, char option, uint16_t min_x, uint16_t max_x, uint16_t min_y, uint16_t max_y);
int joystick_get_analog_value_callback_threshold(Joystick *joystick, char *ret_option, uint16_t *ret_min_x, uint16_t *ret_max_x, uint16_t *ret_min_y, uint16_t *ret_max_y);
int joystick_set_debounce_period(Joystick *joystick, uint32_t debounce);
int joystick_get_debounce_period(Joystick *joystick, uint32_t *ret_debounce);
int joystick_position(Joystick *joystick, int16_t *ret_x, int16_t *ret_y);
int joystick_analog_value(Joystick *joystick, uint16_t *ret_x, uint16_t *ret_y);
int joystick_position_reached(Joystick *joystick, int16_t *ret_x, int16_t *ret_y);
int joystick_analog_value_reached(Joystick *joystick, uint16_t *ret_x, uint16_t *ret_y);
int joystick_pressed(Joystick *joystick);
int joystick_released(Joystick *joystick);

void joystick_register_callback(Joystick *joystick, uint8_t cb, void *func);

#endif