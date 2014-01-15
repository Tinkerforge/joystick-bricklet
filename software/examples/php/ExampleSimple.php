<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystick.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystick;

const HOST = 'localhost';
const PORT = 4223;
const UID = '82w'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$js = new BrickletJoystick(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current position (returned as array with keys 'x' and 'y')
$position = $js->getPosition();

echo "Position: " . $position['x'] . ", " . $position['y'] . "\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
