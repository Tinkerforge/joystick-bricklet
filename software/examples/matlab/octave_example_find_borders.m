function octave_example_find_borders
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "dmC"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    js = java_new("com.tinkerforge.BrickletJoystick", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
    js.setDebouncePeriod(200);

    % Register threshold reached callback to function cb_reached
    js.addPositionReachedListener("cb_reached");

    % Configure threshold for "x and y value outside of [-99..99]"
    js.setPositionCallbackThreshold(js.THRESHOLD_OPTION_OUTSIDE, -99, 99, -99, 99);

    input("\nPress any key to exit...\n", "s");
    ipcon.disconnect()
end

% Callback for x and y position outside of [-99..99]
function cb_reached(x, y)
    x = str2double(x.toString());
    y = str2double(y.toString());
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
