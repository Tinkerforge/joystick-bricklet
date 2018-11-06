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

    //Create listener for pressed events.
    let pressed_listener = joystick_bricklet.get_pressed_receiver();
    // Spawn thread to handle received events. This thread ends when the joystick_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in pressed_listener {
            println!("Pressed");
        }
    });

    //Create listener for released events.
    let released_listener = joystick_bricklet.get_released_receiver();
    // Spawn thread to handle received events. This thread ends when the joystick_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in released_listener {
            println!("Released");
        }
    });

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
