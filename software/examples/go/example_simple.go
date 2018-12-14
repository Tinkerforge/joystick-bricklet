package main

import (
	"fmt"
	"tinkerforge/ipconnection"
	"tinkerforge/joystick_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Joystick Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	j, _ := joystick_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Get current position.
	x, y, _ := j.GetPosition()

	fmt.Printf("Position [X]: \n", x)
	fmt.Printf("Position [Y]: \n", y)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}
