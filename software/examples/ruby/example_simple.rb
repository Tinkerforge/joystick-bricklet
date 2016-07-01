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

# Get current position (returned as [x, y])
position = j.get_position

puts "Position[X]: #{position[0]}"
puts "Position[Y]: #{position[1]}"

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
