package main

import (
	"fmt"
	"github.com/tinkerforge/go-api-bindings/ipconnection"
	"github.com/tinkerforge/go-api-bindings/joystick_bricklet"
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

	j.RegisterPressedCallback(func() {
		fmt.Println("Pressed")
	})

	j.RegisterReleasedCallback(func() {
		fmt.Println("Released")
	})

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}
