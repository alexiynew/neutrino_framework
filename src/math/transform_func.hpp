/// @file
/// @brief Contains transform math functions.
/// @author Fedorov Alexey
/// @date 14.07.2017

#ifndef FRAMEWORK_MATH_TRANSFORM_TYPE_HPP
#define FRAMEWORK_MATH_TRANSFORM_TYPE_HPP

#include <limits>
#include <log/log.hpp>
#include <math/common_func.hpp>
#include <math/matrix_func.hpp>
#include <math/matrix_type.hpp>
#include <math/trigonometric_func.hpp>

namespace framework {

namespace math {

/// @brief Contains implementation details of some functions.
namespace transform_functions_details {

/// @brief Creates a rotation 4x4 matrix.
template <typename T, typename U>
inline matrix<4, 4, T> create_rotate_matrix(const vector<3, T>& v, const U angle)
{
    const T cos = static_cast<T>(::framework::math::cos(angle));
    const T sin = static_cast<T>(::framework::math::sin(angle));

    const auto x_cos = v[0] * (1 - cos);
    const auto y_cos = v[1] * (1 - cos);
    const auto z_cos = v[2] * (1 - cos);

    const auto x_sin = v[0] * sin;
    const auto y_sin = v[1] * sin;
    const auto z_sin = v[2] * sin;

    // clang-format off
    return matrix<4, 4, T>(
            v[0] * x_cos + cos,   v[1] * x_cos + z_sin, v[2] * x_cos - y_sin, 0,
            v[0] * y_cos - z_sin, v[1] * y_cos + cos,   v[2] * y_cos + x_sin, 0,
            v[0] * z_cos + y_sin, v[1] * z_cos - x_sin, v[2] * z_cos + cos,   0,
            0,                    0,                    0,                    1);
    // clang-format on
}

} // namespace transform_functions_details

/// @brief Defines transform functions.
///
/// @defgroup transform_functions Transform functions
/// @ingroup math_module
/// @{

/// @name translate
/// @{
///
/// @brief Builds a translation 3x3 matrix created from a vector of 2 components.
///
/// @param m Matrix multiplied by this translation matrix.
/// @param v Translation vector.
///
/// @return The matrix which contains translation transformation.
template <typename T>
inline matrix<3, 3, T> translate(const matrix<3, 3, T>& m, const vector<2, T>& v)
{
    return matrix<3, 3, T>(m[0], m[1], m[0] * v[0] + m[1] * v[1] + m[2]);
}

/// @brief Builds a translation 4x4 matrix created from a vector of 3 components.
///
/// @param m Matrix multiplied by this translation matrix.
/// @param v Translation vector.
///
/// @return The matrix which contains translation transformation.
template <typename T>
inline matrix<4, 4, T> translate(const matrix<4, 4, T>& m, const vector<3, T>& v)
{
    // clang-format off
    matrix<4, 4, T> temp(1,    0,    0,    0,
                         0,    1,    0,    0,
                         0,    0,    1,    0,
                         v[0], v[1], v[2], 1);
    // clang-format on

    return m * temp;
}
/// @}

/// @name rotate
/// @{
///
/// @brief Builds a rotation 3x3 matrix created from an angle.
///
/// @param m Matrix multiplied by this translation matrix.
/// @param angle Rotation angle expressed in radians.
///
/// @return The matrix which contains rotation transformation.
template <typename T, typename U>
inline matrix<3, 3, T> rotate(const matrix<3, 3, T>& m, const U angle)
{
    const T c = static_cast<T>(math::cos(angle));
    const T s = static_cast<T>(math::sin(angle));

    // clang-format off
    return matrix<3, 3, T>(m[0] *  c + m[1] * s,
                           m[0] * -s + m[1] * c,
                           m[2]);
    // clang-format on
}

/// @brief Builds a rotation 4x4 matrix created from an axis vector and an angle.
///
/// @param m Matrix multiplied by this rotation matrix.
/// @param v Rotation axis, recommended to be normalized.
/// @param angle Rotation angle expressed in radians.
///
/// @return The matrix which contains rotation transformation.
template <typename T, typename U>
inline matrix<4, 4, T> rotate(const matrix<4, 4, T>& m, const vector<3, T>& v, const U angle)
{
    return m * transform_functions_details::create_rotate_matrix(v, angle);
}
/// @}

/// @name scale
/// @{

/// @brief Builds a scale 3x3 matrix created from a vector of 2 components.
///
/// @param m Matrix multiplied by this translation matrix.
/// @param v Coordinates of a scale vector.
///
/// @return The matrix which contains scale transformation.
template <typename T>
inline matrix<3, 3, T> scale(const matrix<3, 3, T>& m, const vector<2, T>& v)
{
    return matrix<3, 3, T>(m[0] * v[0], m[1] * v[1], m[2]);
}

/// @brief Builds a scale 4x4 matrix created from a vector of 3 components.
///
/// @param m Matrix multiplied by this scale matrix.
/// @param v Ratio of scaling for each axis.
///
/// @return The matrix which contains scale transformation.
template <typename T>
inline matrix<4, 4, T> scale(const matrix<4, 4, T>& m, const vector<3, T>& v)
{
    // clang-format off
    const matrix<4, 4, T> temp(v[0], 0,    0,    0,
                               0,    v[1], 0,    0,
                               0,    0,    v[2], 0,
                               0,    0,    0,    1);
    // clang-format on
    return m * temp;
}
/// @}

/// @name shear
/// @{

/// @brief Builds shear 3x3 matrix.
///
/// @param m Matrix multiplied by this translation matrix.
/// @param v Shear factor.
///
/// @return The matrix which contains shear transformation.
template <typename T>
inline matrix<3, 3, T> shear(const matrix<3, 3, T>& m, const vector<2, T>& v)
{
    // clang-format off
    const matrix<3, 3, T> shear(1,   v.x, 0,
                                v.y, 1,   0,
                                0,   0,   1);
    // clang-format on

    return m * shear;
}
/// @}

/// @name ortho
/// @{

/// @brief Creates a matrix for an orthographic parallel viewing volume, using right-handedness.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @param near Near clipping plane.
/// @param far Far clipping plane.
///
/// @return The orthographic projection matrix.
template <typename T>
inline matrix<4, 4, T> ortho(const T left, const T right, const T bottom, const T top, const T near, const T far)
{
    const T width  = right - left;
    const T height = top - bottom;
    const T depth  = far - near;

    ASSERT(::framework::math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(::framework::math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(::framework::math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));

    // clang-format off
    return matrix<4, 4, T> (
            T(2) / width,            0,                        0,                     0,
            0,                       T(2) / height,            0,                     0,
            0,                       0,                        -T(2) / depth,         0,
            -(right + left) / width, -(top + bottom) / height, -(far + near) / depth, 1
    );
    // clang-format on
}
/// @}

/// @name ortho2d
/// @{

/// @brief Creates a matrix for projecting two-dimensional coordinates onto the screen.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
///
/// @return The orthographic projection matrix for two-dimensional space.
template <typename T>
inline matrix<4, 4, T> ortho2d(const T left, const T right, const T bottom, const T top)
{
    return ortho(left, right, bottom, top, T(1), -T(1));
}
/// @}

/// @name frustum
/// @{

/// @brief Creates a right handed frustum matrix.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @param near Distance to the near clipping plane (always positive).
/// @param far Distance to the far clipping plane (always positive).
///
/// @return The frustum matrix.
template <typename T>
inline matrix<4, 4, T> frustum(const T left, const T right, const T bottom, const T top, const T near, const T far)
{
    ASSERT(near > T(0));
    ASSERT(far > T(0));

    const T width  = right - left;
    const T height = top - bottom;
    const T depth  = far - near;

    ASSERT(::framework::math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(::framework::math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(::framework::math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));

    // clang-format off
    return matrix<4, 4, T> (
        (T(2) * near) / width,  0,                       0,                            0,
        0,                      (T(2) * near) / height,  0,                            0,
        (right + left) / width, (top + bottom) / height, -(far + near) / depth,        -1,
        0,                      0,                       -(T(2) * far * near) / depth, 0
    );
    // clang-format on
}
/// @}

/// @name perspective
/// @{

/// @brief Creates a matrix for a right handed, symmetric perspective-view frustum.
///
/// @param fov_y Specifies the field of view angle in the y direction, in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction.
///               The aspect ratio is the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
///
/// @return The perspective projection matrix.
template <typename T>
inline matrix<4, 4, T> perspective(T fov_y, T aspect, T near, T far)
{
    ASSERT(near > T(0));
    ASSERT(far > T(0));

    const T depth   = far - near;
    const T tangent = tan(fov_y / T(2));

    ASSERT(::framework::math::abs(aspect - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(::framework::math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(::framework::math::abs(tangent - std::numeric_limits<T>::epsilon()) > T(0));

    const T cotangent = T(1) / tangent;

    // clang-format off
    return matrix<4, 4, T> (
        cotangent / aspect, 0,         0,                            0,
        0,                  cotangent, 0,                            0,
        0,                  0,         -(far + near) / depth,        -1,
        0,                  0,         -(T(2) * far * near) / depth, 0
    );
    // clang-format on
}
/// @}

/// @name perspective_fov
/// @{

/// @brief Builds a right handed perspective projection matrix based on a field of view.
///
/// @param fov Expressed in radians.
/// @param width Width of the plane (always positive).
/// @param height Height of the plane (always positive).
/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
///
/// @return The perspective projection matrix.
template <typename T>
inline matrix<4, 4, T> perspective_fov(T fov, T width, T height, T near, T far)
{
    ASSERT(width > T(0));
    ASSERT(height > T(0));
    ASSERT(near > T(0));
    ASSERT(far > T(0));

    return perspective(fov, width / height, near, far);
}
/// @}

/// @name infinite_perspective
/// @{

/// @brief Creates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite.
///
/// @param fov_y Specifies the field of view angle in the y direction, in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction.
///               The aspect ratio is the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
///
/// @return The perspective projection matrix.
template <typename T>
inline matrix<4, 4, T> infinite_perspective(T fov_y, T aspect, T near)
{
    ASSERT(near > T(0));
    ASSERT(::framework::math::abs(aspect - std::numeric_limits<T>::epsilon()) > T(0));

    const T tangent = math::tan(fov_y / T(2));

    ASSERT(::framework::math::abs(tangent - std::numeric_limits<T>::epsilon()) > T(0));

    const T cotangent = T(1) / tangent;
    const T epsilon   = std::numeric_limits<T>::epsilon();

    // clang-format off
    return matrix<4, 4, T> (
        cotangent / aspect, 0,         0,                       0,
        0,                  cotangent, 0,                       0,
        0,                  0,         epsilon - 1,             -1,
        0,                  0,         (epsilon - T(2)) * near, 0
    );
    // clang-format on
}
/// @}

/// @name project
/// @{

/// @brief Map the specified coordinates (v.x, v.y, v.z) into window coordinates.
///
/// @param v Specify the coordinates.
/// @param model Specifies the current model-view matrix
/// @param projection Specifies the current projection matrix
/// @param viewport Specifies the current viewport
///
/// @return Return the computed window coordinates.
template <typename T, typename U>
inline vector<3, T>
project(const vector<3, T>& v, const matrix<4, 4, T>& model, const matrix<4, 4, T>& projection, const vector<4, U>& viewport)
{
    vector<4, T> temp(v, T(1));
    temp = projection * model * temp;

    ASSERT(::framework::math::abs(temp.w - std::numeric_limits<T>::epsilon()) > T(0));

    temp /= temp.w;

    temp = temp * T(0.5) + T(0.5);

    const T x      = static_cast<T>(viewport[0]);
    const T y      = static_cast<T>(viewport[1]);
    const T width  = static_cast<T>(viewport[2]);
    const T height = static_cast<T>(viewport[3]);

    temp[0] = temp[0] * width + x;
    temp[1] = temp[1] * height + y;

    return vector<3, T>(temp);
}
/// @}

/// @name unproject
/// @{

/// @brief Map the specified window coordinates (v.x, v.y, v.z) into object coordinates.
///
/// @param v Specify the window coordinates to be mapped.
/// @param model Specifies the model-view matrix
/// @param projection Specifies the projection matrix
/// @param viewport Specifies the viewport
///
/// @return Returns the computed object coordinates.
template <typename T, typename U>
inline vector<3, T>
unproject(const vector<3, T>& v, const matrix<4, 4, T>& model, const matrix<4, 4, T>& projection, const vector<4, U>& viewport)
{
    const T x      = static_cast<T>(viewport[0]);
    const T y      = static_cast<T>(viewport[1]);
    const T width  = static_cast<T>(viewport[2]);
    const T height = static_cast<T>(viewport[3]);

    ASSERT(::framework::math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(::framework::math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));

    const matrix<4, 4, T> inverse = ::framework::math::inverse(projection * model);

    vector<4, T> temp(v, T(1));
    temp.x = (temp.x - x) / width;
    temp.y = (temp.y - y) / height;

    temp = temp * T(2) - T(1);

    vector<4, T> object_matrix = inverse * temp;

    ASSERT(::framework::math::abs(temp.w - std::numeric_limits<T>::epsilon()) > T(0));

    object_matrix /= object_matrix.w;

    return vector<3, T>(object_matrix);
}
/// @}

/// @name pick_matrix
/// @{

/// @brief Define a picking region.
///
/// Creates a projection matrix that can be used to restrict drawing to a small region of the viewport.
///
/// @param center Center of region in window coordinates.
/// @param delta Width and height of region in window coordinates.
/// @param viewport Specifies the viewport.
///
/// @return The region matrix.
template <typename T, typename U>
inline matrix<4, 4, T> pick_matrix(const vector<2, T>& center, const vector<2, T>& delta, const vector<4, U>& viewport)
{
    ASSERT(delta.x > T(0));
    ASSERT(delta.y > T(0));

    const T x      = static_cast<T>(viewport[0]);
    const T y      = static_cast<T>(viewport[1]);
    const T width  = static_cast<T>(viewport[2]);
    const T height = static_cast<T>(viewport[3]);

    const vector<3, T> translate_temp = {
    (width - T(2) * (center.x - x)) / delta.x, (height - T(2) * (center.y - y)) / delta.y, T(0)};

    const vector<3, T> scale_temp = {width / delta.x, height / delta.y, T(1)};

    // Translate and scale the picked region to the entire window
    // clang-format off
    matrix<4, 4, T> temp(scale_temp[0],     0,                 0,                 0,
                         0,                 scale_temp[1],     0,                 0,
                         0,                 0,                 scale_temp[2],     0,
                         translate_temp[0], translate_temp[1], translate_temp[2], 1);
    // clang-format on
    return temp;
}
/// @}

/// @name look_at
/// @{

/// @brief Build a right handed look at view matrix.
///
/// Creates a viewing matrix derived from an eye point,
/// a reference point indicating the center of the scene, and an up vector
///
/// @param eye Position of the camera
/// @param center Position where the camera is looking at
/// @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
///
/// @return The viewing matrix.
template <typename T>
inline matrix<4, 4, T> look_at(const vector<3, T>& eye, const vector<3, T>& center, const vector<3, T>& up)
{
    const vector<3, T> forward = normalize(center - eye);
    const vector<3, T> side    = normalize(cross(forward, up));
    const vector<3, T> new_up  = cross(side, forward);

    // clang-format off
    return matrix<4, 4, T> {
        side.x,          new_up.x,          -forward.x,        0,
        side.y,          new_up.y,          -forward.y,        0,
        side.z,          new_up.z,          -forward.z,        0,
        -dot(side, eye), -dot(new_up, eye), dot(forward, eye), 1
    };
    // clang-format on
}
/// @}

/// @}

} // namespace math

} // namespace framework

#endif
