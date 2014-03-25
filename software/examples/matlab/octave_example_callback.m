function octave_example_callback
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "dmC"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    js = java_new("com.tinkerforge.BrickletJoystick", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register callbacks for pressed and released events
    js.addPressedListener("cb_pressed");
    js.addReleasedListener("cb_released");

    input("\nPress any key to exit...\n", "s");
    ipcon.disconnect();
end

% Callback function for pressed and released events 
function cb_pressed()
    fprintf('Pressed\n');
end

function cb_released()
    fprintf('Released\n');
end
