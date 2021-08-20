////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Fps counter.
/// @author Fedorov Alexey
/// @date 09.04.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#ifndef FRAMEWORK_GAME_CORE_FPS_COUNTER_HPP
#define FRAMEWORK_GAME_CORE_FPS_COUNTER_HPP

#include <atomic>
#include <thread>

namespace framework::game_core
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup game_core_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Fps counter
////////////////////////////////////////////////////////////////////////////////
class FpsCounter final
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates FpsCounter
    ////////////////////////////////////////////////////////////////////////////
    FpsCounter();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    ////////////////////////////////////////////////////////////////////////////
    ~FpsCounter();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief FpsCounter can't be copied
    ////////////////////////////////////////////////////////////////////////////
    FpsCounter(const FpsCounter&) = delete;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief FpsCounter can't be copied
    ////////////////////////////////////////////////////////////////////////////
    FpsCounter& operator=(const FpsCounter&) = delete;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Count a frame.
    ///
    /// Should be called once per frame.
    ////////////////////////////////////////////////////////////////////////////
    void tick();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Frames per second
    ///
    /// @return Frames count.
    ////////////////////////////////////////////////////////////////////////////
    int fps() const;

private:
    void slice_fps();

    bool m_should_stop        = false;
    std::atomic<int> m_frames = 0;
    std::atomic<int> m_fps    = 0;
    std::thread m_fps_thread;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////
} // namespace framework::game_core

#endif
