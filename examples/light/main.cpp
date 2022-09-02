#include <chrono>
#include <thread>

#include <common/utils.hpp>
#include <common/version.hpp>
#include <game_core/camera.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <system/application.hpp>
#include <system/window.hpp>

namespace
{

using namespace framework;
using namespace framework::graphics;
using namespace framework::math;
using namespace framework::system;
using namespace framework::game_core;

namespace cube
{

const std::string vertex_shader   = "./shaders/phong_light.vert";
const std::string fragment_shader = "./shaders/phong_light.frag";

const Mesh::VertexData vertices = {
// clang-format off
        // front
        {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
        // back
        {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
        // left
        {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5}, {-0.5, 0.5, 0.5}, {-0.5, 0.5, -0.5},
        // right
        {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, 0.5, -0.5},
        // top
        {0.5, 0.5, 0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}, {-0.5, 0.5, 0.5},
        // bottom
        {0.5, -0.5, 0.5}, {0.5, -0.5, -0.5}, {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5},
// clang-format on
};

const Mesh::VertexData normals = {
// clang-format off
        // front
        {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0},
        // back
        {0.0, 0.0, -1.0}, {0.0, 0.0, -1.0}, {0.0, 0.0, -1.0}, {0.0, 0.0, -1.0},
        // left
        {-1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0}, {-1.0, 0.0, 0.0},
        // right
        {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
        // top
        {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 
        // bottom
        {0.0, -1.0, 0.0}, {0.0, -1.0, 0.0}, {0.0, -1.0, 0.0}, {0.0, -1.0, 0.0},
// clang-format on
};

const Mesh::ColorData colors = {
// clang-format off
        // front
        {0.7f, 0.1f, 0.1f}, {0.8f, 0.2f, 0.1f}, {0.9f, 0.3f, 0.1f}, {1.0f, 0.4f, 0.1f},
        // back
        {0.1f, 0.7f, 0.1f}, {0.1f, 0.8f, 0.2f}, {0.1f, 0.9f, 0.3f}, {0.1f, 1.0f, 0.4f},
        // left
        {0.1f, 0.1f, 0.7f}, {0.1f, 0.2f, 0.8f}, {0.1f, 0.3f, 0.9f}, {0.1f, 0.4f, 1.0f},
        // right
        {0.7f, 1.0f, 0.1f}, {0.8f, 0.9f, 0.1f}, {0.9f, 0.8f, 0.1f}, {1.0f, 0.7f, 0.1f},
        // top
        {0.1f, 0.7f, 1.0f}, {0.1f, 0.8f, 0.9f}, {0.1f, 0.9f, 0.8f}, {0.1f, 1.0f, 0.7f},
        // bottom
        {1.0f, 0.1f, 0.7f}, {0.9f, 0.2f, 0.8f}, {0.8f, 0.3f, 0.9f}, {0.7f, 0.4f, 1.0f},
// clang-format on
};

Mesh::IndicesData indices = {
// clang-format off
        // front
        0, 1, 2, 0, 2, 3,
        // back
        4, 7, 6, 4, 6, 5,
        // felt
        8, 9, 10, 8, 10 ,11,
        // right
        12, 15, 14, 12, 14, 13,
        // top
        16, 17, 18, 16, 18, 19,
        // bottom
        20, 23, 22, 20, 22, 21,
// clang-format on
};

} // namespace cube

namespace light_cube
{

const std::string vertex_shader   = "./shaders/white_light_lamp.vert";
const std::string fragment_shader = "./shaders/white_light_lamp.frag";

const Mesh::VertexData vertices = {
// clang-format off
        // front
        {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
        // back
        {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
        // left
        {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5}, {-0.5, 0.5, 0.5}, {-0.5, 0.5, -0.5},
        // right
        {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, 0.5, -0.5},
        // top
        {0.5, 0.5, 0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}, {-0.5, 0.5, 0.5},
        // bottom
        {0.5, -0.5, 0.5}, {0.5, -0.5, -0.5}, {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5},
// clang-format on
};

Mesh::IndicesData indices = {
// clang-format off
        // front
        0, 1, 2, 0, 2, 3,
        // back
        4, 7, 6, 4, 6, 5,
        // felt
        8, 9, 10, 8, 10 ,11,
        // right
        12, 15, 14, 12, 14, 13,
        // top
        16, 17, 18, 16, 18, 19,
        // bottom
        20, 23, 22, 20, 22, 21,
// clang-format on
};

} // namespace light_cube

using MeshPtr   = std::unique_ptr<Mesh>;
using ShaderPtr = std::unique_ptr<Shader>;

struct Material
{
    Vector3f ambient  = {1.0f, 1.0f, 1.0f};
    Vector3f diffuse  = {1.0f, 1.0f, 1.0f};
    Vector3f specular = {1.0f, 1.0f, 1.0f};
    float shininess   = 1.0f;
};

struct Object
{
    MeshPtr mesh;
    ShaderPtr shader;
    Vector3f position;
    Material material;
};

Object create_cube()
{
    MeshPtr mesh = std::make_unique<Mesh>();
    mesh->set_vertices(cube::vertices);
    mesh->set_normals(cube::normals);
    // mesh->set_colors(cube::colors);
    mesh->add_submesh(cube::indices);

    ShaderPtr shader = std::make_unique<Shader>();
    shader->load_vertex_source(cube::vertex_shader);
    shader->load_fragment_source(cube::fragment_shader);

    Material material;
    material.ambient   = {1.0f, 0.5f, 0.31f};
    material.diffuse   = {1.0f, 0.5f, 0.31f};
    material.specular  = {0.5f, 0.5f, 0.5f};
    material.shininess = {32.0f};

    return {std::move(mesh), std::move(shader), {0, 0, 0}, material};
}

Object create_light_cube()
{
    MeshPtr mesh = std::make_unique<Mesh>();
    mesh->set_vertices(light_cube::vertices);
    mesh->add_submesh(light_cube::indices);

    ShaderPtr shader = std::make_unique<Shader>();
    shader->load_vertex_source(light_cube::vertex_shader);
    shader->load_fragment_source(light_cube::fragment_shader);

    Material material;

    return {std::move(mesh), std::move(shader), {0, 0, 0}, material};
}

} // namespace

int main()
{
    static constexpr std::chrono::milliseconds delta_time(16);

    Application::set_name("GL light");

    Window main_window("GL light", {800, 640});
    Renderer renderer(main_window.context());

    renderer.set_clear_color(Color(0x202020FFu));

    Camera camera({0.0f, 0.0f, 10.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f});
    camera.set_speed(10);

    renderer.set_uniform("viewMatrix", camera.get_view());

    main_window.set_cursor_visible(false);

    renderer.set_uniform("light.ambient", Vector3f{0.2f, 0.2f, 0.2f});
    renderer.set_uniform("light.diffuse", Vector3f{0.5f, 0.5f, 0.5f});
    renderer.set_uniform("light.specular", Vector3f{1.0f, 1.0f, 1.0f});

    main_window.set_on_resize_callback([&renderer](Size size) {
        const float aspect = static_cast<float>(size.width) / static_cast<float>(size.height);
        renderer.set_uniform("projectionMatrix", perspective(half_pi<float>, aspect, 0.001f, 100.0f));
    });

    main_window.set_on_focus_callback([&main_window]() { main_window.grab_cursor(); });
    main_window.set_on_lost_focus_callback([&main_window]() { main_window.release_cursor(); });

    main_window.set_on_key_down_callback([&camera](KeyCode key, Modifiers) {
        switch (key) {
            case KeyCode::key_w: camera.set_action(Camera::ActionState::moveForward, true); break;
            case KeyCode::key_s: camera.set_action(Camera::ActionState::moveBackward, true); break;
            case KeyCode::key_a: camera.set_action(Camera::ActionState::moveLeft, true); break;
            case KeyCode::key_d: camera.set_action(Camera::ActionState::moveRight, true); break;
            case KeyCode::key_q: camera.set_action(Camera::ActionState::moveUp, true); break;
            case KeyCode::key_e: camera.set_action(Camera::ActionState::moveDown, true); break;
            default: break;
        }
    });

    main_window.set_on_key_up_callback([&camera](KeyCode key, Modifiers) {
        switch (key) {
            case KeyCode::key_w: camera.set_action(Camera::ActionState::moveForward, false); break;
            case KeyCode::key_s: camera.set_action(Camera::ActionState::moveBackward, false); break;
            case KeyCode::key_a: camera.set_action(Camera::ActionState::moveLeft, false); break;
            case KeyCode::key_d: camera.set_action(Camera::ActionState::moveRight, false); break;
            case KeyCode::key_q: camera.set_action(Camera::ActionState::moveUp, false); break;
            case KeyCode::key_e: camera.set_action(Camera::ActionState::moveDown, false); break;
            default: break;
        }
    });

    CursorPosition last_mouse_pos{main_window.size().width / 2, main_window.size().height / 2};
    main_window.set_on_mouse_move_callback([&camera, &last_mouse_pos](CursorPosition pos) {
        int dx = pos.x - last_mouse_pos.x;
        int dy = last_mouse_pos.y - pos.y;

        camera.set_offset({dx, dy});
        last_mouse_pos = pos;
    });

    Object cube       = create_cube();
    Object light_cube = create_light_cube();

    cube.mesh->clear();
    cube.shader->clear();

    light_cube.mesh->clear();
    light_cube.shader->clear();

    main_window.show();

    light_cube.position = {7.0f, 0.0f, 0.0f};

    Matrix4f cube_transform;

    cube_transform = scale(cube_transform, Vector3f(5));

    while (!main_window.should_close()) {
        main_window.process_events();

        camera.update(delta_time);
        renderer.set_uniform("viewMatrix", camera.get_view());

        cube_transform = translate(cube_transform, cube.position);
        cube_transform = rotate(cube_transform, normalize(Vector3f(0, 1, 0)), radians(0.5));

        Matrix4f light_transform;
        light_transform = translate(light_transform, light_cube.position);
        light_transform = scale(light_transform, Vector3f(0.2f, 0.2f, 0.2f));

        // renderer.render(*light_cube.mesh, *light_cube.shader, {Uniform{"modelMatrix", light_transform}});

        // Matrix3f normal_matrix = Matrix3f(transpose(inverse(camera.get_view() * cube_transform)));
        //         renderer.render(*cube.mesh,
        //                         *cube.shader,
        //                         {{"modelMatrix", cube_transform},
        //                          {"normalMatrix", normal_matrix},
        //                          {"lightPos", light_cube.position},
        //                          {"lightMatrix", light_transform},
        //                          {"material.ambient", cube.material.ambient},
        //                          {"material.diffuse", cube.material.diffuse},
        //                          {"material.specular", cube.material.specular},
        //                          {"material.shininess", cube.material.shininess}});
        //
        renderer.display();

        std::this_thread::sleep_for(delta_time);
    }
}
