using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletJoystick joy = new BrickletJoystick(UID); // Create device object
		ipcon.AddDevice(joy); // Add device to IP connection
		// Don't use device before it is added to a connection


		// Get current position
		short posX;
		short posY;
		joy.GetPosition(out posX, out posY);

		System.Console.WriteLine("Position: (" + posX + ", " + posY + ")");

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
    }
}
