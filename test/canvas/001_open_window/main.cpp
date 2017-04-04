#include <canvas/canvas.hpp>
#include <unit_test/suite.hpp>

#pragma mark - test for canvas

class canvas_test : public framework::unit_test::suite
{
public:
    canvas_test()
        : suite("canvas_test")
    {
        add_test([this]() { open_canvas(); }, "open_canvas");
    }

private:
    void open_canvas()
    {
        framework::canvas canvas(640, 480);
        canvas.show();

        TEST_FAIL("Test fail.");
    }
};

int main()
{
    return run_tests(canvas_test());
}
