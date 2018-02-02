#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Joystick Bricklet

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_joystick import BrickletJoystick

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    j = BrickletJoystick(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Get current position
    x, y = j.get_position()

    print("Position [X]: " + str(x))
    print("Position [Y]: " + str(y))

    raw_input("Press key to exit\n") # Use input() in Python 3
    ipcon.disconnect()
