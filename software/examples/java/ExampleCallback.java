import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletJoystick;

public class ExampleCallback {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;
	private static final String UID = "XYZ"; // Change to your UID

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick j = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Add pressed listener
		j.addPressedListener(new BrickletJoystick.PressedListener() {
			public void pressed() {
				System.out.println("Pressed");
			}
		});

		// Add released listener
		j.addReleasedListener(new BrickletJoystick.ReleasedListener() {
			public void released() {
				System.out.println("Released");
			}
		});

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
