/// @file
/// @brief Defines connection to the X server.
/// @author Fedorov Alexey
/// @date 08.08.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_SERVER_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_SERVER_HPP

#include <X11/Xlib.h>
#include <map>
#include <memory>
#include <vector>

namespace framework::system
{
class x11_server final
{
public:
    x11_server(const x11_server&) = delete;
    x11_server& operator=(const x11_server&) = delete;

    ~x11_server();

    Display* display() const;
    XID default_root_window() const;
    XID default_screen() const;

    Window active_window() const;

    Atom get_atom(const std::string& name, bool only_if_exists = true) const;

    XIM input_method() const;

    static std::shared_ptr<x11_server> connect();

private:
    x11_server();

    Display* m_display = nullptr;
    XIM m_input_method = nullptr;

    mutable std::map<std::string, Atom> m_atoms;
};

} // namespace framework::system

#endif
