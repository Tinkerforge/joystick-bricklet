function octave_example_find_borders()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "aQ2"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    js = java_new("com.tinkerforge.BrickletJoystick", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
    js.setDebouncePeriod(200);

    % Register threshold reached callback to function cb_reached
    js.addPositionReachedCallback(@cb_reached);

    % Configure threshold for "x and y value outside of [-99..99]"
    js.setPositionCallbackThreshold(js.THRESHOLD_OPTION_OUTSIDE, -99, 99, -99, 99);

    input("Press any key to exit...\n", "s");
    ipcon.disconnect()
end

% Callback for x and y position outside of [-99..99]
function cb_reached(e)
    x = short2int(e.x);
    y = short2int(e.y);

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

function int = short2int(short)
    if compare_versions(version(), "3.8", "<=")
        int = short.intValue();
    else
        int = short;
    end
end
