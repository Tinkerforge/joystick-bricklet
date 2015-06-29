function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "aQ2"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    js = java_new("com.tinkerforge.BrickletJoystick", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current position (returned as x, y coordinate)
    pos = js.getPosition();
    fprintf("Position(x): %d\n", short2int(pos.x));
    fprintf("Position(y): %d\n", short2int(pos.y));

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end

function int = short2int(short)
    if compare_versions(version(), "3.8", "<=")
        int = short.intValue();
    else
        int = short;
    end
end
