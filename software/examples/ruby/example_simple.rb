#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_joystick'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = '82w' # Change to your UID

ipcon = IPConnection.new # Create IP connection
js = BrickletJoystick.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected


# Get current position (returned as array [x, y])
position = js.get_position
puts "Position: #{position}"

puts 'Press key to exit'
$stdin.gets
