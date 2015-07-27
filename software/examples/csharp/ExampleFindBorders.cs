using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	// Callback for x or y position outside of [-99..99]
	static void ReachedCB(BrickletJoystick sender, short x, short y)
	{
		if(y == 100)
		{
			System.Console.WriteLine("Top");
		}
		else if(y == -100)
		{
			System.Console.WriteLine("Bottom");
		}

		if(x == 100)
		{
			System.Console.WriteLine("Right");
		}
		else if(x == -100)
		{
			System.Console.WriteLine("Left");
		}

		System.Console.WriteLine("");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick j = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
		j.SetDebouncePeriod(200);

		// Register threshold reached callback to function ReachedCB
		j.PositionReached += ReachedCB;

		// Configure threshold for "x or y value outside of [-99..99]"
		j.SetPositionCallbackThreshold('o', -99, 99, -99, 99);

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
