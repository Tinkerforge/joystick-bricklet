#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletJoystick;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Joystick Bricklet

# Callback subroutine for pressed callback
sub cb_pressed
{
    print "Pressed\n";
}

# Callback subroutine for released callback
sub cb_released
{
    print "Released\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $j = Tinkerforge::BrickletJoystick->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register pressed callback to subroutine cb_pressed
$j->register_callback($j->CALLBACK_PRESSED, 'cb_pressed');

# Register released callback to subroutine cb_released
$j->register_callback($j->CALLBACK_RELEASED, 'cb_released');

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
