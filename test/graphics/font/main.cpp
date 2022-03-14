#include <chrono>
#include <thread>

#include <common/size.hpp>
#include <graphics/font.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <math/math.hpp>
#include <system/window.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::graphics;
using namespace framework::math;
using namespace framework::system;

namespace
{

const std::string vertex_shader =
"#version 330 core\n\
layout(location = 0) in vec3 position;\n\
layout(location = 3) in vec4 color;\n\
\n\
uniform mat4 projectionMatrix;\n\
uniform mat4 modelMatrix;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * modelMatrix * vec4(position, 1.0);\n\
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

struct TextObject
{
    TextObject(Mesh m, Vector3f p)
        : mesh(std::move(m))
        , position(p)
    {}

    Mesh mesh;
    math::Vector3f position;
};

constexpr float width       = 25.0f;
constexpr float height      = 25.0f;
constexpr float line_offset = 1.2f;

} // namespace

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
        Window::set_application_name(name());

        Window window(name(), {800, 640});
        Renderer renderer(window);

        renderer.set_clear_color(Color(0x202020FFu));
        renderer.set_polygon_mode(Renderer::PolygonMode::line);

        window.on_resize.connect([&renderer](const Window&, Size) {
            renderer.set_uniform("projectionMatrix", ortho2d(0.0f, width, 0.0f, height));
        });

        Font font;
        auto result = font.load("fonts/UbuntuMono-Regular.ttf");
        TEST_ASSERT(result == Font::LoadResult::Success,
                    "Can't load font, error: " + std::to_string(static_cast<int>(result)));

        std::vector<TextObject> objects;

        // clang-format off
        const std::vector<std::string> strings = {
        "абвгдеёжзийклмнопрстуфхцчшщъьыэюя",
        "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЫЭЮЯ",
        "abcdefghijklmnopqrstuvwzxy",
        "ABCDEFGHIJKLMNOPQRSTUVWZXY",
        "!@#$%^&*()_+=-{}|[]\\;':\",./<>?`~",
        "The quick brown fox jumps over the lazy dog.",
        //"Chruu, a kwik di kwik brong fox a jomp huova di liezi daag de, yu no siit?",
        // "An ḃfuil do ċroí ag bualaḋ ó ḟaitíos an ġrá a ṁeall lena ṗóg éada ó ṡlí do leasa ṫú?" "D'ḟuascail Íosa Úrṁac na hÓiġe Beannaiṫe pór Éava agus Áḋaiṁ.",
        // "Pa's wĳze lynx bezag vroom het fikse aquaduct.",
        // "Falsches Üben von Xylophonmusik quält jeden größeren Zwerg.)",
        // "Im finſteren Jagdſchloß am offenen Felsquellwaſſer patzte der affig-flatterhafte kauzig-höf‌liche Bäcker über ſeinem verſifften kniffligen C-Xylophon.",
        // "Blåbærsyltetøy",
        // "Flygande bäckasiner söka strax hwila på mjuka tuvor.",
        // "Sævör grét áðan því úlpan var ónýt.",
        // "Törkylempijävongahdus",
        // "Albert osti fagotin ja töräytti puhkuvan melodian.",
        // "On sangen hauskaa, että polkupyörä on maanteiden jokapäiväinen ilmiö.",
        // "Pchnąć w tę łódź jeża lub osiem skrzyń fig.",
        // "Příliš žluťoučký kůň úpěl ďábelské ódy.",
        // "Starý kôň na hŕbe kníh žuje tíško povädnuté ruže, na stĺpe sa ďateľ učí kvákať novú ódu o živote.",
        // "Šerif bo za domačo vajo spet kuhal žgance.",
        // "ξεσκεπάζω την ψυχοφθόρα βδελυγμία",
        // "ξεσκεπάζω τὴν ψυχοφθόρα βδελυγμία",
        // "Съешь же ещё этих мягких французских булок да выпей чаю.",
        // "В чащах юга жил-был цитрус? Да, но фальшивый экземпляр! ёъ.",
        // "Жълтата дюля беше щастлива, че пухът, който цъфна, замръзна като гьон.",
        // "Vuol Ruoŧa geđggiid leat máŋga luosa ja čuovžža.",
        // "Árvíztűrő tükörfúrógép.",
        // "El pingüino Wenceslao hizo kilómetros bajo exhaustiva lluvia y frío, añoraba a su querido cachorro.",
        // "Volé cigüeña que jamás cruzó París, exhibe flor de kiwi y atún.",
        // "O próximo vôo à noite sobre o Atlântico, põe freqüentemente o único médico.",
        // "Les naïfs ægithales hâtifs pondant à Noël où il gèle sont sûrs d'être déçus en voyant leurs drôles d'œufs abîmés.",
        // "Eĥoŝanĝo ĉiuĵaŭde",
        // "Laŭ Ludoviko Zamenhof bongustas freŝa ĉeĥa manĝaĵo kun spicoj.",
        // "זה כיף סתם לשמוע איך תנצח קרפד עץ טוב בגן.",
        // "いろはにほへど　ちりぬるを わがよたれぞ　つねならむ うゐのおくやま　けふこえて あさきゆめみじ　ゑひもせず",
        };
        //  clang-format on

        float current_line_offset = line_offset;
        for (const auto& str : strings) {
            Mesh text_mesh = font.create_text_mesh(str);

            TEST_ASSERT(text_mesh.vertices().size() > 0, "Text mesh is empty.");
            TEST_ASSERT(text_mesh.sub_meshes().size() > 0, "Text mesh is empty.");

            renderer.load(text_mesh);

            objects.emplace_back(std::move(text_mesh), math::Vector3f(0.5f, height - current_line_offset, 0.0f));
            current_line_offset += line_offset;
        }

        Shader shader;
        shader.set_vertex_source(vertex_shader);
        shader.set_fragment_source(fragment_shader);
        renderer.load(shader);
        shader.clear();

        window.show();

        std::chrono::microseconds max_total_time = std::chrono::seconds(300);
        std::chrono::microseconds total_time(0);
        std::chrono::milliseconds delta_time(16);

        while (!window.should_close() && total_time < max_total_time) {
            window.process_events();

            for (const auto& object : objects) {
                Matrix4f transform = translate(math::Matrix4f(), object.position);
                renderer.render(object.mesh, shader, {Uniform{"modelMatrix", transform}});
            }

            renderer.display();

            std::this_thread::sleep_for(delta_time);
            total_time += delta_time;
        }
    }
};

int main()
{
    return run_tests(FontTest());
}
