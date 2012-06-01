import com.tinkerforge.BrickletJoystick;
import com.tinkerforge.IPConnection;

public class ExampleFindCorners {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException

		BrickletJoystick joy = new BrickletJoystick(UID); // Create device object

		// Add device to ip connection
		ipcon.addDevice(joy); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection
		

		// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
		joy.setDebouncePeriod(200);

		// Configure threshold for "x and y value outside of -99 and 99"
		joy.setPositionCallbackThreshold('o', (short)-99, (short)99, (short)-99, (short)99);

		// Add and implement position reached listener 
		// (called if x and y value outside of -99 and 99)
		joy.addListener(new BrickletJoystick.PositionReachedListener() {
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
		
		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}