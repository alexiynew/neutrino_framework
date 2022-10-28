#ifndef GAME_CORE_CAMERA_HPP
#define GAME_CORE_CAMERA_HPP

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

    Camera(const Camera& other)            = default;
    Camera& operator=(const Camera& other) = default;

    Camera(Camera&& other)            = default;
    Camera& operator=(Camera&& other) = default;

    void set_action(ActionState state, bool value);
    void set_speed(float speed);
    void set_sensitivity(float sensitivity);
    void set_offset(math::Vector2f offset);

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

    float m_yaw   = -90.0f;
    float m_pitch = 0.0f;

    float m_speed       = 0.0f;
    float m_sensitivity = 0.05f;

    State m_state = {0, 0, 0, 0, 0, 0};
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::game_core

#endif
