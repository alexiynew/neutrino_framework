#ifndef FRAMEWORK_MATH_UTILS_H
#define FRAMEWORK_MATH_UTILS_H

#include <ostream>

#include <type_traits>
#include <common_types.h>

namespace framework {

namespace math {

namespace utils {

// helpers
template <typename T>
struct default_init
{
    constexpr const static T value = T(1);
};

template <>
struct default_init<bool>
{
    constexpr const static bool value = false;
};

template <typename T>
struct floating_point_or_integer
{
    constexpr const static bool value = std::is_arithmetic<T>::value && !std::is_same<bool, T>::value;
};

template <U32 N>
struct vec_helper
{
    template <typename T, typename F, typename TResult = typename std::result_of<F(T)>::type, template<U32, typename> class TVec>
    static inline TVec<N, TResult> apply(const TVec<N, T>&, F&&);

    template <typename T, typename U, typename F, typename TResult = typename std::result_of<F(T, U)>::type, template<U32, typename> class TVec>
    static inline TVec<N, TResult> apply(const TVec<N, T>&, const TVec<N, U>&, F&&);
};

template <>
template <typename T, typename F, typename TResult, template<U32, typename> class TVec>
inline TVec<4, TResult> vec_helper<4>::apply(const TVec<4, T>& v, F&& opp)
{
    return TVec<4, TResult>(opp(v.x), opp(v.y), opp(v.z), opp(v.w));
}

template <>
template <typename T, typename F, typename TResult, template<U32, typename> class TVec>
inline TVec<3, TResult> vec_helper<3>::apply(const TVec<3, T>& v, F&& opp)
{
    return TVec<3, TResult>(opp(v.x), opp(v.y), opp(v.z));
}

template <>
template <typename T, typename F, typename TResult, template<U32, typename> class TVec>
inline TVec<2, TResult> vec_helper<2>::apply(const TVec<2, T>& v, F&& opp)
{
    return TVec<2, TResult>(opp(v.x), opp(v.y));
}

template <>
template <typename T, typename U, typename F, typename TResult, template<U32, typename> class TVec>
inline TVec<4, TResult> vec_helper<4>::apply(const TVec<4, T>& l, const TVec<4, U>& r, F&& opp)
{
    return TVec<4, TResult>(opp(l.x, r.x), opp(l.y, r.y), opp(l.z, r.z), opp(l.w, r.w));
}

template <>
template <typename T, typename U, typename F, typename TResult, template<U32, typename> class TVec>
inline TVec<3, TResult> vec_helper<3>::apply(const TVec<3, T>& l, const TVec<3, U>& r, F&& opp)
{
    return TVec<3, TResult>(opp(l.x, r.x), opp(l.y, r.y), opp(l.z, r.z));
}

template <>
template <typename T, typename U, typename F, typename TResult, template<U32, typename> class TVec>
inline TVec<2, TResult> vec_helper<2>::apply(const TVec<2, T>& l, const TVec<2, U>& r, F&& opp)
{
    return TVec<2, TResult>(opp(l.x, r.x), opp(l.y, r.y));
}


template <U32 N>
struct type_creator
{
    template <typename TResult, typename F>
    static inline TResult create(F&&);
};

template<>
template <typename TResult, typename F>
inline TResult type_creator<4>::create(F&& opp)
{
    return TResult(opp(0), opp(1), opp(2), opp(3));
}

template<>
template <typename TResult, typename F>
inline TResult type_creator<3>::create(F&& opp)
{
    return TResult(opp(0), opp(1), opp(2));
}

template<>
template <typename TResult, typename F>
inline TResult type_creator<2>::create(F&& opp)
{
    return TResult(opp(0), opp(1));
}

} // namespace utils

template <U32 N, typename T, template<U32, typename> class TVec>
std::ostream& operator<<(std::ostream& os, const TVec<N, T>& v)
{
    os << "[";
    for (U32 i = 0; i < N; ++i) {
        os << v[i] << (i < N - 1 ? ", " : "");
    }
    os << "]";
    return os;
}

template <U32 C, U32 R, typename T, template<U32, U32, typename> class TMat>
std::ostream& operator<<(std::ostream& os, const TMat<C, R, T>& m)
{
    os << "[";
    for (U32 i = 0; i < C; ++i) {
        os << m[i] << (i < C - 1 ? "\n " : "");
    }
    os << "]";
    return os;
}

} // namespace math

} // namespace framework

#endif // FRAMEWORK_MATH_UTILS_H
