<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystick.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystick;

const HOST = 'localhost';
const PORT = 4223;
const UID = '82w'; // Change to your UID

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
$js = new BrickletJoystick(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register callbacks for pressed and released events
$js->registerCallback(BrickletJoystick::CALLBACK_PRESSED, 'cb_pressed');
$js->registerCallback(BrickletJoystick::CALLBACK_RELEASED, 'cb_released');

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
