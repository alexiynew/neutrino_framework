////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Camera.
/// @author Fedorov Alexey
/// @date 29.07.2020
////////////////////////////////////////////////////////////////////////////////

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

#include <game_core/camera.hpp>

namespace framework::game_core
{

Camera::Camera(math::Vector3f position, math::Vector3f front, math::Vector3f up)
    : m_position(position)
    , m_front(normalize(front))
    , m_up(normalize(up))
{}

void Camera::set_action(ActionState state, bool value)
{
    switch (state) {
        case ActionState::moveForward: m_state.moveForward = value; break;
        case ActionState::moveBackward: m_state.moveBackward = value; break;
        case ActionState::moveUp: m_state.moveUp = value; break;
        case ActionState::moveDown: m_state.moveDown = value; break;
        case ActionState::moveLeft: m_state.moveLeft = value; break;
        case ActionState::moveRight: m_state.moveRight = value; break;
    }
}

void Camera::set_speed(float speed)
{
    m_speed = speed;
}

void Camera::set_sensitivity(float sensitivity)
{
    m_sensitivity = sensitivity;
}

void Camera::set_offset(math::Vector2f offset)
{
    m_yaw += offset.x * m_sensitivity;
    m_pitch += offset.y * m_sensitivity;

    if (m_pitch > 89.0f) {
        m_pitch = 89.0f;
    }
    if (m_pitch < -89.0f) {
        m_pitch = -89.0f;
    }
}

void Camera::update(std::chrono::nanoseconds delata_time)
{
    using FloatSecond = std::chrono::duration<float>;

    const FloatSecond delta  = std::chrono::duration_cast<FloatSecond>(delata_time);
    const float camera_speed = static_cast<float>(m_speed * delta.count());

    math::Vector3f front;

    front.x = static_cast<float>(cos(math::radians(m_pitch)) * cos(math::radians(m_yaw)));
    front.y = static_cast<float>(sin(math::radians(m_pitch)));
    front.z = static_cast<float>(cos(math::radians(m_pitch)) * sin(math::radians(m_yaw)));

    m_front = normalize(front);

    math::Vector3f direction(0, 0, 0);

    if (m_state.moveForward) {
        direction += m_front;
    }

    if (m_state.moveBackward) {
        direction -= m_front;
    }

    if (m_state.moveLeft) {
        direction -= normalize(cross(m_front, m_up));
    }

    if (m_state.moveRight) {
        direction += normalize(cross(m_front, m_up));
    }

    if (m_state.moveUp) {
        direction += m_up;
    }

    if (m_state.moveDown) {
        direction -= m_up;
    }

    if (any(math::Vector3b(direction))) {
        m_position += normalize(direction) * camera_speed;
    }
}

bool Camera::is_action_set(ActionState state) const
{
    switch (state) {
        case ActionState::moveForward: return m_state.moveForward;
        case ActionState::moveBackward: return m_state.moveBackward;
        case ActionState::moveUp: return m_state.moveUp;
        case ActionState::moveDown: return m_state.moveDown;
        case ActionState::moveLeft: return m_state.moveLeft;
        case ActionState::moveRight: return m_state.moveRight;
    }

    assert(false);
    return false;
}

math::Matrix4f Camera::get_view() const
{
    return look_at(m_position, m_position + m_front, m_up);
}

} // namespace framework::game_core
