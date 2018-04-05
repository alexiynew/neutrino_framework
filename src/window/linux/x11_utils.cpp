#include <window/linux/x11_utils.hpp>

namespace framework {

namespace utils {

Status send_client_message(Display* display, Window window, Atom message_type, const std::vector<int64>& data)
{
    XEvent event               = {0};
    event.type                 = ClientMessage;
    event.xclient.window       = window;
    event.xclient.message_type = message_type;
    event.xclient.format       = 32;

    const int max_size = sizeof(event.xclient.data.l) / sizeof(long);

    for (size_t i = 0; i < data.size() && i < max_size; ++i) {
        event.xclient.data.l[i] = data[i];
    }

    return XSendEvent(display, DefaultRootWindow(display), False, SubstructureNotifyMask | SubstructureRedirectMask, &event);
}

} // namespace utils

} // namespace framework
