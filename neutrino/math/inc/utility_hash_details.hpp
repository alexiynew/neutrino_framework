#ifndef FRAMEWORK_MATH_INC_UTILITY_HASH_DETAILS_HPP
#define FRAMEWORK_MATH_INC_UTILITY_HASH_DETAILS_HPP

#include <cstddef>

namespace framework::math::unility_hash::details
{

constexpr inline std::size_t hash_combine(std::size_t seed, std::size_t hash) noexcept
{
    hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash;
    return seed;
}

} // namespace framework::math::unility_hash::details

#endif
