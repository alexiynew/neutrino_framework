#ifndef FRAMEWORK_MATH_INC_RELATIONAL_FUNCTIONS_DETAILS_HPP
#define FRAMEWORK_MATH_INC_RELATIONAL_FUNCTIONS_DETAILS_HPP

#ifndef FRAMEWORK_MATH_DETAILS
    #error You should include math/math.hpp instead of relational_functions_details.hpp
#endif

#include <functional>

#include <math/inc/common_functions.hpp>
#include <math/inc/matrix_type.hpp>
#include <math/inc/vector_type.hpp>

namespace framework::math::relational_functions_details
{

template <typename T>
inline bool almost_equal_implementation(const T& a, const T& b, std::int32_t ulp, std::true_type /*unused*/)
{
    const auto scaled_epsilon = std::numeric_limits<T>::epsilon() * static_cast<T>(ulp);
    const auto difference     = framework::math::abs(a - b);
    return difference < scaled_epsilon || difference < std::numeric_limits<T>::min();
}

template <typename T>
inline bool almost_equal_implementation(const T& a, const T& b, std::int32_t /*unused*/, std::false_type /*unused*/)
{
    return a == b;
}

template <std::size_t N, typename T>
inline bool almost_equal_implementation(const Vector<N, T>& a, const Vector<N, T>& b, std::int32_t ulp = 0)
{
    constexpr Vector<N, bool> true_vector{true};
    return true_vector == transform(a, b, [ulp](const T& component_a, const T& component_b) {
               return almost_equal_implementation(component_a, component_b, ulp, std::is_floating_point<T>{});
           });
}

template <std::size_t C, std::size_t R, typename T>
inline bool almost_equal_implementation(const Matrix<C, R, T>& a, const Matrix<C, R, T>& b, std::int32_t ulp = 0)
{
    for (std::size_t i = 0; i < C; ++i) {
        if (!almost_equal_implementation(a[i], b[i], ulp)) {
            return false;
        }
    }
    return true;
}

inline bool any_implementation(const Vector<4, bool>& v)
{
    return v.x || v.y || v.z || v.w;
}

inline bool any_implementation(const Vector<3, bool>& v)
{
    return v.x || v.y || v.z;
}

inline bool any_implementation(const Vector<2, bool>& v)
{
    return v.x || v.y;
}

inline bool all_implementation(const Vector<4, bool>& v)
{
    return v.x && v.y && v.z && v.w;
}

inline bool all_implementation(const Vector<3, bool>& v)
{
    return v.x && v.y && v.z;
}

inline bool all_implementation(const Vector<2, bool>& v)
{
    return v.x && v.y;
}

} // namespace framework::math::relational_functions_details

#endif
