<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystick.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystick;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change to your UID

// Callback function for pressed callback
function cb_pressed()
{
    echo "Pressed\n";
}

// Callback function for released callback
function cb_released()
{
    echo "Released\n";
}

$ipcon = new IPConnection(); // Create IP connection
$j = new BrickletJoystick(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register pressed callback to function cb_pressed
$j->registerCallback(BrickletJoystick::CALLBACK_PRESSED, 'cb_pressed');

// Register released callback to function cb_released
$j->registerCallback(BrickletJoystick::CALLBACK_RELEASED, 'cb_released');

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
