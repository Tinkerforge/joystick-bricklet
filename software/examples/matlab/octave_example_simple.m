function octave_example_simple()
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "dmC"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    js = java_new("com.tinkerforge.BrickletJoystick", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position (returned as x, y coordinate)
    pos = js.getPosition();
    fprintf("Position(x): %s\n", pos.x.toString());
    fprintf("Position(y): %s\n", pos.y.toString());

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end
