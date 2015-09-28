function octave_example_callback()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    j = java_new("com.tinkerforge.BrickletJoystick", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register pressed callback to function cb_pressed
    j.addPressedCallback(@cb_pressed);

    % Register released callback to function cb_released
    j.addReleasedCallback(@cb_released);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for pressed callback
function cb_pressed(e)
    fprintf("Pressed\n");
end

% Callback function for released callback
function cb_released(e)
    fprintf("Released\n");
end
