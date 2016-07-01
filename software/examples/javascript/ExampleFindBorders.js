var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Joystick Bricklet

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var j = new Tinkerforge.BrickletJoystick(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
        j.setDebouncePeriod(200);

        // Configure threshold for position "outside of -99, -99 to 99, 99"
        j.setPositionCallbackThreshold('o', -99, 99, -99, 99);
    }
);

// Register position reached callback
j.on(Tinkerforge.BrickletJoystick.CALLBACK_POSITION_REACHED,
    // Callback function for position reached callback
    function (x, y) {
        if(y === 100) {
            console.log('Top');
        }
        else if(y === -100) {
            console.log('Bottom');
        }

        if(x === 100) {
            console.log('Right');
        }
        else if(x === -100) {
            console.log('Left');
        }

        console.log();
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
