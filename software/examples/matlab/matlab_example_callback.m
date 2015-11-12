function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletJoystick;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    j = handle(BrickletJoystick(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register pressed callback to function cb_pressed
    set(j, 'PressedCallback', @(h, e) cb_pressed(e));

    % Register released callback to function cb_released
    set(j, 'ReleasedCallback', @(h, e) cb_released(e));

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for pressed callback
function cb_pressed(e)
    fprintf('Pressed\n');
end

% Callback function for released callback
function cb_released(e)
    fprintf('Released\n');
end
