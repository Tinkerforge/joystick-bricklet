#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# get threshold callbacks with a debounce time of 0.2 seconds (200ms)
tinkerforge call joystick-bricklet $uid set-debounce-period 200

# configure threshold for "x or y value outside of [-99..99]"
tinkerforge call joystick-bricklet $uid set-position-callback-threshold outside -99 99 -99 99

# handle incoming position-reached callbacks
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
            fi"
