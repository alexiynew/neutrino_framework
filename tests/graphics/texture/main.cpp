#include <graphics/image.hpp>
#include <graphics/texture.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::graphics;

class TextureTest : public unit_test::Suite
{
public:
    TextureTest()
        : Suite("TextureTest")
    {
        add_test([this]() { texture_data(); }, "texture_data");
        add_test([this]() { texture_copy(); }, "texture_copy");
        add_test([this]() { texture_move(); }, "texture_move");
    }

private:
    void texture_data()
    {
        std::vector<Color> data = {Color{0xFF0088FF}, Color{0xFF0088FF}, Color{0xFF0088FF}, Color{0xFF0088FF}};

        Image img(data, 2, 2);

        Texture texture;

        texture.set_image(img);
        texture.set_wrap_s_parameter(Texture::Wrap::clamp_to_border);
        texture.set_wrap_t_parameter(Texture::Wrap::clamp_to_edge);
        texture.set_border_color(Color{0xFF0088FFu});
        texture.set_min_filter(Texture::MinFilter::nearest_mipmap_nearest);
        texture.set_mag_filter(Texture::MagFilter::nearest);

        TEST_ASSERT(texture.image() == img, "Wrong image.");
        TEST_ASSERT(texture.wrap_s_parameter() == Texture::Wrap::clamp_to_border, "Wrong wrap s parametr.");
        TEST_ASSERT(texture.wrap_t_parameter() == Texture::Wrap::clamp_to_edge, "Wrong wrap t parametr.");
        TEST_ASSERT(texture.border_color() == Color{0xFF0088FFu}, "Wrong border color.");
        TEST_ASSERT(texture.min_filter() == Texture::MinFilter::nearest_mipmap_nearest, "Wrong min filter.");
        TEST_ASSERT(texture.mag_filter() == Texture::MagFilter::nearest, "Wrong mag filter.");

        texture.clear();

        TEST_ASSERT(texture.image() == Image{}, "Wrong image.");
        TEST_ASSERT(texture.wrap_s_parameter() == Texture::Wrap::repeat, "Wrong wrap s parametr.");
        TEST_ASSERT(texture.wrap_t_parameter() == Texture::Wrap::repeat, "Wrong wrap t parametr.");
        TEST_ASSERT(texture.border_color() == Color{0x000000FFu}, "Wrong border color.");
        TEST_ASSERT(texture.min_filter() == Texture::MinFilter::nearest_mipmap_linear, "Wrong min filter.");
        TEST_ASSERT(texture.mag_filter() == Texture::MagFilter::linear, "Wrong mag filter.");
    }

    void texture_copy()
    {
        std::vector<Color> data = {Color{0xFF0088FF}, Color{0xFF0088FF}, Color{0xFF0088FF}, Color{0xFF0088FF}};

        Image img(data, 2, 2);

        Texture texture;

        texture.set_image(img);
        texture.set_wrap_s_parameter(Texture::Wrap::clamp_to_border);
        texture.set_wrap_t_parameter(Texture::Wrap::clamp_to_edge);
        texture.set_border_color(Color{0xFF0088FFu});
        texture.set_min_filter(Texture::MinFilter::nearest_mipmap_nearest);
        texture.set_mag_filter(Texture::MagFilter::nearest);

        Texture texture1;
        texture1 = texture;

        texture.clear();

        TEST_ASSERT(texture1.wrap_s_parameter() == Texture::Wrap::clamp_to_border, "Wrong wrap s parametr.");
        TEST_ASSERT(texture1.wrap_t_parameter() == Texture::Wrap::clamp_to_edge, "Wrong wrap t parametr.");
        TEST_ASSERT(texture1.border_color() == Color{0xFF0088FFu}, "Wrong border color.");
        TEST_ASSERT(texture1.min_filter() == Texture::MinFilter::nearest_mipmap_nearest, "Wrong min filter.");
        TEST_ASSERT(texture1.mag_filter() == Texture::MagFilter::nearest, "Wrong mag filter.");
    }

    void texture_move()
    {
        std::vector<Color> data = {Color{0xFF0088FF}, Color{0xFF0088FF}, Color{0xFF0088FF}, Color{0xFF0088FF}};

        Image img(data, 2, 2);

        Texture texture;

        texture.set_image(img);
        texture.set_wrap_s_parameter(Texture::Wrap::clamp_to_border);
        texture.set_wrap_t_parameter(Texture::Wrap::clamp_to_edge);
        texture.set_border_color(Color{0xFF0088FFu});
        texture.set_min_filter(Texture::MinFilter::nearest_mipmap_nearest);
        texture.set_mag_filter(Texture::MagFilter::nearest);

        Texture texture1;
        texture1 = std::move(texture);

        TEST_ASSERT(texture1.image() == img, "Wrong image.");
        TEST_ASSERT(texture1.wrap_s_parameter() == Texture::Wrap::clamp_to_border, "Wrong wrap s parametr.");
        TEST_ASSERT(texture1.wrap_t_parameter() == Texture::Wrap::clamp_to_edge, "Wrong wrap t parametr.");
        TEST_ASSERT(texture1.border_color() == Color{0xFF0088FFu}, "Wrong border color.");
        TEST_ASSERT(texture1.min_filter() == Texture::MinFilter::nearest_mipmap_nearest, "Wrong min filter.");
        TEST_ASSERT(texture1.mag_filter() == Texture::MagFilter::nearest, "Wrong mag filter.");

        TEST_ASSERT(texture.image() == Image{}, "Wrong image.");
        TEST_ASSERT(texture.wrap_s_parameter() == Texture::Wrap::repeat, "Wrong wrap s parametr.");
        TEST_ASSERT(texture.wrap_t_parameter() == Texture::Wrap::repeat, "Wrong wrap t parametr.");
        TEST_ASSERT(texture.border_color() == Color{0x000000FFu}, "Wrong border color.");
        TEST_ASSERT(texture.min_filter() == Texture::MinFilter::nearest_mipmap_linear, "Wrong min filter.");
        TEST_ASSERT(texture.mag_filter() == Texture::MagFilter::linear, "Wrong mag filter.");
    }
};

int main()
{
    return run_tests(TextureTest());
}
