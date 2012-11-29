#!/usr/bin/env python
# -*- coding: utf-8 -*-  

HOST = "localhost"
PORT = 4223
UID = "abcd" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_joystick import Joystick

# Callback function for pressed and released events 
def cb_pressed():
    print('Pressed')

def cb_released():
    print('Released')

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    js = Joystick(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register callbacks for pressed and released events
    js.register_callback(js.CALLBACK_PRESSED, cb_pressed)
    js.register_callback(js.CALLBACK_RELEASED, cb_released)

    raw_input('Press key to exit\n') # Use input() in Python 3
