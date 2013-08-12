#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# handle incoming pressed and released callbacks
tinkerforge dispatch joystick-bricklet $uid pressed\
 --execute "echo Pressed;
            tinkerforge dispatch --duration exit-after-first joystick-bricklet $uid released\
             --execute 'echo Released'"
