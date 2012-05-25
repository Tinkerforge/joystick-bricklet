#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_joystick'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = '82w' # Change to your UID

ipcon = IPConnection.new HOST, PORT # Create IP connection to brickd
js = BrickletJoystick.new UID # Create device object
ipcon.add_device js # Add device to IP connection
# Don't use device before it is added to a connection

# Get current position (returned as array [x, y])
position = js.get_position
puts "Position: #{position}"

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
