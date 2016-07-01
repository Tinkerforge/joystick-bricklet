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

# Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
j.set_debounce_period 200

# Register position reached callback
j.register_callback(BrickletJoystick::CALLBACK_POSITION_REACHED) do |x, y|
  if y == 100
    puts 'Top'
  elsif y == -100
    puts 'Bottom'
  end

  if x == 100
    puts 'Right'
  elsif x == -100
    puts 'Left'
  end

  puts ''
end

# Configure threshold for position "outside of -99, -99 to 99, 99"
j.set_position_callback_threshold 'o', -99, 99, -99, 99

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
