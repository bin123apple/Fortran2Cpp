mod input_handler {
    pub struct InputHandler {}

    impl InputHandler {
        pub fn new() -> Self {
            Self {}
        }

        pub fn handle_input(&self) {
            println!("Handling general input...");
        }
    }
}

mod keyboard {
    pub struct Keyboard {}

    impl Keyboard {
        pub fn new() -> Self {
            Self {}
        }

        pub fn handle_key_press(&self) {
            println!("Handling keyboard input...");
        }
    }
}

mod mouse {
    pub struct Mouse {}

    impl Mouse {
        pub fn new() -> Self {
            Self {}
        }

        pub fn handle_mouse_move(&self) {
            println!("Handling mouse movement...");
        }
    }
}

mod gamepad {
    pub struct Gamepad {}

    impl Gamepad {
        pub fn new() -> Self {
            Self {}
        }

        pub fn handle_button_press(&self) {
            println!("Handling gamepad button press...");
        }
    }
}

mod input {
    pub use crate::input_handler::InputHandler;
    pub use crate::keyboard::Keyboard;
    pub use crate::mouse::Mouse;
    pub use crate::gamepad::Gamepad;
}

fn main() {
    let handler = input::InputHandler::new();
    let keyboard = input::Keyboard::new();
    let mouse = input::Mouse::new();
    let gamepad = input::Gamepad::new();

    handler.handle_input();
    keyboard.handle_key_press();
    mouse.handle_mouse_move();
    gamepad.handle_button_press();

    println!("All inputs handled.");
}