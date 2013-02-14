
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_joystick.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abcd" // Change to your UID

// Callback for x or y position outside of [-99..99]
void cb_reached(int16_t x, int16_t y, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	if(y == 100) {
		printf("Top\n");
	} else if(y == -100) {
		printf("Bottom\n");
	}

	if(x == 100) {
		printf("Right\n");
	} else if(x == -100) {
		printf("Left\n");
	}

	printf("\n");
}

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Joystick js;
	joystick_create(&js, UID, &ipcon);

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
	joystick_set_debounce_period(&js, 200);

	// Register threshold reached callback to function cb_reached
	joystick_register_callback(&js,
	                           JOYSTICK_CALLBACK_POSITION_REACHED,
	                           (void *)cb_reached,
	                           NULL);

	// Configure threshold for "x or y value outside of [-99..99]"
	joystick_set_position_callback_threshold(&js, 'o', -99, 99, -99, 99);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
