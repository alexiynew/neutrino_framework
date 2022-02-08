#include <graphics/font.hpp>
#include <unit_test/suite.hpp>

using namespace framework::graphics;

namespace
{}

class FontTest : public framework::unit_test::Suite
{
public:
    FontTest()
        : Suite("FontTest")
    {
        add_test([this]() { render_font(); }, "render_font");
    }

private:
    void render_font()
    {
        Font font;

        TEST_ASSERT(font.load("fonts/Arial.otf") == Font::LoadResult::Success, "Should load Arial font");
    }
};

int main()
{
    return run_tests(FontTest());
}
