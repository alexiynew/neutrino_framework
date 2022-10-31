# System

This module consists of classes and functions responsible for operating system interactions:
Window creation, handling window system events, and user input.

``` cpp
#include <system/window.hpp>

int main()
{
    using namespace neutrino;
    using namespace neutrino::system;

    // Create window
    Window window("Example window", Size(640, 480));

    // Setup callbacks
    window.on_show.connect([](const Window&) { 
        // Do something when window shown
    });

    window.on_key_down.connect([](const Window&, system::KeyCode key, system::Modifiers state) {
        // Process user input
    });

    // Show window on screen
    window.show();

    // Main loop
    while (!window.should_close()) {
        // Pull system events and call window callbacs
        window.process_events();

        ...
    }

    return 0;
}

```
