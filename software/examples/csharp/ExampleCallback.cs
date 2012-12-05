using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback functions for pressed and released events
	static void PressedCB(object sender)
	{
		System.Console.WriteLine("Pressed");
	}

	static void ReleasedCB(object sender)
	{
		System.Console.WriteLine("Released");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick joy = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register callbacks for pressed and released events
		joy.Pressed += PressedCB;
		joy.Released += ReleasedCB;

		System.Console.WriteLine("Press key to exit");
	}
}
