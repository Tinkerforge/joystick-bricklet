function matlab_example_find_borders
    import com.tinkerforge.BrickletJoystick;
    import com.tinkerforge.IPConnection;
    
    HOST ='localhost';
    PORT = 4223;
    UID = 'dmC'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    js = BrickletJoystick(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT) % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
    js.setDebouncePeriod(200);

    % Register threshold reached callback to function cb_reached
    set(js, 'PositionReachedCallback', @(h, e) cb_reached(e));

    % Configure threshold for "x and y value outside of [-99..99]"
    js.setPositionCallbackThreshold('o', -99, 99, -99, 99);

    input('Press any key to exit...\n', 's');
    ipcon.disconnect()
end

% Callback for x and y position outside of [-99..99]
function cb_reached(e)
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
