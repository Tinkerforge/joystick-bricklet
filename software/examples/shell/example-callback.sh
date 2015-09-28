#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change to your UID

# Handle incoming pressed callbacks
tinkerforge dispatch joystick-bricklet $uid pressed\
 --execute "echo Pressed" &

# Handle incoming released callbacks
tinkerforge dispatch joystick-bricklet $uid released\
 --execute "echo Released" &

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
