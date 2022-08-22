#ifndef WINDOW_EVENTS_VIEW_HPP
#define WINDOW_EVENTS_VIEW_HPP

#include <graphics/font.hpp>
#include <graphics/renderer.hpp>
#include <system/window.hpp>

class DataContext;

class View
{
public:
    View(framework::system::Window& window);
    ~View();

    void render(const DataContext& context);

    void on_resize(framework::Size size);

private:
    framework::graphics::Renderer m_renderer;
    framework::graphics::Font m_font;
    framework::graphics::Renderer::ResourceId m_shader_id = 1;
};

#endif
