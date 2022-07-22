#include <chrono>
#include <thread>

#include <game_core/fps_counter.hpp>
#include <unit_test/suite.hpp>

using namespace framework;
using namespace framework::game_core;

class FpsCounterTest : public unit_test::Suite
{
public:
    FpsCounterTest()
        : Suite("FpsCounterTest")
    {
        add_test([this]() { fps_count(); }, "fps_count");
    }

private:
    void fps_count()
    {
        FpsCounter fps;

        for (int i = 0; i < 100; ++i) {
            fps.tick();
        }

        while (fps.fps() == 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }

        TEST_ASSERT(fps.fps() == 100, "Should be 100 frames");

        while (fps.fps() != 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }

        TEST_ASSERT(fps.fps() == 0, "Should be 0 frames");
        TEST_ASSERT(fps.total_fames() == 100, "Should be 100 frames");
    }
};

int main()
{
    return run_tests(FpsCounterTest());
}
