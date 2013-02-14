#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "6j9" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_joystick import Joystick

# Callback for x and y position outside of [-99..99]
def cb_reached(x, y):
    if y == 100:
        print('Top')
    elif y == -100:
        print('Bottom')

    if x == 100:
        print('Right')
    elif x == -100:
        print('Left')

    print('')

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    js = Joystick(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
    js.set_debounce_period(200)

    # Register threshold reached callback to function cb_reached
    js.register_callback(js.CALLBACK_POSITION_REACHED, cb_reached)

    # Configure threshold for "x and y value outside of [-99..99]"
    js.set_position_callback_threshold('o', -99, 99, -99, 99)

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.disconnect()
