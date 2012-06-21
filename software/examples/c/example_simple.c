
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_joystick.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abcd" // Change to your UID

int main() {
	// Create IP connection to brickd
	IPConnection ipcon;
	if(ipcon_create(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not create connection\n");
		exit(1);
	}

	// Create device object
	Joystick js;
	joystick_create(&js, UID); 

	// Add device to IP connection
	if(ipcon_add_device(&ipcon, &js) < 0) {
		fprintf(stderr, "Could not connect to Bricklet\n");
		exit(1);
	}
	// Don't use device before it is added to a connection

	// Get current position (x and y value)
	int16_t pos_x;
	int16_t pos_y;
	if(joystick_get_position(&js, &pos_x, &pos_y) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Position: %d, %d\n", pos_x, pos_y);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
