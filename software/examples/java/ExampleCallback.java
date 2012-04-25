import com.tinkerforge.BrickletJoystick;
import com.tinkerforge.IPConnection;

public class ExampleCallback {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException
		BrickletJoystick joy = new BrickletJoystick(UID); // Create device object

		// Add device to IP connection
		ipcon.addDevice(joy); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection

		// Add and implement listener for pressed and released events
		joy.addListener(new BrickletJoystick.PressedListener() {
			public void pressed() {
				System.out.println("Pressed");
			}
		});
		joy.addListener(new BrickletJoystick.ReleasedListener() {
			public void released() {
				System.out.println("Released");
			}
		});

		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}
