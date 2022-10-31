#ifndef WINDOW_EVENTS_VIEW_HPP
#define WINDOW_EVENTS_VIEW_HPP

#include <graphics/font.hpp>
#include <graphics/renderer.hpp>
#include <math/math.hpp>
#include <system/window.hpp>

class DataContext;

class View
{
public:
    View(neutrino::system::Window& window);
    ~View();

    void render(const DataContext& data);

    void on_resize(neutrino::Size size);

private:
    enum TextName : neutrino::graphics::Renderer::ResourceId
    {
        WindowTitleText = 0,
        WindowSizeText,
        WindowPositionText,
        WindowStateText,
        WindowResizableText,
        WindowHasInputFocusText,

        CursorTitleText,
        CursorPositionText,
        CursorCapturedText,
        CursorVisibleText,
        MouseHoverText,
        CursorMarker,

        CatText,
        CatText1,

        LogTextBegin,
    };

    void render_window_state(const DataContext& data);
    void render_cursor_state(const DataContext& data);
    void render_log(const DataContext& data);
    void render_cat(const DataContext& data);
    void render_cursor_marker(const DataContext& data);

    void render_normal_text(TextName id, const std::string& text, neutrino::math::Vector3f position);

    neutrino::graphics::Renderer m_renderer;
    neutrino::graphics::Font m_font;
    neutrino::graphics::Renderer::ResourceId m_shader_id = 1;
};

#endif
