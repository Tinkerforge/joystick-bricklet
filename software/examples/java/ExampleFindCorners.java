import com.tinkerforge.BrickletJoystick;
import com.tinkerforge.IPConnection;

public class ExampleFindCorners {
	private static final String host = "localhost";
	private static final int port = 4223;
	private static final String UID = "ABC"; // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletJoystick joy = new BrickletJoystick(UID, ipcon); // Create device object

		ipcon.connect(host, port); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
		joy.setDebouncePeriod(200);

		// Configure threshold for "x and y value outside of -99 and 99"
		joy.setPositionCallbackThreshold('o', (short)-99, (short)99, (short)-99, (short)99);

		// Add and implement position reached listener 
		// (called if x and y value outside of -99 and 99)
		joy.addPositionReachedListener(new BrickletJoystick.PositionReachedListener() {
			public void positionReached(short x, short y) {
				if(x == 100 && y == 100) {
					System.out.println("Top Right");
				} else if(x == -100 && y == 100) {
					System.out.println("Top Left");
				} else if(x == -100 && y == -100) {
					System.out.println("Bottom Left");
				} else if(x == 100 && y == -100) {
					System.out.println("Bottom Right");
				} else {
					// This can't happen, the threshold is configured to: "outside of -99, 99"
					System.out.println("Error");
				}
			}
		});

		System.console().readLine("Press key to exit\n");
	}
}
