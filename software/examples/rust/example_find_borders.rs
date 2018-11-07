use std::{error::Error, io, thread};
use tinkerforge::{ip_connection::IpConnection, joystick_bricklet::*};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Joystick Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let j = JoystickBricklet::new(UID, &ipcon); // Create device object

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd
                                          // Don't use device before ipcon is connected

    // Get threshold receivers with a debounce time of 0.2 seconds (200ms)
    j.set_debounce_period(200);

    let position_reached_receiver = j.get_position_reached_callback_receiver();
    
    // Spawn thread to handle received events.
    // This thread ends when the `j`
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for position_reached in position_reached_receiver {
            if position_reached.y == 100 {
                println!("Top");
            } else if position_reached.y == -100 {
                println!("Bottom");
            } else if position_reached.x == 100 {
                println!("Right");
            } else if position_reached.x == -100 {
                println!("Left");
            }
            println!();
        }
    });

    // Configure threshold for position "outside of -99, -99 to 99, 99"
    j.set_position_callback_threshold('o', -99, 99, -99, 99);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
