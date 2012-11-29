<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystick.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystick;

$host = 'localhost';
$port = 4223;
$uid = '82w'; // Change to your UID

// Callback for x and y position outside of -99, 99
function cb_reached($x, $y)
{
    if ($x == 100 && $y == 100) {
        echo "Top Right\n";
    } elseif ($x == -100 && $y == 100) {
        echo "Top Left\n";
    } elseif ($x == -100 && $y == -100) {
        echo "Bottom Left\n";
    } elseif ($x == 100 && $y == -100) {
        echo "Bottom Right\n";
    } else {
        // This can't happen, the threshold is configured to:
        // "outside of -99, 99"
        echo "Error\n";
    }
}

$ipcon = new IPConnection(); // Create IP connection
$js = new BrickletJoystick($uid, $ipcon); // Create device object

$ipcon->connect($host, $port); // Connect to brickd
// Don't use device before ipcon is connected

// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
$js->setDebouncePeriod(200);

// Register threshold reached callback to function cb_reached
$js->registerCallback(BrickletJoystick::CALLBACK_POSITION_REACHED, 'cb_reached');

// Configure threshold for "x and y value outside of -99 and 99"
$js->setPositionCallbackThreshold('o', -99, 99, -99, 99);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
