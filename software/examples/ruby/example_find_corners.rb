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

# Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
js.set_debounce_period 200

# Register position callback for x and y position outside of -99, 99
js.register_callback(BrickletJoystick::CALLBACK_POSITION_REACHED) do |x, y|
  if x == 100 and y == 100
    puts 'Top Right'
  elsif x == -100 and y == 100
    puts 'Top Left'
  elsif x == -100 and y == -100
    puts 'Bottom Left'
  elsif x == 100 and y == -100
    puts 'Bottom Right'
  else
    # This can't happen, the threshold is configured to:
    # "outside of -99, 99"
    puts 'Error'
  end
end

# Configure threshold for "x and y value outside of -99 and 99"
js.set_position_callback_threshold 'o', -99, 99, -99, 99

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
