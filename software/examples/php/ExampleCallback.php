<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystick.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystick;

$host = 'localhost';
$port = 4223;
$uid = '82w'; // Change to your UID

// Callback function for pressed and released events 
function cb_pressed()
{
    echo "Pressed\n";
}

function cb_released()
{
    echo "Released\n";
}

$ipcon = new IPConnection(); // Create IP connection
$js = new BrickletJoystick($uid, $ipcon); // Create device object

$ipcon->connect($host, $port); // Connect to brickd
// Don't use device before ipcon is connected

// Register callbacks for pressed and released events
$js->registerCallback(BrickletJoystick::CALLBACK_PRESSED, 'cb_pressed');
$js->registerCallback(BrickletJoystick::CALLBACK_RELEASED, 'cb_released');

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
