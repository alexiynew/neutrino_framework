// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

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
