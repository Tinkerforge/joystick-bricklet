import com.tinkerforge.BrickletJoystick;
import com.tinkerforge.IPConnection;

public class ExampleCallback {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;
	private static final String UID = "ABC"; // Change to your UID

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick joy = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Add and implement listener for pressed and released events
		joy.addPressedListener(new BrickletJoystick.PressedListener() {
			public void pressed() {
				System.out.println("Pressed");
			}
		});
		joy.addReleasedListener(new BrickletJoystick.ReleasedListener() {
			public void released() {
				System.out.println("Released");
			}
		});

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
