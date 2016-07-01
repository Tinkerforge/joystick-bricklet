#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Joystick Bricklet

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_joystick import BrickletJoystick

# Callback function for pressed callback
def cb_pressed():
    print("Pressed")

# Callback function for released callback
def cb_released():
    print("Released")

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    j = BrickletJoystick(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register pressed callback to function cb_pressed
    j.register_callback(j.CALLBACK_PRESSED, cb_pressed)

    # Register released callback to function cb_released
    j.register_callback(j.CALLBACK_RELEASED, cb_released)

    raw_input("Press key to exit\n") # Use input() in Python 3
    ipcon.disconnect()
