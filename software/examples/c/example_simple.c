#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_joystick.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

int main(void) {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Joystick j;
	joystick_create(&j, UID, &ipcon);

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		return 1;
	}
	// Don't use device before ipcon is connected

	// Get current position (x and y value)
	int16_t pos_x;
	int16_t pos_y;
	if(joystick_get_position(&j, &pos_x, &pos_y) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		return 1;
	}

	printf("Position: %d, %d\n", pos_x, pos_y);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
	return 0;
}
