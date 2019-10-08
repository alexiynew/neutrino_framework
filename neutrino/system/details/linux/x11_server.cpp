/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <common/types.hpp>

#include <system/details/linux/x11_keyboard.hpp>
#include <system/details/linux/x11_server.hpp>

namespace
{
using ::framework::system::details::x11_server;

const char* const log_tag = "x11_server";

std::weak_ptr<x11_server>& server_instance()
{
    static std::weak_ptr<x11_server> instance;
    return instance;
}

[[noreturn]] ::framework::int32 fatal_error_handler(Display* /*unused*/)
{
    // TODO(alex): Report error
    std::terminate();
}

int error_handler(Display* display, XErrorEvent* /* unused */)
{
    auto x_server = server_instance().lock();
    if (x_server && display == x_server->display()) {
        // TODO(alex): Report error
        // constexpr ::framework::uint32 length = 8 * 1024;
        // char buffer[length];
        // XGetErrorText(display, event->error_code, buffer, length);

        //::framework::log::error(log_tag) << buffer << std::endl;
    }

    return 0;
}

void set_error_handlers()
{
    XSetIOErrorHandler(fatal_error_handler);
    XSetErrorHandler(error_handler);
}

void release_error_handlers()
{
    XSetIOErrorHandler(nullptr);
    XSetErrorHandler(nullptr);
}

} // namespace

namespace framework::system::details
{
std::shared_ptr<x11_server> x11_server::connect()
{
    if (server_instance().expired()) {
        std::shared_ptr<x11_server> temp{new x11_server()};
        server_instance() = temp;
        return temp;
    }

    return server_instance().lock();
}

x11_server::x11_server() : m_display{nullptr}
{
    m_display = XOpenDisplay(nullptr);

    if (m_display == nullptr) {
        throw std::runtime_error("Failed to open connection to X server, there is no display.");
    }

    set_error_handlers();

    m_input_method = XOpenIM(m_display, nullptr, nullptr, nullptr);

    init_key_code_map(this);
}

x11_server::~x11_server()
{
    if (m_input_method != nullptr) {
        XCloseIM(m_input_method);
    }

    if (m_display != nullptr) {
        XCloseDisplay(m_display);
    }

    release_error_handlers();
}

Display* x11_server::display() const
{
    return m_display;
}

XID x11_server::default_root_window() const
{
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
    return DefaultRootWindow(display());
}

XID x11_server::default_screen() const
{
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
    return static_cast<XID>(DefaultScreen(display()));
}

Window x11_server::active_window() const
{
    Window window;
    int state;

    XGetInputFocus(m_display, &window, &state);

    return window;
}

Atom x11_server::get_atom(const std::string& name, bool only_if_exists) const
{
    if (m_atoms.count(name) == 0) {
        Atom atom = XInternAtom(m_display, name.c_str(), only_if_exists ? True : False);
        m_atoms.insert({name, atom});
    }

    return m_atoms[name];
}

XIM x11_server::input_method() const
{
    return m_input_method;
}

} // namespace framework::system::details
