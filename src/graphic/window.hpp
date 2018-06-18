/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

#ifndef FRAMEWORK_GRAPHIC_WINDOW_HPP
#define FRAMEWORK_GRAPHIC_WINDOW_HPP

#include <memory>

#include <common/types.hpp>

namespace framework
{
namespace graphic
{
class window
{
public:
    class implementation;

    struct size_t
    {
        int32 width;
        int32 height;
    };

    struct position_t
    {
        int32 x;
        int32 y;
    };

    window(size_t size, const std::string& title = "");
    ~window();

    window(const window&) = delete;
    window& operator=(const window&) = delete;

    window(window&& other);
    window& operator=(window&& other);

    /// @name actions
    /// @{
    void show();
    void hide();
    void focus();
    void process_events();

    void iconify();
    void maximize();
    void switch_to_fullscreen();
    void restore();
    /// @}

    /// @name setters
    /// @{
    void set_size(size_t size);
    void set_position(position_t position);

    void set_max_size(size_t max_size);
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

    uint64 native_handler() const;
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

} // namespace graphic

} // namespace framework

#endif
