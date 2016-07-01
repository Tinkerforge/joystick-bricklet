#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletJoystick;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Joystick Bricklet

# Callback subroutine for position reached callback
sub cb_position_reached
{
    my ($x, $y) = @_;

    if ($y == 100)
    {
        print "Top\n";
    }
    elsif ($y == -100)
    {
        print "Bottom\n";
    }

    if ($x == 100)
    {
        print "Right\n";
    }
    elsif ($x == -100)
    {
        print "Left\n";
    }

    print "\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $j = Tinkerforge::BrickletJoystick->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
$j->set_debounce_period(200);

# Register position reached callback to subroutine cb_position_reached
$j->register_callback($j->CALLBACK_POSITION_REACHED, 'cb_position_reached');

# Configure threshold for position "outside of -99, -99 to 99, 99"
$j->set_position_callback_threshold('o', -99, 99, -99, 99);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
