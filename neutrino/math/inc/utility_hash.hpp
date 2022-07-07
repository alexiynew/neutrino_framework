#ifndef FRAMEWORK_MATH_INC_UTILITY_HASH_HPP
#define FRAMEWORK_MATH_INC_UTILITY_HASH_HPP

#ifndef FRAMEWORK_MATH_DETAILS
    #error You should include math/math.hpp instead of utility_hash.hpp
#endif

#include <functional>

#include <math/inc/matrix_type.hpp>
#include <math/inc/utility_hash_details.hpp>
#include <math/inc/vector_type.hpp>

namespace std
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_hash_functions
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Support of std::hash for vectors.
template <std::size_t N, typename T>
struct hash<framework::math::Vector<N, T>>
{
    std::size_t operator()(const framework::math::Vector<N, T>& value) const noexcept;
};

/// @brief Support of std::hash for matrices.
template <std::size_t C, std::size_t R, typename T>
struct hash<framework::math::Matrix<C, R, T>>
{
    std::size_t operator()(const framework::math::Matrix<C, R, T>& value) const noexcept;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <std::size_t N, typename T>
std::size_t hash<framework::math::Vector<N, T>>::operator()(const framework::math::Vector<N, T>& value) const noexcept
{
    std::size_t seed = 0;
    hash<T> hasher;
    for (std::size_t i = 0; i < N; ++i) {
        seed = framework::math::unility_hash::details::hash_combine(seed, hasher(value[i]));
    }
    return seed;
}

template <std::size_t C, std::size_t R, typename T>
std::size_t hash<framework::math::Matrix<C, R, T>>::operator()(
const framework::math::Matrix<C, R, T>& value) const noexcept
{
    std::size_t seed = 0;
    hash<typename framework::math::Matrix<C, R, T>::ColumnType> hasher;
    for (std::size_t i = 0; i < C; ++i) {
        seed = framework::math::unility_hash::details::hash_combine(seed, hasher(value[i]));
    }
    return seed;
}

} // namespace std

#endif
