using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick j = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get current position
		short posX;
		short posY;
		j.GetPosition(out posX, out posY);

		System.Console.WriteLine("Position: (" + posX + ", " + posY + ")");

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
    }
}
