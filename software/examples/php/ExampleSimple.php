<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletJoystick.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletJoystick;

$host = 'localhost';
$port = 4223;
$uid = '82w'; // Change to your UID

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$js = new BrickletJoystick($uid); // Create device object

$ipcon->addDevice($js); // Add device to IP connection
// Don't use device before it is added to a connection

// Get current position (returned as array with keys 'x' and 'y')
$position = $js->getPosition();

echo "Position: " . $position['x'] . ", " . $position['y'] . "\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->destroy();

?>
