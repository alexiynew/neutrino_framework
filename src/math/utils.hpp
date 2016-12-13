#ifndef FRAMEWORK_MATH_UTILS_HPP
#define FRAMEWORK_MATH_UTILS_HPP

#include <ostream>
#include <type_traits>

namespace framework {

namespace math {

namespace utils {

// TODO: rename it all, to with names conventions id:3

// helpers
template <typename T>
struct default_value
{
    constexpr const static T value = T(1);
};

template <>
struct default_value<bool>
{
    constexpr const static bool value = false;
};

template <typename T>
struct is_floating_point_or_integer
{
    constexpr const static bool value = std::is_arithmetic<T>::value && !std::is_same<bool, T>::value;
};

template <unsigned int N>
struct type_creator
{
    template <typename TResult, typename F>
    static inline TResult create(F&&);
};

template <>
template <typename TResult, typename F>
inline TResult type_creator<4>::create(F&& opp)
{
    return TResult(opp(0), opp(1), opp(2), opp(3));
}

template <>
template <typename TResult, typename F>
inline TResult type_creator<3>::create(F&& opp)
{
    return TResult(opp(0), opp(1), opp(2));
}

template <>
template <typename TResult, typename F>
inline TResult type_creator<2>::create(F&& opp)
{
    return TResult(opp(0), opp(1));
}

template <unsigned int N, typename T, typename F, typename TResult = typename std::result_of<F(T)>::type, template <unsigned int, typename> class TVec>
inline TVec<N, TResult> createVector(const TVec<N, T>& v, F&& opp)
{
    return type_creator<N>::template create<TVec<N, TResult>>([&](const unsigned int index) { return opp(v[index]); });
}

template <unsigned int N, typename T, typename U, typename F, typename TResult = typename std::result_of<F(T, U)>::type, template <unsigned int, typename> class TVec>
static inline TVec<N, TResult> createVector(const TVec<N, T>& lhs, const TVec<N, U>& rhs, F&& opp)
{
    return type_creator<N>::template create<TVec<N, TResult>>(
    [&](const unsigned int index) { return opp(lhs[index], rhs[index]); });
}

} // namespace utils

template <unsigned int N, typename T, template <unsigned int, typename> class TVec>
std::ostream& operator<<(std::ostream& os, const TVec<N, T>& v)
{
    os << "[";
    for (unsigned int i = 0; i < N; ++i) {
        os << v[i] << (i < N - 1 ? ", " : "");
    }
    os << "]";
    return os;
}

template <unsigned int C, unsigned int R, typename T, template <unsigned int, unsigned int, typename> class TMat>
std::ostream& operator<<(std::ostream& os, const TMat<C, R, T>& m)
{
    os << "[";
    for (unsigned int i = 0; i < C; ++i) {
        os << m[i] << (i < C - 1 ? "\n " : "");
    }
    os << "]";
    return os;
}

} // namespace math

} // namespace framework

#endif
