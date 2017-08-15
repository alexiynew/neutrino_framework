/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

#ifndef FRAMEWORK_WINDOW_WINDOW_HPP
#define FRAMEWORK_WINDOW_WINDOW_HPP

#include <common/common_types.hpp>
#include <memory>

namespace framework {

class window_implementation;

class window
{
public:
    window();
    ~window();

    window(const window&) = delete;
    window& operator=(const window&) = delete;

    /// @name actions
    /// @{
    void show();
    void hide();
    void focus();
    void process_events();

    void minimize();
    void maximize();
    void to_full_screen();
    void restore();
    /// @}

    /// @name setters
    /// @{
    void set_size(int32 width, int32 height);
    void set_position(int32 x, int32 y);

    void set_max_size(int32 width, int32 height);
    void set_min_size(int32 width, int32 height);

    void set_title(const std::string& title);
    /// @}

    /// @name getters
    /// @{
    int x();
    int y();
    int width();
    int height();

    int max_height();
    int max_width();
    int min_height();
    int min_width();

    std::string title();

    bool full_screen();
    bool minimized();
    bool maximized();
    bool resizable();
    bool visible();
    bool focused();
    /// @}

private:
    std::unique_ptr<window_implementation> m_implementation;
};
}

#endif
