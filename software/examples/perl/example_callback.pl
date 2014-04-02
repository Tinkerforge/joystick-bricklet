#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletJoystick;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => '6j9'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $js = Tinkerforge::BrickletJoystick->new(&UID, $ipcon); # Create device object

# Callback function for pressed and released events 
sub cb_pressed
{
    print "Pressed\n";
}

sub cb_released
{
    print "Released\n";
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register callbacks for pressed and released events
$js->register_callback($js->CALLBACK_PRESSED, 'cb_pressed');
$js->register_callback($js->CALLBACK_RELEASED, 'cb_released');

print "Press any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
