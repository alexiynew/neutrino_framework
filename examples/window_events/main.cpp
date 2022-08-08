#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include <log/log.hpp>
#include <log/stream_logger.hpp>
#include <system/window.hpp>

#include "event_handler.hpp"
#include "view.hpp"

int main()
{
    using namespace framework;
    using framework::log::StreamLogger;
    using framework::system::Window;

    framework::log::set_logger(std::make_unique<StreamLogger>(std::cout));

    Window w("Window Events", {800, 600});

    EventHandler event_handler(w);
    View view(w);

    log::info("Main") << "RUN";
    w.show();
    while (!w.should_close()) {
        event_handler.update();
        view.render(event_handler.data_context());
    }
}
