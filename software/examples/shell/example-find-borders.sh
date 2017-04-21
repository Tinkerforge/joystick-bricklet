#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Joystick Bricklet

# Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
tinkerforge call joystick-bricklet $uid set-debounce-period 200

# Handle incoming position reached callbacks
tinkerforge dispatch joystick-bricklet $uid position-reached\
 --execute "if   [ {y} -eq 100 ];
            then echo Top;
            elif [ {y} -eq -100 ];
            then echo Bottom;
            fi;
            if   [ {x} -eq 100 ];
            then echo Right;
            elif [ {x} -eq -100 ];
            then echo Left;
            fi" &

# Configure threshold for position "outside of -99, -99 to 99, 99"
tinkerforge call joystick-bricklet $uid set-position-callback-threshold threshold-option-outside -99 99 -99 99

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
