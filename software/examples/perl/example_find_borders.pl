#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletJoystick;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => '6j9'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $js = Tinkerforge::BrickletJoystick->new(&UID, $ipcon); # Create device object

# Callback for x and y position outside of [-99..99]
sub cb_reached
{
    my($x, $y) = @_;

    if($y == 100)
    {
        print "\nTop\n";
    }
    elsif($y == -100)
    {
        print "\nBottom\n";
    }
    if($x == 100)
    {
        print "\nRight\n";
    }
    elsif($x == -100)
    {
        print "\nLeft\n";
    }
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
$js->set_debounce_period(200);

# Register threshold reached callback to function cb_reached
$js->register_callback($js->CALLBACK_POSITION_REACHED, 'cb_reached');

# Configure threshold for "x and y value outside of [-99..99]"
$js->set_position_callback_threshold('o', -99, 99, -99, 99);

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
