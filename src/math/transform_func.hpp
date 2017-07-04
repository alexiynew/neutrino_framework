#ifndef FRAMEWORK_MATH_TRANSFORM_TYPE_HPP
#define FRAMEWORK_MATH_TRANSFORM_TYPE_HPP

#include <math/matrix_type.hpp>
#include <math/trigonometric_func.hpp>

// TODO: Ensure only float type for all functions.

namespace framework {

namespace math {

#pragma mark - 2d transform

/// Builds a translation 3/// 3 matrix created from a vector of 2 components.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Coordinates of a translation vector.
template <typename T>
inline matrix<3, 3, T> translate(const matrix<3, 3, T>& m, const vector<2, T>& v)
{
    return matrix<3, 3, T>(m[0], m[1], m[0] * v[0] + m[1] * v[1] + m[2]);
}

/// Builds a rotation 3/// 3 matrix created from an angle.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param angle Rotation angle expressed in radians.
template <typename T, typename U>
inline matrix<3, 3, T> rotate(const matrix<3, 3, T>& m, const U angle)
{
    const T c = static_cast<T>(math::cos(angle));
    const T s = static_cast<T>(math::sin(angle));

    return matrix<3, 3, T>(m[0] * c + m[1] * s, m[0] * -s + m[1] * c, m[2]);
}

/// Builds a scale 3/// 3 matrix created from a vector of 2 components.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Coordinates of a scale vector.
template <typename T>
inline matrix<3, 3, T> scale(const matrix<3, 3, T>& m, const vector<2, T>& v)
{
    return matrix<3, 3, T>(m[0] * v[0], m[1] * v[1], m[2]);
}

/// Builds shear 3/// 3 matrix.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Shear factor.
template <typename T>
inline matrix<3, 3, T> shear(const matrix<3, 3, T>& m, const vector<2, T>& v)
{
    matrix<3, 3, T> shear;
    shear[0][1] = v.x;
    shear[1][0] = v.y;

    return m * shear;
}

#pragma mark - 3d transform

/// Create a translation 4 * 4 matrix from 3 scalars.
template <typename T>
inline matrix<4, 4, T> createTranslateMatrix(const vector<3, T>& v)
{
    // clang-format off
    return matrix<4, 4, T>(1,    0,    0,    0,
                           0,    1,    0,    0,
                           0,    0,    1,    0,
                           v[0], v[1], v[2], 1);
    // clang-format on
}

/// Create a rotate 4/// 4 matrix from an axis of 3 scalars and an andgle
/// epressed in radians.
template <typename T, typename U>
inline matrix<4, 4, T> createRotateMatrix(const vector<3, T>& v, const U angle)
{
    const T c = static_cast<T>(math::cos(angle));
    const T s = static_cast<T>(math::sin(angle));

    const auto c_1 = 1 - c;

    const auto xc = v[0] * c_1;
    const auto yc = v[1] * c_1;
    const auto zc = v[2] * c_1;

    const auto xs = v[0] * s;
    const auto ys = v[1] * s;
    const auto zs = v[2] * s;

    // clang-format off
    return matrix<4, 4, T>(
            v[0] * xc + c,  v[1] * xc + zs, v[2] * xc - ys, 0,
            v[0] * yc - zs, v[1] * yc + c,  v[2] * yc + xs, 0,
            v[0] * zc + ys, v[1] * zc - xs, v[2] * zc + c,  0,
            0,              0,              0,              1);
    // clang-format on
}

/// Create a scale 4 * 4 matrix from a vector of 3 components.
template <typename T>
inline matrix<4, 4, T> createScaleMatrix(const vector<3, T>& v)
{
    // clang-format off
    return matrix<4, 4, T>(v[0], 0,    0,    0,
                           0,    v[1], 0,    0,
                           0,    0,    v[2], 0,
                           0,    0,    0,    1);
    // clang-format on
}

/// Builds a translation 4/// 4 matrix created from a vector of 3 components.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Coordinates of a translation vector.
template <typename T>
inline matrix<4, 4, T> translate(const matrix<4, 4, T>& m, const vector<3, T>& v)
{
    return m * createTranslateMatrix(v);
}

/// Builds a scale 4 * 4 matrix created from a vector of 3 components.
///
/// @param m Input matrix multiplied by this scale matrix.
/// @param v Ratio of scaling for each axis.
/// @tparam T Value type used to build the matrix
template <typename T>
inline matrix<4, 4, T> scale(const matrix<4, 4, T>& m, const vector<3, T>& v)
{
    return m * createScaleMatrix(v);
}

/// Builds a rotation 4 * 4 matrix created from an axis vector and an angle.
///
/// @param m Input matrix multiplied by this rotation matrix.
/// @param angle Rotation angle expressed in radians.
/// @param v Rotation axis, recommended to be normalized.
/// @tparam T Value type used to build the matrix.
/// @tparam U Value type of angle.
template <typename T, typename U>
inline matrix<4, 4, T> rotate(const matrix<4, 4, T>& m, const vector<3, T>& v, const U angle)
{
    return m * createRotateMatrix(v, angle);
}

#pragma mark - Projection

/// Creates a matrix for an orthographic parallel viewing volume, using
/// right-handedness.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @param near Near clipping plane.
/// @param far Far clipping plane.
/// @tparam T Value type used to build the matrix.
template <typename T>
inline matrix<4, 4, T> ortho(const T left, const T right, const T bottom, const T top, const T near, const T far)
{
    const T width  = right - left;
    const T height = top - bottom;
    const T depth  = far - near;

    ASSERT(math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));

