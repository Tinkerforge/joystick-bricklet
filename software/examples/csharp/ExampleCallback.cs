using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	// Callback function for pressed callback
	static void PressedCB(BrickletJoystick sender)
	{
		Console.WriteLine("Pressed");
	}

	// Callback function for released callback
	static void ReleasedCB(BrickletJoystick sender)
	{
		Console.WriteLine("Released");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick j = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register pressed callback to function PressedCB
		j.Pressed += PressedCB;

		// Register released callback to function ReleasedCB
		j.Released += ReleasedCB;

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
