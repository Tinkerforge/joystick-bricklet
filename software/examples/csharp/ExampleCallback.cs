using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	// Callback functions for pressed and released events
	static void PressedCB(BrickletJoystick sender)
	{
		System.Console.WriteLine("Pressed");
	}

	static void ReleasedCB(BrickletJoystick sender)
	{
		System.Console.WriteLine("Released");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick j = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register callbacks for pressed and released events
		j.Pressed += PressedCB;
		j.Released += ReleasedCB;

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
