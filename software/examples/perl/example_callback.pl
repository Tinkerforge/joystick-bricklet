#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletJoystick;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => '6j9'; # Change to your UID

my $ipcon = IPConnection->new(); # Create IP connection
my $js = BrickletJoystick->new(&UID, $ipcon); # Create device object

# Callback function for pressed and released events 
sub cb_pressed
{
    print "\nPressed\n";
}
sub cb_released
{
    print "\nReleased\n";
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register callbacks for pressed and released events
$js->register_callback($js->CALLBACK_PRESSED, 'cb_pressed');
$js->register_callback($js->CALLBACK_RELEASED, 'cb_released');

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
