<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystick.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystick;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Joystick Bricklet

// Callback function for position reached callback
function cb_positionReached($x, $y)
{
    if ($y == 100) {
        echo "Top\n";
    } elseif ($y == -100) {
        echo "Bottom\n";
    }

    if ($x == 100) {
        echo "Right\n";
    } elseif ($x == -100) {
        echo "Left\n";
    }

    echo "\n";
}

$ipcon = new IPConnection(); // Create IP connection
$j = new BrickletJoystick(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
$j->setDebouncePeriod(200);

// Register position reached callback to function cb_positionReached
$j->registerCallback(BrickletJoystick::CALLBACK_POSITION_REACHED, 'cb_positionReached');

// Configure threshold for position "outside of -99, -99 to 99, 99"
$j->setPositionCallbackThreshold('o', -99, 99, -99, 99);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
