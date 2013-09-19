
// This example is Windows only. Link to user32.lib in addition to ws2_32.lib

#include <stdio.h>
#include <windows.h>

#include "ip_connection.h"
#include "bricklet_joystick.h"

#define HOST "localhost"
#define PORT 4223
#define UID "dmC" // Change to your UID

// Fake a mouse button event
void send_mouse_button(uint32_t event) {
	INPUT input;

	memset(&input, 0, sizeof(INPUT));

	input.type = INPUT_MOUSE;
	input.mi.dwFlags = event;

	SendInput(1, &input, sizeof(INPUT));
}

// Fake a mouse move event
void send_mouse_move(int16_t x, int16_t y) {
	INPUT input;
	memset(&input, 0, sizeof(INPUT));

	input.type = INPUT_MOUSE;
	input.mi.dx = x;
	input.mi.dy = y;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;

	SendInput(1, &input, sizeof(INPUT));
}

// Callback function for pressed and released events
void cb_pressed(void *user_data) {
	(void)user_data; // avoid unused parameter warning

	send_mouse_button(MOUSEEVENTF_LEFTDOWN);
}

void cb_released(void *user_data) {
	(void)user_data; // avoid unused parameter warning

	send_mouse_button(MOUSEEVENTF_LEFTUP);
}

// Joystick moves mouse and the button is mapped to left mouse button
int main() {
	IPConnection ipcon;
	Joystick js;

	// Create IP connection
	ipcon_create(&ipcon);

	// Create device object
	joystick_create(&js, UID, &ipcon);

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Register callbacks for pressed and released events
	joystick_register_callback(&js,
	                           JOYSTICK_CALLBACK_PRESSED,
	                           (void *)cb_pressed,
	                           NULL);

	joystick_register_callback(&js,
	                           JOYSTICK_CALLBACK_RELEASED,
	                           (void *)cb_released,
	                           NULL);

	printf("Press ctrl+c to exit\n");

	while(true) {
		int16_t x, y;
		joystick_get_position(&js, &x, &y);

		x = x / 4; // Slow down by factor of 4
		y = -y / 4; // Slow down by factor of 4 and invert axis

		send_mouse_move(x, y);

		Sleep(25); // Check Joystick position every 0.025s (25ms)
	}

	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally

	return 0;
}
