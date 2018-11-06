use std::{error::Error, io};

use tinkerforge::{ipconnection::IpConnection, joystick_bricklet::*};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Joystick Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let joystick_bricklet = JoystickBricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    // Get current position
    let get_position_result = joystick_bricklet.get_position().recv()?;

    println!("Position [X]: {}", get_position_result.x);
    println!("Position [Y]: {}", get_position_result.y);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