    // clang-format off
    return matrix<4, 4, T> (
            T(2) / width,            0,                        0,                     0,
            0,                       T(2) / height,            0,                     0,
            0,                       0,                        -T(2) / depth,         0,
            -(right + left) / width, -(top + bottom) / height, -(far + near) / depth, 1
    );
    // clang-format on
}

/// Creates a matrix for projecting two-dimensional coordinates onto the screen.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @tparam T Value type used to build the matrix
template <typename T>
inline matrix<4, 4, T> ortho2D(const T left, const T right, const T bottom, const T top)
{
    // Right-handedness matrix is default.
    return ortho(left, right, bottom, top, T(1), -T(1));
}

/// Creates a right handed frustum matrix.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @param near Distance to the near clipping plane (always positive).
/// @param far Distance to the far clipping plane (always positive).
/// @tparam T Value type used to build the matrix
template <typename T>
inline matrix<4, 4, T> frustum(const T left, const T right, const T bottom, const T top, const T near, const T far)
{
    ASSERT(near > T(0));
    ASSERT(far > T(0));

    const T width  = right - left;
    const T height = top - bottom;
    const T depth  = far - near;

    ASSERT(math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));

    // clang-format off
    return matrix<4, 4, T> (
        (T(2) * near) / width,  0,                       0,                            0,
        0,                      (T(2) * near) / height,  0,                            0,
        (right + left) / width, (top + bottom) / height, -(far + near) / depth,        -1,
        0,                      0,                       -(T(2) * far * near) / depth, 0
    );
    // clang-format on
}

