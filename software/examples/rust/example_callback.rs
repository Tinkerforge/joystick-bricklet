use std::{error::Error, io, thread};
use tinkerforge::{ip_connection::IpConnection, joystick_bricklet::*};

const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Joystick Bricklet.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let j = JoystickBricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
                                          // Don't use device before ipcon is connected.

    // Create receiver for pressed events.
    let pressed_receiver = j.get_pressed_receiver();

    // Spawn thread to handle received events. This thread ends when the `j` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for pressed in pressed_receiver {
            println!("Pressed");
        }
    });

    // Create receiver for released events.
    let released_receiver = j.get_released_receiver();

    // Spawn thread to handle received events. This thread ends when the `j` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for released in released_receiver {
            println!("Released");
        }
    });

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
