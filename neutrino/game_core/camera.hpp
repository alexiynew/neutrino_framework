////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Camera.
/// @author Fedorov Alexey
/// @date 29.07.2020
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

#ifndef FRAMEWORK_GAME_CORE_CAMERA_HPP
#define FRAMEWORK_GAME_CORE_CAMERA_HPP

#include <chrono>

#include <math/math.hpp>

namespace framework::game_core
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup game_core_module
/// @{
////////////////////////////////////////////////////////////////////////////////

class Camera
{
public:
    enum class ActionState
    {
        moveForward,
        moveBackward,
        moveUp,
        moveDown,
        moveLeft,
        moveRight,
    };

    Camera(math::Vector3f position, math::Vector3f front, math::Vector3f up);

    Camera(const Camera& other) = default;
    Camera& operator=(const Camera& other) = default;

    Camera(Camera&& other) = default;
    Camera& operator=(Camera&& other) = default;

    void set_action(ActionState state, bool value);
    void set_speed(float speed);

    void update(std::chrono::nanoseconds delata_time);

    bool is_action_set(ActionState state) const;

    math::Matrix4f get_view() const;

private:
    struct State
    {
        int moveForward : 1;
        int moveBackward : 1;
        int moveUp : 1;
        int moveDown : 1;
        int moveLeft : 1;
        int moveRight : 1;
    };

    math::Vector3f m_position = {0, 0, 0};
    math::Vector3f m_front    = {0, 0, 0};
    math::Vector3f m_up       = {0, 0, 0};

    float m_speed = 0;

    State m_state = {0};
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::game_core

#endif
