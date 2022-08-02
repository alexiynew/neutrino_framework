#ifndef MATH_INC_BEZIER_FUNCTIONS_HPP
#define MATH_INC_BEZIER_FUNCTIONS_HPP

#include <math/inc/vector_type.hpp>

namespace framework::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_bezier_functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Point on quadratic bezier curve with respect ot factor t.
///
/// A Bezier curve is defined by a set of control points p1, p2, p3.
/// The first and last control points are always the endpoints of the curve.
/// However, the intermediate control point generally do not lie on the curve.
/// The t factor represents how close resulting point is to p1 or p3. Assumed to be in range [0, 1].
/// For t = 0 result is p1, for t = 1 result is p3.
///
/// @param p1 First control point (on curve).
/// @param p2 Second control point (off curve).
/// @param p3 Third control point (on curve).
/// @param t Factor. Assumed to be in range [0, 1];
///
/// @return Point on quadratic bezier curve.

template <std::size_t N, typename T, typename U, typename R = std::enable_if_t<std::is_floating_point_v<T>, T>>
inline Vector<N, R> quadratic_bezier(const Vector<N, T>& p1, const Vector<N, T>& p2, const Vector<N, T>& p3, const U& t)
{
    const U t1 = (static_cast<U>(1) - t);
    return t1 * t1 * p1 + 2 * t1 * t * p2 + t * t * p3;
}

/// @brief Point on cubic bezier curve with respect ot factor t.
///
/// A Bezier curve is defined by a set of control points p1, p2, p3, p4.
/// The first and last control points are always the endpoints of the curve.
/// However, the intermediate control point generally do not lie on the curve.
/// The t factor represents how close resulting point is to p1 or p4. Assumed to be in range [0, 1].
/// For t = 0 result is p1, for t = 1 result is p4.
///
/// @param p1 First control point (on curve).
/// @param p2 Second control point (off curve).
/// @param p3 Third control point (off curve).
/// @param p4 Fourth control point (on curve).
/// @param t Factor. Assumed to be in range [0, 1];
///
/// @return Point on cubic bezier curve.
template <std::size_t N, typename T, typename U, typename R = std::enable_if_t<std::is_floating_point_v<T>, T>>
inline Vector<N, R> cubic_bezier(const Vector<N, T>& p1,
                                 const Vector<N, T>& p2,
                                 const Vector<N, T>& p3,
                                 const Vector<N, T>& p4,
                                 const U& t)
{
    const U t1 = (static_cast<U>(1) - t);
    return t1 * t1 * t1 * p1 + 3 * t1 * t1 * t * p2 + 3 * t1 * t * t * p3 + t * t * t * p4;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::math

#endif
