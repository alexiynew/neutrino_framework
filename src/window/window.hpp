/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

#ifndef FRAMEWORK_WINDOW_HPP
#define FRAMEWORK_WINDOW_HPP

#include <memory>

namespace framework {

class window_implementation;

class window
{
public:
    window();
    ~window();

    // actions
    void show();
    void hide();

    /// Send the Window to the background.
    void to_back();
    /// Bring the Window to the foreground.
    void to_front();

    void request_focus();

    // setters
    void set_widht(int w);
    void set_height(int h);

    void set_max_height(int h);
    void set_max_width(int w);
    void set_min_height(int h);
    void set_min_width(int w);

    void set_title(const std::string& t);

    // getters
    int x();
    int y();
    int widht();
    int height();

    int max_height();
    int max_width();
    int min_height();
    int min_width();

    std::string title();

    bool always_on_top();
    bool full_screen();
    bool iconified();
    bool maximized();
    bool resizable();
    bool focused();

private:
    std::unique_ptr<window_implementation> m_implementation;
};
}

#endif
