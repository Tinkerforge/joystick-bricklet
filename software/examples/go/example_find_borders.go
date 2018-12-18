package main

import (
	"fmt"
    "github.com/Tinkerforge/go-api-bindings/ipconnection"
    "github.com/Tinkerforge/go-api-bindings/joystick_bricklet"
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

	// Get threshold receivers with a debounce time of 0.2 seconds (200ms).
	j.SetDebouncePeriod(200)

	j.RegisterPositionReachedCallback(func(x int16, y int16) {
		if y == 100 {
            fmt.Println("Top");
        } else if y == -100 {
            fmt.Println("Bottom");
        } else if x == 100 {
            fmt.Println("Right");
        } else if x == -100 {
            fmt.Println("Left");
        }
        fmt.Println();
	})

	// Configure threshold for position "outside of -99, -99 to 99, 99".
	j.SetPositionCallbackThreshold('o', -99, 99, -99, 99)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

	ipcon.Disconnect()
}
