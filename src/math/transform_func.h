#ifndef FRAMEWORK_MATH_TRANSFORM_TYPE_H
#define FRAMEWORK_MATH_TRANSFORM_TYPE_H

#include <math/matrix_type.h>
#include <math/trigonometric_func.h>

// TODO: Ensure only float type for all functions.

namespace framework {

namespace math {

#pragma mark - Types declarations

template <U32 C, U32 R, typename T>
using Matrix = matrix_impl::Matrix<C, R, T>;

template <U32 N, typename T>
using Vector = vector_impl::Vector<N, T>;

#pragma mark - 2d transform

/// Builds a translation 3 * 3 matrix created from a vector of 2 components.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Coordinates of a translation vector.
template <typename T>
inline Matrix<3, 3, T> translate(const Matrix<3, 3, T>& m, const Vector<2, T>& v)
{
    return Matrix<3, 3, T>(m[0], m[1], m[0] * v[0] + m[1] * v[1] + m[2]);
}

/// Builds a rotation 3 * 3 matrix created from an angle.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param angle Rotation angle expressed in radians.
template <typename T, typename U>
inline Matrix<3, 3, T> rotate(const Matrix<3, 3, T>& m, const U angle)
{
    const T c = static_cast<T>(math::cos(angle));
    const T s = static_cast<T>(math::sin(angle));

    return Matrix<3, 3, T>(m[0] * c + m[1] * s, m[0] * -s + m[1] * c, m[2]);
}

/// Builds a scale 3 * 3 matrix created from a vector of 2 components.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Coordinates of a scale vector.
template <typename T>
inline Matrix<3, 3, T> scale(const Matrix<3, 3, T>& m, const Vector<2, T>& v)
{
    return Matrix<3, 3, T>(m[0] * v[0], m[1] * v[1], m[2]);
}

/// Builds shear 3 * 3 matrix.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Shear factor.
template <typename T>
inline Matrix<3, 3, T> shear(const Matrix<3, 3, T>& m, const Vector<2, T>& v)
{
    Matrix<3, 3, T> shear;
    shear[0][1] = v.x;
    shear[1][0] = v.y;

    return m * shear;
}

#pragma mark - 3d transform

/// Create a translation 4 * 4 matrix from 3 scalars.
template <typename T>
inline Matrix<4, 4, T> createTranslateMatrix(const Vector<3, T>& v)
{
    // clang-format off
    return Matrix<4, 4, T>(1,    0,    0,    0,
                           0,    1,    0,    0,
                           0,    0,    1,    0,
                           v[0], v[1], v[2], 1);
    // clang-format on
}

/// Create a rotate 4 * 4 matrix from an axis of 3 scalars and an andgle
/// epressed in radians.
template <typename T, typename U>
inline Matrix<4, 4, T> createRotateMatrix(const Vector<3, T>& v, const U angle)
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
    return matrix_impl::Matrix<4, 4, T>(
            v[0] * xc + c,  v[1] * xc + zs, v[2] * xc - ys, 0,
            v[0] * yc - zs, v[1] * yc + c,  v[2] * yc + xs, 0,
            v[0] * zc + ys, v[1] * zc - xs, v[2] * zc + c,  0,
            0,              0,              0,              1);
    // clang-format on
}

/// Create a scale 4 * 4 matrix from a vector of 3 components.
template <typename T>
inline Matrix<4, 4, T> createScaleMatrix(const Vector<3, T>& v)
{
    // clang-format off
    return Matrix<4, 4, T>(v[0], 0,    0,    0,
                           0,    v[1], 0,    0,
                           0,    0,    v[2], 0,
                           0,    0,    0,    1);
    // clang-format on
}

/// Builds a translation 4 * 4 matrix created from a vector of 3 components.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param v Coordinates of a translation vector.
template <typename T>
inline Matrix<4, 4, T> translate(const Matrix<4, 4, T>& m, const Vector<3, T>& v)
{
    return m * createTranslateMatrix(v);
}

/// Builds a scale 4 * 4 matrix created from a vector of 3 components.
///
/// @param m Input matrix multiplied by this scale matrix.
/// @param v Ratio of scaling for each axis.
/// @tparam T Value type used to build the matrix
template <typename T>
inline Matrix<4, 4, T> scale(const Matrix<4, 4, T>& m, const Vector<3, T>& v)
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
inline Matrix<4, 4, T> rotate(const Matrix<4, 4, T>& m, const Vector<3, T>& v, const U angle)
{
    return m * createRotateMatrix(v, angle);
}

#pragma mark - Projection

/// Creates a matrix for an orthographic parallel viewing volume, using right-handedness.
///
/// @param left Left clipping plane.
/// @param right Right clipping plane.
/// @param bottom Bottom clipping plane.
/// @param top Top clipping plane.
/// @param near Near clipping plane.
/// @param far Far clipping plane.
/// @tparam T Value type used to build the matrix.
template <typename T>
inline Matrix<4, 4, T> ortho(const T left, const T right, const T bottom, const T top, const T near, const T far)
{
    const T width  = right - left;
    const T height = top - bottom;
    const T depth  = far - near;

    ASSERT(math::abs(width - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(height - std::numeric_limits<T>::epsilon()) > T(0));
    ASSERT(math::abs(depth - std::numeric_limits<T>::epsilon()) > T(0));

    // clang-format off
    return Matrix<4, 4, T> (
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
inline Matrix<4, 4, T> ortho2D(const T left, const T right, const T bottom, const T top)
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
inline Matrix<4, 4, T> frustum(const T left, const T right, const T bottom, const T top, const T near, const T far)
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
    return Matrix<4, 4, T> (
        (T(2) * near) / width,  0,                       0,                            0,
        0,                      (T(2) * near) / height,  0,                            0,
        (right + left) / width, (top + bottom) / height, -(far + near) / depth,        -1,
        0,                      0,                       -(T(2) * far * near) / depth, 0
    );
    // clang-format on
}

/// Creates a matrix for a right handed, symetric perspective-view frustum.
///
/// @param fovy Specifies the field of view angle in the y direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction.
///        The aspect ratio is the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
/// @tparam T Value type used to build the matrix.
template <typename T>
inline Matrix<4, 4, T> perspective(T fovy, T aspect, T near, T far)
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
    return Matrix<4, 4, T> (
        cotangent / aspect, 0,         0,                            0,
        0,                  cotangent, 0,                            0,
        0,                  0,         -(far + near) / depth,        -1,
        0,                  0,         -(T(2) * far * near) / depth, 0
    );
    // clang-format on
}


/// Builds a right handed perspective projection matrix based on a field of view.
///
/// @param fov Expressed in radians.
/// @param width Width of the plane (always positive).
/// @param height Height of the plane (always positive).
/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
/// @tparam T Value type used to build the matrix.
template <typename T>
inline Matrix<4, 4, T> perspectiveFov(T fov, T width, T height, T near, T far)
{
    ASSERT(width > T(0));
    ASSERT(height > T(0));
    ASSERT(near > T(0));
    ASSERT(far > T(0));

    return perspective(fov, width / height, near, far);
}

/// Creates a matrix for a right handed, symmetric perspective-view frustum with far plane at infinite.
///
/// @param fovy Specifies the field of view angle in the y direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction.
///        The aspect ratio is the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
/// @tparam T Value type used to build the matrix
template <typename T>
inline Matrix<4, 4, T> infinitePerspective(T fovy, T aspect, T near)
{
    ASSERT(near > T(0));
    ASSERT(math::abs(aspect - std::numeric_limits<T>::epsilon()) > T(0));

    const T tangent = math::tan(fovy / T(2));

    ASSERT(math::abs(tangent - std::numeric_limits<T>::epsilon()) > T(0));

    const T cotangent = T(1) / tangent;
    const T epsilon   = std::numeric_limits<T>::epsilon();

    // clang-format off
    return Matrix<4, 4, T> (
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
inline Vector<3, T>
project(const Vector<3, T>& v, const Matrix<4, 4, T>& model, const Matrix<4, 4, T>& proj, const Vector<4, U>& viewport)
{
    Vector<4, T> tmp(v, T(1));
    tmp = model * tmp;
    tmp = proj * tmp;

    tmp /= tmp.w;

    tmp = tmp * T(0.5) + T(0.5);

    tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
    tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

    return Vector<3, T>(tmp);
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
inline Vector<3, T>
unProject(const Vector<3, T>& v, const Matrix<4, 4, T>& model, const Matrix<4, 4, T>& proj, const Vector<4, U>& viewport)
{
    const Matrix<4, 4, T> inv = inverse(proj * model);

    Vector<4, T> tmp(v, T(1));
    tmp.x = (tmp.x - T(viewport[0])) / T(viewport[2]);
    tmp.y = (tmp.y - T(viewport[1])) / T(viewport[3]);

    tmp = tmp * T(2) - T(1);

    Vector<4, T> obj = inv * tmp;
    obj /= obj.w;

    return Vector<3, T>(obj);
}


/// Define a picking region
///
/// @param center Center of region.
/// @param delta Width and height of region.
/// @param viewport Specifies the viewport.
/// @tparam T Native type used for the computation.
/// @tparam U Value type of viewport.
template <typename T, typename U>
inline Matrix<4, 4, T> pickMatrix(const Vector<2, T>& center, const Vector<2, T>& delta, const Vector<4, U>& viewport)
{
    ASSERT(delta.x > T(0) && delta.y > T(0));

    Vector<3, T> translate_tmp = {
        (static_cast<T>(viewport[2]) - T(2) * (center.x - static_cast<T>(viewport[0]))) / delta.x,
        (static_cast<T>(viewport[3]) - T(2) * (center.y - static_cast<T>(viewport[1]))) / delta.y,
        T(0)
    };

    Vector<3, T> scale_tmp = {
        static_cast<T>(viewport[2]) / delta.x,
        static_cast<T>(viewport[3]) / delta.y,
        T(1)
    };

    // Translate and scale the picked region to the entire window
    Matrix<4, 4, T> result = createTranslateMatrix(translate_tmp);
    return scale(result, scale_tmp);
}

} // namespace math

} // namespace framework

#endif

/*



/// Build a right handed look at view matrix.
///
/// @param eye Position of the camera
/// @param center Position where the camera is looking at
/// @param up Normalized up vector, how the camera is oriented. Typically (0, 0,
1)
/// @see gtc_matrix_transform
/// @see - frustum(T const & left, T const & right, T const & bottom, T const &
top, T const & nearVal, T const &
farVal) frustum(T const & left, T const & right, T const & bottom, T const &
top, T const & nearVal, T const & farVal)
template <typename T, precision P>
GLM_FUNC_DECL tmat4x4<T, P> lookAt(
tvec3<T, P> const & eye,
tvec3<T, P> const & center,
tvec3<T, P> const & up);


/// @}

*/
