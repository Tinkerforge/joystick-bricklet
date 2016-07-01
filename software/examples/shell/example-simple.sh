#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Joystick Bricklet

# Get current position
tinkerforge call joystick-bricklet $uid get-position
