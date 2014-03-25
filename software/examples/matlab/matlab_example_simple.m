function matlab_example_simple
    import com.tinkerforge.BrickletJoystick;
    import com.tinkerforge.IPConnection;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'dmC'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    js = BrickletJoystick(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position (returned as x, y coordinate)
    pos = js.getPosition();
    fprintf('Position(x): %g\n', pos.x);
    fprintf('Position(y): %g\n', pos.y);

    input('\nPress any key to exit...\n', 's');
    ipcon.disconnect();
end
