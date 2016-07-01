using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Joystick Bricklet

	// Callback function for position reached callback
	static void PositionReachedCB(BrickletJoystick sender, short x, short y)
	{
		if(y == 100)
		{
			Console.WriteLine("Top");
		}
		else if(y == -100)
		{
			Console.WriteLine("Bottom");
		}

		if(x == 100)
		{
			Console.WriteLine("Right");
		}
		else if(x == -100)
		{
			Console.WriteLine("Left");
		}

		Console.WriteLine("");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick j = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
		j.SetDebouncePeriod(200);

		// Register position reached callback to function PositionReachedCB
		j.PositionReached += PositionReachedCB;

		// Configure threshold for position "outside of -99, -99 to 99, 99"
		j.SetPositionCallbackThreshold('o', -99, 99, -99, 99);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
