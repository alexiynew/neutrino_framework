#ifndef FRAMEWORK_MATH_TRANSFORM_TYPE_H
#define FRAMEWORK_MATH_TRANSFORM_TYPE_H

#include <math/matrix_type.h>
#include <math/trigonometric_func.h>

namespace framework {

namespace math {

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
template <typename T>
inline Matrix<3, 3, T> rotate(const Matrix<3, 3, T>& m, const T angle)
{
    T const c = cos(angle);
    T const s = sin(angle);

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

/// Builds an horizontal (parallel to the x axis) shear 3 * 3 matrix.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param s Shear factor.
template <typename T>
inline Matrix<3, 3, T> shearX(const Matrix<3, 3, T>& m, const T& s)
{
    Matrix<3, 3, T> shear;
    shear[0][1] = s;

    return m * shear;
}

/// Builds a vertical (parallel to the y axis) shear 3 * 3 matrix.
///
/// @param m Input matrix multiplied by this translation matrix.
/// @param s Shear factor.
template <typename T>
inline Matrix<3, 3, T> shearY(const Matrix<3, 3, T>& m, const T& s)
{
    Matrix<3, 3, T> shear;
    shear[1][0] = s;

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
template <typename T>
inline Matrix<4, 4, T> createRotateMatrix(const Vector<3, T>& v, T angle)
{
    auto c = cos(angle);
    auto s = sin(angle);

    auto c_1 = 1 - c;

    auto xc = v[0] * c_1;
    auto yc = v[1] * c_1;
    auto zc = v[2] * c_1;

    auto xs = v[0] * s;
    auto ys = v[1] * s;
    auto zs = v[2] * s;

    // clang-format off
    return matrix_impl::Matrix<4, 4, T>(
            v[0] * xc + c, v[1] * xc + zs, v[2] * xc - ys, 0,
            v[0] * yc - zs, v[1] * yc + c, v[2] * yc + xs, 0,
            v[0] * zc + ys, v[1] * zc - xs, v[2] * zc + c, 0,
            0,              0,              0,             1);
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

} // namespace math

} // namespace framework

#endif

/*


/// Builds a rotation 4 * 4 matrix created from an axis vector and an angle.
///
/// @param m Input matrix multiplied by this rotation matrix.
/// @param angle Rotation angle expressed in radians.
/// @param axis Rotation axis, recommended to be normalized.
/// @tparam T Value type used to build the matrix. Supported: half, float or
double.
/// @see gtc_matrix_transform
/// @see - rotate(tmat4x4<T, P> const & m, T angle, T x, T y, T z)
/// @see - rotate(T angle, tvec3<T, P> const & v)
template <typename T, precision P>
GLM_FUNC_DECL tmat4x4<T, P> rotate(
tmat4x4<T, P> const & m,
T angle,
tvec3<T, P> const & axis);


/// Creates a matrix for an orthographic parallel viewing volume, using the
default handedness.
///
/// @param left
/// @param right
/// @param bottom
/// @param top
/// @param zNear
/// @param zFar
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const
& top)
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> ortho(
T left,
T right,
T bottom,
T top,
T zNear,
T zFar);

/// Creates a matrix for an orthographic parallel viewing volume, using
left-handedness.
///
/// @param left
/// @param right
/// @param bottom
/// @param top
/// @param zNear
/// @param zFar
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const
& top)
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> orthoLH(
T left,
T right,
T bottom,
T top,
T zNear,
T zFar);

/// Creates a matrix for an orthographic parallel viewing volume, using
right-handedness.
///
/// @param left
/// @param right
/// @param bottom
/// @param top
/// @param zNear
/// @param zFar
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const
& top)
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> orthoRH(
T left,
T right,
T bottom,
T top,
T zNear,
T zFar);

/// Creates a matrix for projecting two-dimensional coordinates onto the screen.
///
/// @param left
/// @param right
/// @param bottom
/// @param top
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const
& top, T const & zNear, T const & zFar)
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> ortho(
T left,
T right,
T bottom,
T top);

/// Creates a frustum matrix with default handedness.
///
/// @param left
/// @param right
/// @param bottom
/// @param top
/// @param near
/// @param far
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> frustum(
T left,
T right,
T bottom,
T top,
T near,
T far);

/// Creates a left handed frustum matrix.
///
/// @param left
/// @param right
/// @param bottom
/// @param top
/// @param near
/// @param far
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> frustumLH(
T left,
T right,
T bottom,
T top,
T near,
T far);

/// Creates a right handed frustum matrix.
///
/// @param left
/// @param right
/// @param bottom
/// @param top
/// @param near
/// @param far
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> frustumRH(
T left,
T right,
T bottom,
T top,
T near,
T far);

/// Creates a matrix for a symetric perspective-view frustum based on the
default handedness.
///
/// @param fovy Specifies the field of view angle in the y direction. Expressed
in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
(always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> perspective(
T fovy,
T aspect,
T near,
T far);

/// Creates a matrix for a right handed, symetric perspective-view frustum.
///
/// @param fovy Specifies the field of view angle, in degrees, in the y
direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
(always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveRH(
T fovy,
T aspect,
T near,
T far);

/// Creates a matrix for a left handed, symetric perspective-view frustum.
///
/// @param fovy Specifies the field of view angle, in degrees, in the y
direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
(always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveLH(
T fovy,
T aspect,
T near,
T far);

/// Builds a perspective projection matrix based on a field of view and the
default handedness.
///
/// @param fov Expressed in radians.
/// @param width
/// @param height
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
(always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveFov(
T fov,
T width,
T height,
T near,
T far);

/// Builds a right handed perspective projection matrix based on a field of
view.
///
/// @param fov Expressed in radians.
/// @param width
/// @param height
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
(always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveFovRH(
T fov,
T width,
T height,
T near,
T far);

/// Builds a left handed perspective projection matrix based on a field of view.
///
/// @param fov Expressed in radians.
/// @param width
/// @param height
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @param far Specifies the distance from the viewer to the far clipping plane
(always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveFovLH(
T fov,
T width,
T height,
T near,
T far);

/// Creates a matrix for a symmetric perspective-view frustum with far plane at
infinite with default handedness.
///
/// @param fovy Specifies the field of view angle, in degrees, in the y
direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> infinitePerspective(
T fovy, T aspect, T near);

/// Creates a matrix for a left handed, symmetric perspective-view frustum with
far plane at infinite.
///
/// @param fovy Specifies the field of view angle, in degrees, in the y
direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> infinitePerspectiveLH(
T fovy, T aspect, T near);

/// Creates a matrix for a right handed, symmetric perspective-view frustum with
far plane at infinite.
///
/// @param fovy Specifies the field of view angle, in degrees, in the y
direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> infinitePerspectiveRH(
T fovy, T aspect, T near);

/// Creates a matrix for a symmetric perspective-view frustum with far plane at
infinite for graphics hardware that
doesn't support depth clamping.
///
/// @param fovy Specifies the field of view angle, in degrees, in the y
direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> tweakedInfinitePerspective(
T fovy, T aspect, T near);

/// Creates a matrix for a symmetric perspective-view frustum with far plane at
infinite for graphics hardware that
doesn't support depth clamping.
///
/// @param fovy Specifies the field of view angle, in degrees, in the y
direction. Expressed in radians.
/// @param aspect Specifies the aspect ratio that determines the field of view
in the x direction. The aspect ratio is
the ratio of x (width) to y (height).
/// @param near Specifies the distance from the viewer to the near clipping
plane (always positive).
/// @param ep
/// @tparam T Value type used to build the matrix. Currently supported: half
(not recommanded), float or double.
/// @see gtc_matrix_transform
template <typename T>
GLM_FUNC_DECL tmat4x4<T, defaultp> tweakedInfinitePerspective(
T fovy, T aspect, T near, T ep);

/// Map the specified object coordinates (obj.x, obj.y, obj.z) into window
coordinates.
///
/// @param obj Specify the object coordinates.
/// @param model Specifies the current modelview matrix
/// @param proj Specifies the current projection matrix
/// @param viewport Specifies the current viewport
/// @return Return the computed window coordinates.
/// @tparam T Native type used for the computation. Currently supported: half
(not recommanded), float or double.
/// @tparam U Currently supported: Floating-point types and integer types.
/// @see gtc_matrix_transform
template <typename T, typename U, precision P>
GLM_FUNC_DECL tvec3<T, P> project(
tvec3<T, P> const & obj,
tmat4x4<T, P> const & model,
tmat4x4<T, P> const & proj,
tvec4<U, P> const & viewport);

/// Map the specified window coordinates (win.x, win.y, win.z) into object
coordinates.
///
/// @param win Specify the window coordinates to be mapped.
/// @param model Specifies the modelview matrix
/// @param proj Specifies the projection matrix
/// @param viewport Specifies the viewport
/// @return Returns the computed object coordinates.
/// @tparam T Native type used for the computation. Currently supported: half
(not recommanded), float or double.
/// @tparam U Currently supported: Floating-point types and integer types.
/// @see gtc_matrix_transform
template <typename T, typename U, precision P>
GLM_FUNC_DECL tvec3<T, P> unProject(
tvec3<T, P> const & win,
tmat4x4<T, P> const & model,
tmat4x4<T, P> const & proj,
tvec4<U, P> const & viewport);

/// Define a picking region
///
/// @param center
/// @param delta
/// @param viewport
/// @tparam T Native type used for the computation. Currently supported: half
(not recommanded), float or double.
/// @tparam U Currently supported: Floating-point types and integer types.
/// @see gtc_matrix_transform
template <typename T, precision P, typename U>
GLM_FUNC_DECL tmat4x4<T, P> pickMatrix(
tvec2<T, P> const & center,
tvec2<T, P> const & delta,
tvec4<U, P> const & viewport);

/// Build a look at view matrix based on the default handedness.
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
GLM_FUNC_DECL tmat4x4<T, P> lookAtRH(
tvec3<T, P> const & eye,
tvec3<T, P> const & center,
tvec3<T, P> const & up);

/// Build a left handed look at view matrix.
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
GLM_FUNC_DECL tmat4x4<T, P> lookAtLH(
tvec3<T, P> const & eye,
tvec3<T, P> const & center,
tvec3<T, P> const & up);

/// @}

*/
