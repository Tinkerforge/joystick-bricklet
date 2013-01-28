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

# Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
js.set_debounce_period 200

# Register position callback for x or y position outside of [-99..99]
js.register_callback(BrickletJoystick::CALLBACK_POSITION_REACHED) do |x, y|
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

# Configure threshold for "x or y value outside of [-99..99]"
js.set_position_callback_threshold 'o', -99, 99, -99, 99

puts 'Press key to exit'
$stdin.gets
