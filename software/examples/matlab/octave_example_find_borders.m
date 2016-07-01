function octave_example_find_borders()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Joystick Bricklet

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    j = java_new("com.tinkerforge.BrickletJoystick", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
    j.setDebouncePeriod(200);

    % Register position reached callback to function cb_position_reached
    j.addPositionReachedCallback(@cb_position_reached);

    % Configure threshold for position "outside of -99, -99 to 99, 99"
    j.setPositionCallbackThreshold("o", -99, 99, -99, 99);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for position reached callback
function cb_position_reached(e)
    x = java2int(e.x);
    y = java2int(e.y);

    if y == 100
        fprintf("Top\n");
    elseif y == -100
        fprintf("Bottom\n");
    end
    if x == 100
        fprintf("Right\n");
    elseif x ==-100
        fprintf("Left\n");
    end
    fprintf("\n");
end

function int = java2int(value)
    if compare_versions(version(), "3.8", "<=")
        int = value.intValue();
    else
        int = value;
    end
end
