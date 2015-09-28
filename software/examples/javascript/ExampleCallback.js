var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change to your UID

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var j = new Tinkerforge.BrickletJoystick(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

// Register pressed callback
j.on(Tinkerforge.BrickletJoystick.CALLBACK_PRESSED,
    // Callback function for pressed callback
    function () {
        console.log('Pressed');
    }
);

// Register released callback
j.on(Tinkerforge.BrickletJoystick.CALLBACK_RELEASED,
    // Callback function for released callback
    function () {
        console.log('Released');
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