/// Creates a matrix for a right handed, symetric perspective-view frustum.
///
/// @param fovy Specifies the field of view angle in the y direction. Expressed
/// in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
/// in the x direction.
///        The aspect ratio is the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
/// plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
/// (always positive).
/// @tparam T Value type used to build the matrix.
template <typename T>
inline matrix<4, 4, T> perspective(T fovy, T aspect, T near, T far)
{
    ASSERT(near > T(0));
    ASSERT(far > T(0));

    const T depth   = far - near;
    const T tangent = tan(fovy / T(2));

    ASSERT(math::abs(aspect - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(tangent - std::numeric_limits<T>::epsilon()) > T(0));

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

/// Builds a right handed perspective projection matrix based on a field of
/// view.
///
/// @param fov Expressed in radians.
/// @param width Width of the plane (always positive).
/// @param height Height of the plane (always positive).
/// @param near Specifies the distance from the viewer to the near clipping
/// plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
/// (always positive).
/// @tparam T Value type used to build the matrix.
template <typename T>
inline matrix<4, 4, T> perspectiveFov(T fov, T width, T height, T near, T far)
{
    ASSERT(width > T(0));
    ASSERT(height > T(0));
    ASSERT(near > T(0));
    ASSERT(far > T(0));

    return perspective(fov, width / height, near, far);
}

/// Creates a matrix for a right handed, symmetric perspective-view frustum with
/// far plane at infinite.
///
/// @param fovy Specifies the field of view angle in the y direction. Expressed
/// in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
/// in the x direction.
///        The aspect ratio is the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
/// plane (always positive).
/// @tparam T Value type used to build the matrix
template <typename T>
inline matrix<4, 4, T> infinitePerspective(T fovy, T aspect, T near)
{
    ASSERT(near > T(0));
    ASSERT(math::abs(aspect - std::numeric_limits<T>::epsilon()) > T(0));

    const T tangent = math::tan(fovy / T(2));

    ASSERT(math::abs(tangent - std::numeric_limits<T>::epsilon()) > T(0));

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

#pragma mark - Helper functions

/// Map the specified coordinates (v.x, v.y, v.z) into window coordinates.
///
/// @param v Specify the coordinates.
/// @param model Specifies the current modelview matrix
/// @param proj Specifies the current projection matrix
/// @param viewport Specifies the current viewport
/// @return Return the computed window coordinates.
/// @tparam T Native type used for the computation.
/// @tparam U Value type of viewport.
template <typename T, typename U>
inline vector<3, T>
project(const vector<3, T>& v, const matrix<4, 4, T>& model, const matrix<4, 4, T>& proj, const vector<4, U>& viewport)
{
    vector<4, T> tmp(v, T(1));
    tmp = model * tmp;
    tmp = proj * tmp;

    ASSERT(math::abs(tmp.w - std::numeric_limits<T>::epsilon()) > T(0));

    tmp /= tmp.w;

    tmp = tmp * T(0.5) + T(0.5);

    const T x      = static_cast<T>(viewport[0]);
    const T y      = static_cast<T>(viewport[1]);
    const T width  = static_cast<T>(viewport[2]);
    const T height = static_cast<T>(viewport[3]);

    tmp[0] = tmp[0] * width + x;
    tmp[1] = tmp[1] * height + y;

    return vector<3, T>(tmp);
}

/// Map the specified window coordinates (v.x, v.y, v.z) into object coordinates.
///
/// @param v Specify the window coordinates to be mapped.
/// @param model Specifies the modelview matrix
/// @param proj Specifies the projection matrix
/// @param viewport Specifies the viewport
/// @return Returns the computed object coordinates.
/// @tparam T Native type used for the computation.
/// @tparam U Value type of viewport.
template <typename T, typename U>
inline vector<3, T>
unProject(const vector<3, T>& v, const matrix<4, 4, T>& model, const matrix<4, 4, T>& proj, const vector<4, U>& viewport)
{
    const T x      = static_cast<T>(viewport[0]);
    const T y      = static_cast<T>(viewport[1]);
    const T width  = static_cast<T>(viewport[2]);
    const T height = static_cast<T>(viewport[3]);

    ASSERT(math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));

    const matrix<4, 4, T> inv = inverse(proj * model);

    vector<4, T> tmp(v, T(1));
    tmp.x = (tmp.x - x) / width;
    tmp.y = (tmp.y - y) / height;

    tmp = tmp * T(2) - T(1);

    vector<4, T> obj = inv * tmp;

    ASSERT(math::abs(tmp.w - std::numeric_limits<T>::epsilon()) > T(0));

    obj /= obj.w;

    return vector<3, T>(obj);
}

/// Define a picking region
///
/// @param center Center of region.
/// @param delta Width and height of region.
/// @param viewport Specifies the viewport.
/// @tparam T Native type used for the computation.
/// @tparam U Value type of viewport.
template <typename T, typename U>
inline matrix<4, 4, T> pickMatrix(const vector<2, T>& center, const vector<2, T>& delta, const vector<4, U>& viewport)
{
    ASSERT(delta.x > T(0));
    ASSERT(delta.y > T(0));

    const T x      = static_cast<T>(viewport[0]);
    const T y      = static_cast<T>(viewport[1]);
    const T width  = static_cast<T>(viewport[2]);
    const T height = static_cast<T>(viewport[3]);

    const vector<3, T> translate_tmp = {
    (width - T(2) * (center.x - x)) / delta.x, (height - T(2) * (center.y - y)) / delta.y, T(0)};

    const vector<3, T> scale_tmp = {width / delta.x, height / delta.y, T(1)};

    // Translate and scale the picked region to the entire window
    const matrix<4, 4, T> result = createTranslateMatrix(translate_tmp);
    return scale(result, scale_tmp);
}

/// Build a right handed look at view matrix.
///
/// @param eye Position of the camera
/// @param center Position where the camera is looking at
/// @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
template <typename T>
inline matrix<4, 4, T> lookAt(const vector<3, T>& eye, const vector<3, T>& center, const vector<3, T>& up)
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

} // namespace math

} // namespace framework

#endif
