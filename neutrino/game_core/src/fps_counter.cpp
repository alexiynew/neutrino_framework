#include <chrono>

#include <game_core/fps_counter.hpp>

namespace framework::game_core
{
FpsCounter::FpsCounter()
    : m_fps_thread(&FpsCounter::slice_fps, this)
{}

FpsCounter::~FpsCounter()
{
    m_should_stop = true;
    m_fps_thread.join();
}

void FpsCounter::tick()
{
    m_frames++;
    m_frames_total++;
}

std::uint32_t FpsCounter::fps() const
{
    return m_fps;
}

std::uint32_t FpsCounter::total_fames() const
{
    return m_frames_total;
}

void FpsCounter::slice_fps()
{
    while (!m_should_stop) {
        m_fps = m_frames.exchange(0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

} // namespace framework::game_core
