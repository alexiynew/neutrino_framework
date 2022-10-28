#include <graphics/shader.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::graphics;

namespace
{

const std::string vertex_shader =
"#version 330 core\n\
layout(location = 0) in vec3 position;\n\
layout(location = 3) in vec4 color;\n\
\n\
uniform mat4 modelMatrix;\n\
uniform mat4 viewMatrix;\n\
uniform mat4 projectionMatrix;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);\n\
    fragColor = color / 256.0;\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
in vec4 fragColor;\n\
out vec4 color;\n\
void main(){\n\
    color = fragColor;\n\
}";

} // namespace

class ShaderTest : public framework::unit_test::Suite
{
public:
    ShaderTest()
        : Suite("ShaderTest")
    {
        add_test([this]() { shader_data(); }, "shader_data");
        add_test([this]() { shader_copy(); }, "shader_copy");
        add_test([this]() { shader_move(); }, "shader_move");
    }

private:
    void shader_data()
    {
        Shader shader;

        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);

        TEST_ASSERT(shader.vertex_source() == vertex_shader, "Wrong vertex source.");
        TEST_ASSERT(shader.fragment_source() == fragment_shader, "Wrong fragment source.");

        shader.clear();

        TEST_ASSERT(shader.vertex_source().empty(), "Wrong vertex source.");
        TEST_ASSERT(shader.fragment_source().empty(), "Wrong fragment source.");
    }

    void shader_copy()
    {
        Shader shader;

        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);

        TEST_ASSERT(shader.vertex_source() == vertex_shader, "Wrong vertex source.");
        TEST_ASSERT(shader.fragment_source() == fragment_shader, "Wrong fragment source.");

        Shader shader1;
        shader1 = shader;

        shader.clear();

        TEST_ASSERT(shader1.vertex_source() == vertex_shader, "Wrong vertex source.");
        TEST_ASSERT(shader1.fragment_source() == fragment_shader, "Wrong fragment source.");
    }

    void shader_move()
    {
        Shader shader;

        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);

        TEST_ASSERT(shader.vertex_source() == vertex_shader, "Wrong vertex source.");
        TEST_ASSERT(shader.fragment_source() == fragment_shader, "Wrong fragment source.");

        Shader shader1;
        shader1 = std::move(shader);

        TEST_ASSERT(shader1.vertex_source() == vertex_shader, "Wrong vertex source.");
        TEST_ASSERT(shader1.fragment_source() == fragment_shader, "Wrong fragment source.");

        TEST_ASSERT(shader.vertex_source().empty(), "Wrong vertex source.");
        TEST_ASSERT(shader.fragment_source().empty(), "Wrong fragment source.");
    }
};

int main()
{
    return run_tests(ShaderTest());
}
