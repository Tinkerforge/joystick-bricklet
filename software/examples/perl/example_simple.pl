#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletJoystick;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Joystick Bricklet

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $j = Tinkerforge::BrickletJoystick->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current position
my ($x, $y) = $j->get_position();

print "Position [X]: $x\n";
print "Position [Y]: $y\n";

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
