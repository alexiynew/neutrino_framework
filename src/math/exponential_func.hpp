#ifndef FRAMEWORK_MATH_EXPONENTIAL_FUNC_HPP
#define FRAMEWORK_MATH_EXPONENTIAL_FUNC_HPP

#include <cmath>

#include <common_types.hpp>

namespace framework {

namespace math {

/// Returns 'base' raised to the power 'exponent'.
using ::std::pow;

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> pow(const TVec<4, T>& base, const TVec<4, T>& exponent)
{
    return TVec<4, T>(pow(base.x, exponent.x), pow(base.y, exponent.y), pow(base.z, exponent.z), pow(base.w, exponent.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> pow(const TVec<3, T>& base, const TVec<3, T>& exponent)
{
    return TVec<3, T>(pow(base.x, exponent.x), pow(base.y, exponent.y), pow(base.z, exponent.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> pow(const TVec<2, T>& base, const TVec<2, T>& exponent)
{
    return TVec<2, T>(pow(base.x, exponent.x), pow(base.y, exponent.y));
}

/// Returns the natural exponentiation of x, i.e., e^x.
using ::std::exp;

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> exp(const TVec<4, T>& a)
{
    return TVec<4, T>(exp(a.x), exp(a.y), exp(a.z), exp(a.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> exp(const TVec<3, T>& a)
{
    return TVec<3, T>(exp(a.x), exp(a.y), exp(a.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> exp(const TVec<2, T>& a)
{
    return TVec<2, T>(exp(a.x), exp(a.y));
}

/// Returns the natural logarithm of v, i.e.,
/// returns the value y which satisfies the equation x = e^y.
/// Results are undefined if v <= 0.
using ::std::log;

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> log(const TVec<4, T>& a)
{
    return TVec<4, T>(log(a.x), log(a.y), log(a.z), log(a.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> log(const TVec<3, T>& a)
{
    return TVec<3, T>(log(a.x), log(a.y), log(a.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> log(const TVec<2, T>& a)
{
    return TVec<2, T>(log(a.x), log(a.y));
}

/// Returns 2 raised to the v power.
using ::std::exp2;

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> exp2(const TVec<4, T>& a)
{
    return TVec<4, T>(exp2(a.x), exp2(a.y), exp2(a.z), exp2(a.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> exp2(const TVec<3, T>& a)
{
    return TVec<3, T>(exp2(a.x), exp2(a.y), exp2(a.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> exp2(const TVec<2, T>& a)
{
    return TVec<2, T>(exp2(a.x), exp2(a.y));
}

/// Returns the base 2 log of x, i.e., returns the value y,
/// which satisfies the equation x = 2 ^ y.
using ::std::log2;

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> log2(const TVec<4, T>& a)
{
    return TVec<4, T>(log2(a.x), log2(a.y), log2(a.z), log2(a.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> log2(const TVec<3, T>& a)
{
    return TVec<3, T>(log2(a.x), log2(a.y), log2(a.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> log2(const TVec<2, T>& a)
{
    return TVec<2, T>(log2(a.x), log2(a.y));
}

/// Returns the positive square root of v.
using ::std::sqrt;

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> sqrt(const TVec<4, T>& a)
{
    return TVec<4, T>(sqrt(a.x), sqrt(a.y), sqrt(a.z), sqrt(a.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> sqrt(const TVec<3, T>& a)
{
    return TVec<3, T>(sqrt(a.x), sqrt(a.y), sqrt(a.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> sqrt(const TVec<2, T>& a)
{
    return TVec<2, T>(sqrt(a.x), sqrt(a.y));
}

/// Returns the reciprocal of the positive square root of v.
template <typename T>
inline T invsqrt(const T& v)
{
    return T(1) / std::sqrt(v);
}

template <typename T, template <U32, typename> class TVec>
inline TVec<4, T> invsqrt(const TVec<4, T>& a)
{
    return TVec<4, T>(invsqrt(a.x), invsqrt(a.y), invsqrt(a.z), invsqrt(a.w));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<3, T> invsqrt(const TVec<3, T>& a)
{
    return TVec<3, T>(invsqrt(a.x), invsqrt(a.y), invsqrt(a.z));
}

template <typename T, template <U32, typename> class TVec>
inline TVec<2, T> invsqrt(const TVec<2, T>& a)
{
    return TVec<2, T>(invsqrt(a.x), invsqrt(a.y));
}

} // namespace math

} // namespace framework

#endif
