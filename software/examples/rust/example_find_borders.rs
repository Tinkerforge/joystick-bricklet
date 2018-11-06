use std::{error::Error, io, thread};
use tinkerforge::{ipconnection::IpConnection, joystick_bricklet::*};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Joystick Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let joystick_bricklet = JoystickBricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    // Get threshold listeners with a debounce time of 0.2 seconds (200ms)
    joystick_bricklet.set_debounce_period(200);

    //Create listener for position reached events.
    let position_reached_listener = joystick_bricklet.get_position_reached_receiver();
    // Spawn thread to handle received events. This thread ends when the joystick_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in position_reached_listener {
            if event.y == 100 {
                println!("Top");
            } else if event.y == -100 {
                println!("Bottom");
            } else if event.x == 100 {
                println!("Right");
            } else if event.x == -100 {
                println!("Left");
            }
            println!();
        }
    });

    // Configure threshold for position "outside of -99, -99 to 99, 99"
    joystick_bricklet.set_position_callback_threshold('o', -99, 99, -99, 99);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
