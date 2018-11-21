/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

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

#ifndef FRAMEWORK_WINDOW_WINDOW_HPP
#define FRAMEWORK_WINDOW_WINDOW_HPP

#include <memory>

#include <common/types.hpp>
#include <opengl/context.hpp>

/// @details
///
/// Contains different OS related stuff.
///
/// @defgroup system_module System
/// @{

/// @defgroup window_class Window

/// @}

/// @brief Operating System related classes.
namespace framework::system
{
/// @addtogroup window_class
/// @{

/// @brief A Window class.
///
/// OpenGL-based window, abstracts all window management, input processing, and event handling.
class window
{
public:
    /// @brief Base class for OS specific realisation.
    class implementation;

    /// @brief Window size.
    struct size_t
    {
        int32 width;  ///< Window width.
        int32 height; ///< Window height.
    };

    /// @brief Window position.
    struct position_t
    {
        int32 x; ///< X coordiante.
        int32 y; ///< Y coordinate.
    };

    /// @brief Sets the formal name of the application.
    ///
    /// @param name Application name.
    static void set_application_name(const std::string& name);

    /// @brief Creates window.
    ///
    /// @param size Window size.
    /// @param title Window name.
    /// @param settings Gpaphic context settings.
    ///
    /// @thread_safety This function can be called only from main thread.
    window(size_t size, const std::string& title, opengl::context_settings settings = opengl::context_settings());

    /// @brief Destructor.
    ~window();

    window(const window&) = delete;
    window& operator=(const window&) = delete;

    /// @brief Move constructor.
    window(window&& other) noexcept;

    /// @brief Move operator.
    ///
    /// @return Reference to moved object.
    window& operator=(window&& other) noexcept;

    /// @name actions
    /// @{

    /// @brief Makes the window visible.
    void show();

    /// @brief Hides the window.
    void hide();

    /// @brief If window is visible, brings it to the front and may make it the focused.
    void focus();

    /// @brief Pull all system events and process it.
    void process_events();

    void iconify();
    void maximize();
    void switch_to_fullscreen();
    void restore();
    /// @}

    /// @name setters
    /// @{

    /// @brief Resize window.
    ///
    /// @param size New window size.
    void set_size(size_t size);

    /// @brief Move window.
    ///
    /// @brief New winodw position.
    void set_position(position_t position);

    /// @brief Sets maximum window size.
    ///
    /// @param max_size Maximum window size.
    void set_max_size(size_t max_size);

    /// @brief Sets minimum window size.
    ///
    /// @param min_size Minimum window size.
    void set_min_size(size_t min_size);

    void set_resizable(bool value);

    void set_title(const std::string& title);
    /// @}

    /// @name getters
    /// @{
    position_t position() const;
    size_t size() const;

    size_t max_size() const;
    size_t min_size() const;

    std::string title() const;

    framework::opengl::context* context() const;
    /// @}

    /// @name state
    /// @{
    bool fullscreen() const;
    bool iconified() const;
    bool maximized() const;
    bool resizable() const;
    bool visible() const;
    bool focused() const;
    /// @}

private:
    std::unique_ptr<implementation> m_implementation;
};

bool operator==(const window::size_t& lhs, const window::size_t& rhs);
bool operator!=(const window::size_t& lhs, const window::size_t& rhs);

bool operator==(const window::position_t& lhs, const window::position_t& rhs);
bool operator!=(const window::position_t& lhs, const window::position_t& rhs);

template <typename T>
T& operator<<(T& ostream, const window::size_t& size)
{
    ostream << "{" << size.width << ", " << size.height << "}";
    return ostream;
}

template <typename T>
T& operator<<(T& ostream, const window::position_t& position)
{
    ostream << "{" << position.x << ", " << position.y << "}";
    return ostream;
}

/// @}

} // namespace framework::system

#endif
