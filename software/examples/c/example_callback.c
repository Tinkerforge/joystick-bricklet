
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_joystick.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abcd" // Change to your UID

// Callback function for pressed and released events 
void cb_pressed(void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Pressed\n");
}

void cb_released(void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Released\n");
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

	// Register callbacks for pressed and released events
	joystick_register_callback(&js, 
	                           JOYSTICK_CALLBACK_PRESSED, 
	                           (void *)cb_pressed,
	                           NULL);

	joystick_register_callback(&js, 
	                           JOYSTICK_CALLBACK_RELEASED, 
	                           (void *)cb_released,
	                           NULL);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
