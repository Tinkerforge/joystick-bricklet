function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletJoystick;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Joystick Bricklet

    ipcon = IPConnection(); % Create IP connection
    j = handle(BrickletJoystick(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position
    position = j.getPosition();

    fprintf('Position[X]: %i\n', position.x);
    fprintf('Position[Y]: %i\n', position.y);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
