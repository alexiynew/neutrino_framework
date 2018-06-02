#include <graphic/opengl/opengl_canvas.hpp>
#include <graphic/renderer.hpp>
#include <graphic/window.hpp>
#include <unit_test/suite.hpp>

class renderer_test : public framework::unit_test::suite
{
public:
    renderer_test() : suite("renderer_test")
    {
        add_test([this]() { main_loop(); }, "main_loop");
    }

private:
    void main_loop()
    {
        using namespace framework::graphic;

        window main_window({640, 480});
        renderer gl_renderer(std::make_unique<opengl_canvas>(main_window));

        main_window.show();

        while (main_window.visible()) {
            main_window.process_events();

            gl_renderer.draw();
            gl_renderer.swap_buffers();
        }
    }
};

int main()
{
    return run_tests(renderer_test());
}
