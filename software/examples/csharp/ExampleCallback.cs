using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback functions for pressed and released events
	static void PressedCB()
	{
		System.Console.WriteLine("Pressed");
	}

	static void ReleasedCB()
	{
		System.Console.WriteLine("Released");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletJoystick joy = new BrickletJoystick(UID); // Create device object
		ipcon.AddDevice(joy); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Register callbacks for pressed and released events
		joy.RegisterCallback(new BrickletJoystick.Pressed(PressedCB));
		joy.RegisterCallback(new BrickletJoystick.Released(ReleasedCB));

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
	}
}
