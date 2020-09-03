////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Contains transform math functions.
/// @author Fedorov Alexey
/// @date 14.07.2017
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

#ifndef FRAMEWORK_MATH_DETAILS
    #error You should include math/math.hpp instead of transform_functions.hpp
#endif

#ifndef FRAMEWORK_MATH_INC_TRANSFORM_FUNCTIONS_HPP
    #define FRAMEWORK_MATH_INC_TRANSFORM_FUNCTIONS_HPP

    #include <cassert>
    #include <limits>

    #include <math/inc/common_functions.hpp>
    #include <math/inc/matrix_functions.hpp>
    #include <math/inc/matrix_type.hpp>
    #include <math/inc/trigonometric_functions.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_transform_functions
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name translate
/// @{
///
/// @brief Builds a translation 3x3 Matrix created from a vector of 2 components.
///
/// @param m Matrix multiplied by this translation Matrix.
/// @param v Translation vector.
///
/// @return The Matrix which contains translation transformation.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<3, 3, T> translate(const Matrix<3, 3, T>& m, const Vector<2, T>& v)
{
    return Matrix<3, 3, T>(m[0], m[1], m[0] * v[0] + m[1] * v[1] + m[2]);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Builds a translation 4x4 Matrix created from a vector of 3 components.
///
/// @param m Matrix multiplied by this translation Matrix.
/// @param v Translation vector.
///
/// @return The Matrix which contains translation transformation.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> translate(const Matrix<4, 4, T>& m, const Vector<3, T>& v)
{
    // clang-format off
    Matrix<4, 4, T> temp(1,    0,    0,    0,
                         0,    1,    0,    0,
                         0,    0,    1,    0,
                         v[0], v[1], v[2], 1);
    // clang-format on

    return m * temp;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name rotate
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Builds a rotation 3x3 Matrix created from an angle.
///
/// @param m Matrix multiplied by this translation Matrix.
/// @param angle Rotation angle expressed in radians.
///
/// @return The Matrix which contains rotation transformation.
////////////////////////////////////////////////////////////////////////////////
template <typename T, typename U>
inline Matrix<3, 3, T> rotate(const Matrix<3, 3, T>& m, const U angle)
{
    const auto c = static_cast<T>(math::cos(angle));
    const auto s = static_cast<T>(math::sin(angle));

    // clang-format off
    return Matrix<3, 3, T>(m[0] *  c + m[1] * s,
                           m[0] * -s + m[1] * c,
                           m[2]);
    // clang-format on
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Builds a rotation 4x4 Matrix created from an axis vector and an angle.
///
/// @param m Matrix multiplied by this rotation Matrix.
/// @param v Rotation axis, recommended to be normalized.
/// @param angle Rotation angle expressed in radians.
///
/// @return The Matrix which contains rotation transformation.
////////////////////////////////////////////////////////////////////////////////
template <typename T, typename U>
inline Matrix<4, 4, T> rotate(const Matrix<4, 4, T>& m, const Vector<3, T>& v, const U angle)
{
    const auto cos = static_cast<T>(framework::math::cos(angle));
    const auto sin = static_cast<T>(framework::math::sin(angle));

    const auto x_cos = v[0] * (1 - cos);
    const auto y_cos = v[1] * (1 - cos);
    const auto z_cos = v[2] * (1 - cos);

    const auto x_sin = v[0] * sin;
    const auto y_sin = v[1] * sin;
    const auto z_sin = v[2] * sin;

    // clang-format off
    const Matrix<4, 4, T> temp(
            v[0] * x_cos + cos,   v[1] * x_cos + z_sin, v[2] * x_cos - y_sin, 0,
            v[0] * y_cos - z_sin, v[1] * y_cos + cos,   v[2] * y_cos + x_sin, 0,
            v[0] * z_cos + y_sin, v[1] * z_cos - x_sin, v[2] * z_cos + cos,   0,
            0,                    0,                    0,                    1);
    // clang-format on

    return m * temp;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name scale
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Builds a scale 3x3 Matrix created from a vector of 2 components.
///
/// @param m Matrix multiplied by this translation Matrix.
/// @param v Coordinates of a scale vector.
///
/// @return The Matrix which contains scale transformation.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<3, 3, T> scale(const Matrix<3, 3, T>& m, const Vector<2, T>& v)
{
    return Matrix<3, 3, T>(m[0] * v[0], m[1] * v[1], m[2]);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Builds a scale 4x4 Matrix created from a vector of 3 components.
///
/// @param m Matrix multiplied by this scale Matrix.
/// @param v Ratio of scaling for each axis.
///
/// @return The Matrix which contains scale transformation.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> scale(const Matrix<4, 4, T>& m, const Vector<3, T>& v)
{
    // clang-format off
    const Matrix<4, 4, T> temp(v[0], 0,    0,    0,
                               0,    v[1], 0,    0,
                               0,    0,    v[2], 0,
                               0,    0,    0,    1);
    // clang-format on
    return m * temp;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name shear
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Builds shear 3x3 Matrix.
///
/// @param m Matrix multiplied by this translation Matrix.
/// @param v Shear factor.
///
/// @return The Matrix which contains shear transformation.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<3, 3, T> shear(const Matrix<3, 3, T>& m, const Vector<2, T>& v)
{
    // clang-format off
    const Matrix<3, 3, T> shear(1,   v.x, 0,
                                v.y, 1,   0,
                                0,   0,   1);
    // clang-format on

    return m * shear;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name ortho
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a Matrix for an orthographic parallel viewing volume,
/// using right-handedness.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @param near_val Near clipping plane.
/// @param far_val Far clipping plane.
///
/// @return The orthographic projection Matrix.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> ortho(const T left, const T right, const T bottom, const T top, const T near_val, const T far_val)
{
    const T width  = right - left;
    const T height = top - bottom;
    const T depth  = far_val - near_val;

    assert(framework::math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    assert(framework::math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));
    assert(framework::math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));

    // clang-format off
    return Matrix<4, 4, T> (
            T(2) / width,            0,                        0,                             0,
            0,                       T(2) / height,            0,                             0,
            0,                       0,                        -T(2) / depth,                 0,
            -(right + left) / width, -(top + bottom) / height, -(far_val + near_val) / depth, 1
    );
    // clang-format on
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name ortho2d
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a Matrix for projecting two-dimensional coordinates
/// onto the screen.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
///
/// @return The orthographic projection Matrix for two-dimensional space.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> ortho2d(const T left, const T right, const T bottom, const T top)
{
    return ortho(left, right, bottom, top, -T(1), T(1));
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name frustum
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a right handed frustum Matrix.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @param near_val Distance to the near clipping plane (always positive).
/// @param far_val Distance to the far clipping plane (always positive).
///
/// @return The frustum Matrix.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> frustum(const T left,
                               const T right,
                               const T bottom,
                               const T top,
                               const T near_val,
                               const T far_val)
{
    assert(near_val > T(0));
    assert(far_val > T(0));

    const T width  = right - left;
    const T height = top - bottom;
    const T depth  = far_val - near_val;

    assert(framework::math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    assert(framework::math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));
    assert(framework::math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));

    // clang-format off
    return Matrix<4, 4, T> (
        (T(2) * near_val) / width,  0,                          0,                                    0,
        0,                          (T(2) * near_val) / height, 0,                                    0,
        (right + left) / width,     (top + bottom) / height,    -(far_val + near_val) / depth,        -1,
        0,                          0,                          -(T(2) * far_val * near_val) / depth, 0
    );
    // clang-format on
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name perspective
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a Matrix for a right handed, symmetric perspective-view
/// frustum.
///
/// @param fov_y Specifies the field of view angle in the y direction,
///              in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
///               in the x direction. The aspect ratio is the ratio of
///               x (width) to y (height).
/// @param near_val Specifies the distance from the viewer to the near clipping
///                 plane (always positive).
/// @param far_val Specifies the distance from the viewer to the far clipping
///                plane (always positive).
///
/// @return The perspective projection Matrix.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> perspective(T fov_y, T aspect, T near_val, T far_val)
{
    assert(near_val > T(0));
    assert(far_val > T(0));

    const T depth   = far_val - near_val;
    const T tangent = tan(fov_y / T(2));

    assert(framework::math::abs(aspect - std::numeric_limits<T>::epsilon()) > T(0));
    assert(framework::math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));
    assert(framework::math::abs(tangent - std::numeric_limits<T>::epsilon()) > T(0));

    const T cotangent = T(1) / tangent;

    // clang-format off
    return Matrix<4, 4, T> (
        cotangent / aspect, 0,         0,                                    0,
        0,                  cotangent, 0,                                    0,
        0,                  0,         -(far_val + near_val) / depth,        -1,
        0,                  0,         -(T(2) * far_val * near_val) / depth, 0
    );
    // clang-format on
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name perspective_fov
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Builds a right handed perspective projection Matrix based on a
/// field of view.
///
/// @param fov Expressed in radians.
/// @param width Width of the plane (always positive).
/// @param height Height of the plane (always positive).
/// @param near_val Specifies the distance from the viewer to the near clipping
///                 plane (always positive).
/// @param far_val Specifies the distance from the viewer to the far clipping
///                plane (always positive).
///
/// @return The perspective projection Matrix.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> perspective_fov(T fov, T width, T height, T near_val, T far_val)
{
    assert(width > T(0));
    assert(height > T(0));
    assert(near_val > T(0));
    assert(far_val > T(0));

    return perspective(fov, width / height, near_val, far_val);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name infinite_perspective
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Creates a Matrix for a right handed, symmetric perspective-view
/// frustum with far plane at infinite.
///
/// @param fov_y Specifies the field of view angle in the y direction,
///              in radians.
/// @param aspect Specifies the aspect ratio that determines the field of
///               view in the x direction. The aspect ratio is the ratio of
///               x (width) to y (height).
/// @param near_val Specifies the distance from the viewer to the near clipping
///                 plane (always positive).
///
/// @return The perspective projection Matrix.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> infinite_perspective(T fov_y, T aspect, T near_val)
{
    assert(near_val > T(0));
    assert(framework::math::abs(aspect - std::numeric_limits<T>::epsilon()) > T(0));

    const T tangent = math::tan(fov_y / T(2));

    assert(framework::math::abs(tangent - std::numeric_limits<T>::epsilon()) > T(0));

    const T cotangent = T(1) / tangent;
    const T epsilon   = std::numeric_limits<T>::epsilon();

    // clang-format off
    return Matrix<4, 4, T> (
        cotangent / aspect, 0,         0,                           0,
        0,                  cotangent, 0,                           0,
        0,                  0,         epsilon - 1,                 -1,
        0,                  0,         (epsilon - T(2)) * near_val, 0
    );
    // clang-format on
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name project
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Map the specified coordinates (v.x, v.y, v.z) into window coordinates.
///
/// @param v Specify the coordinates.
/// @param model Specifies the current model-view Matrix
/// @param projection Specifies the current projection Matrix
/// @param viewport Specifies the current viewport
///
/// @return Return the computed window coordinates.
////////////////////////////////////////////////////////////////////////////////
template <typename T, typename U>
inline Vector<3, T> project(const Vector<3, T>& v,
                            const Matrix<4, 4, T>& model,
                            const Matrix<4, 4, T>& projection,
                            const Vector<4, U>& viewport)
{
    Vector<4, T> temp(v, T(1));
    temp = projection * model * temp;

    assert(framework::math::abs(temp.w - std::numeric_limits<T>::epsilon()) > T(0));

    temp /= temp.w;

    temp = temp * T(0.5) + T(0.5);

    const auto x      = static_cast<T>(viewport[0]);
    const auto y      = static_cast<T>(viewport[1]);
    const auto width  = static_cast<T>(viewport[2]);
    const auto height = static_cast<T>(viewport[3]);

    temp[0] = temp[0] * width + x;
    temp[1] = temp[1] * height + y;

    return Vector<3, T>(temp);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name unproject
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Map the specified window coordinates (v.x, v.y, v.z)
/// into object coordinates.
///
/// @param v Specify the window coordinates to be mapped.
/// @param model Specifies the model-view Matrix
/// @param projection Specifies the projection Matrix
/// @param viewport Specifies the viewport
///
/// @return Returns the computed object coordinates.
////////////////////////////////////////////////////////////////////////////////
template <typename T, typename U>
inline Vector<3, T> unproject(const Vector<3, T>& v,
                              const Matrix<4, 4, T>& model,
                              const Matrix<4, 4, T>& projection,
                              const Vector<4, U>& viewport)
{
    const auto x      = static_cast<T>(viewport[0]);
    const auto y      = static_cast<T>(viewport[1]);
    const auto width  = static_cast<T>(viewport[2]);
    const auto height = static_cast<T>(viewport[3]);

    assert(framework::math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    assert(framework::math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));

    const Matrix<4, 4, T> inverse = framework::math::inverse(projection * model);

    Vector<4, T> temp(v, T(1));
    temp.x = (temp.x - x) / width;
    temp.y = (temp.y - y) / height;

    temp = temp * T(2) - T(1);

    Vector<4, T> object_matrix = inverse * temp;

    assert(framework::math::abs(temp.w - std::numeric_limits<T>::epsilon()) > T(0));

    object_matrix /= object_matrix.w;

    return Vector<3, T>(object_matrix);
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name pick_matrix
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Define a picking region.
///
/// Creates a projection Matrix that can be used to restrict drawing to
/// a small region of the viewport.
///
/// @param center Center of region in window coordinates.
/// @param delta Width and height of region in window coordinates.
/// @param viewport Specifies the viewport.
///
/// @return The region Matrix.
////////////////////////////////////////////////////////////////////////////////
template <typename T, typename U>
inline Matrix<4, 4, T> pick_matrix(const Vector<2, T>& center, const Vector<2, T>& delta, const Vector<4, U>& viewport)
{
    assert(delta.x > T(0));
    assert(delta.y > T(0));

    const auto x      = static_cast<T>(viewport[0]);
    const auto y      = static_cast<T>(viewport[1]);
    const auto width  = static_cast<T>(viewport[2]);
    const auto height = static_cast<T>(viewport[3]);

    const Vector<3, T> translate_temp = {(width - T(2) * (center.x - x)) / delta.x,
                                         (height - T(2) * (center.y - y)) / delta.y,
                                         T(0)};

    const Vector<3, T> scale_temp = {width / delta.x, height / delta.y, T(1)};

    // Translate and scale the picked region to the entire window
    // clang-format off
    Matrix<4, 4, T> temp(scale_temp[0],     0,                 0,                 0,
                         0,                 scale_temp[1],     0,                 0,
                         0,                 0,                 scale_temp[2],     0,
                         translate_temp[0], translate_temp[1], translate_temp[2], 1);
    // clang-format on
    return temp;
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @name look_at
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Build a right handed look at view Matrix.
///
/// Creates a viewing Matrix derived from an eye point,
/// a reference point indicating the center of the scene, and an up vector
///
/// @param eye Position of the camera
/// @param center Position where the camera is looking at
/// @param up Normalized up vector, how the camera is oriented.
///           Typically (0, 1, 0)
///
/// @return The viewing Matrix.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
inline Matrix<4, 4, T> look_at(const Vector<3, T>& eye, const Vector<3, T>& center, const Vector<3, T>& up)
{
    const Vector<3, T> forward = normalize(center - eye);
    const Vector<3, T> side    = normalize(cross(forward, up));
    const Vector<3, T> new_up  = cross(side, forward);

    // clang-format off
    return Matrix<4, 4, T> {
        side.x,          new_up.x,          -forward.x,        0,
        side.y,          new_up.y,          -forward.y,        0,
        side.z,          new_up.z,          -forward.z,        0,
        -dot(side, eye), -dot(new_up, eye), dot(forward, eye), 1
    };
    // clang-format on
}
////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
