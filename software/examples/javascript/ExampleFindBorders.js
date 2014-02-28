var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'dmG'; // Change to your UID

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var js = new Tinkerforge.BrickletJoystick(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function(error) {
        console.log('Error: '+error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function(connectReason) {
        // Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
        js.setDebouncePeriod(200);
        // Configure threshold for "x and y value outside of [-99..99]"
        js.setPositionCallbackThreshold('o', -99, 99, -99, 99);
    }
);

// Register threshold reached callback
js.on(Tinkerforge.BrickletJoystick.CALLBACK_POSITION_REACHED,
    function(x, y) {
        if(y === 100) {
            console.log('Top');
        }
        if(y === -100) {
            console.log('Bottom');
        }
        if(x === 100) {
            console.log('Right');
        }
        if(x === -100) {
            console.log('Left');
        }
        console.log();
    }
);

console.log("Press any key to exit ...");
process.stdin.on('data',
    function(data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
