#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# handle incoming pressed and released callbacks
# note: this chaining of two dispatches assumes that a pressed callback is
#       always followed by a released callback
tinkerforge dispatch joystick-bricklet $uid pressed\
 --execute "echo Pressed;
            tinkerforge dispatch --duration exit-after-first joystick-bricklet $uid released\
             --execute 'echo Released'"
