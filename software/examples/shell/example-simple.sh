#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# gt current position (x and y value)
tinkerforge call joystick-bricklet $uid get-position
