function matlab_example_find_borders()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletJoystick;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    j = BrickletJoystick(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
    j.setDebouncePeriod(200);

    % Register position reached callback to function cb_position_reached
    set(j, 'PositionReachedCallback', @(h, e) cb_position_reached(e));

    % Configure threshold for position "outside of -99, -99 to 99, 99"
    j.setPositionCallbackThreshold('o', -99, 99, -99, 99);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for position reached callback
function cb_position_reached(e)
    if e.y == 100
        fprintf('Top\n');
    elseif e.y == -100
        fprintf('Bottom\n');
    end
    if e.x == 100
        fprintf('Right\n');
    elseif e.x == -100
        fprintf('Left\n');
    end
    fprintf('\n');
end
