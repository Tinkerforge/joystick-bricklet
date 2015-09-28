import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletJoystick;

public class ExampleFindBorders {
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

		// Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
		j.setDebouncePeriod(200);

		// Add position reached listener
		j.addPositionReachedListener(new BrickletJoystick.PositionReachedListener() {
			public void positionReached(short x, short y) {
				if(y == 100) {
					System.out.println("Top");
				} else if(y == -100) {
					System.out.println("Bottom");
				}

				if(x == 100) {
					System.out.println("Right");
				} else if(x == -100) {
					System.out.println("Left");
				}

				System.out.println("");
			}
		});

		// Configure threshold for position "outside of -99, -99 to 99, 99"
		j.setPositionCallbackThreshold('o', (short)(-99), (short)99, (short)(-99), (short)99);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
