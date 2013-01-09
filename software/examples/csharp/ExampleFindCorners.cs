using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback for x and y position outside of -99, 99
	static void ReachedCB(BrickletJoystick sender, short x, short y)
	{
		if(x == 100 && y == 100)
		{
			System.Console.WriteLine("Top Right");
		}
		else if(x == -100 && y == 100)
		{
			System.Console.WriteLine("Top Left");
		}
		else if(x == -100 && y == -100)
		{
			System.Console.WriteLine("Bottom Left");
		}
		else if(x == 100 && y == -100)
		{
			System.Console.WriteLine("Bottom Right");
		}
		else
		{
			// This can't happen, the threshold is configured to: "outside of -99, 99"
			System.Console.WriteLine("Error");
		}
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick joy = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
		joy.SetDebouncePeriod(200);

		// Register threshold reached callback to function ReachedCB
		joy.PositionReached += ReachedCB;

		// Configure threshold for "x and y value outside of -99 and 99"
		joy.SetPositionCallbackThreshold('o', -99, 99, -99, 99);

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
	}
}
