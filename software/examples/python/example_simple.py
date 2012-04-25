#!/usr/bin/env python
# -*- coding: utf-8 -*-  

HOST = "localhost"
PORT = 4223
UID = "abcd" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_joystick import Joystick

if __name__ == "__main__":
    ipcon = IPConnection(HOST, PORT) # Create IP connection to brickd

    js = Joystick(UID) # Create device object
    ipcon.add_device(js) # Add device to IP connection
    # Don't use device before it is added to a connection

    # Get current position (returned as tuple x,y)
    position = js.get_position()

    print('Position: ' + str(position))

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.destroy()
