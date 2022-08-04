#ifndef WINDOW_EVENTS_VIEW_HPP
#define WINDOW_EVENTS_VIEW_HPP

#include <graphics/font.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <system/window.hpp>

class DataContext;

class View
{
public:
    View(framework::system::Window& window);
    ~View();

    void render(const DataContext& context);

private:
    framework::system::Window& m_window;

    framework::graphics::Renderer m_renderer;
    framework::graphics::Font m_font;
    framework::graphics::Shader m_shader;
};

#endif