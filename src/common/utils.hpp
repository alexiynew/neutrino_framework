/// @file
/// @brief Different helper functions
/// @author Fedorov Alexey
/// @date 03.03.2018

#ifndef FRAMEWORK_COMMON_UTILS_HPP
#define FRAMEWORK_COMMON_UTILS_HPP

namespace framework
{
/// @details
///
/// Different helper functions.
///
/// @defgroup common_utils_module Common utils
/// @{

namespace utils
{
/// @addtogroup common_utils_module
/// @{

/// @brief Determines if it is the debug build.
///
/// @return `true` in debug mode, `false` otherwise.
inline constexpr bool is_debug() noexcept
{
#ifndef NDEBUG
    return true;
#else
    return false;
#endif
}

/// @}

} // namespace utils

/// @}

} // namespace framework

#endif
