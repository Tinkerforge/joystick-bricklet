#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_joystick'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Joystick Bricklet

ipcon = IPConnection.new # Create IP connection
j = BrickletJoystick.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Register pressed callback
j.register_callback(BrickletJoystick::CALLBACK_PRESSED) do
  puts 'Pressed'
end

# Register released callback
j.register_callback(BrickletJoystick::CALLBACK_RELEASED) do
  puts 'Released'
end

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
