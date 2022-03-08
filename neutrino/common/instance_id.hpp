#ifndef FRAMEWORK_COMMON_INSTANCE_ID_HPP
#define FRAMEWORK_COMMON_INSTANCE_ID_HPP

#include <cstdint>
#include <functional>
#include <ostream>

namespace framework
{
class InstanceId;
}

namespace std
{
template <>
struct hash<framework::InstanceId>;
} // namespace std

namespace framework
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup utils_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Id of any object.
///
/// Every default constructed instance id guaranteed to be unique.
class InstanceId final
{
public:
    /// @brief Creates InstanceId with unique index.
    InstanceId();

private:
    friend bool operator==(const InstanceId& lhs, const InstanceId& rhs);
    friend bool operator<(const InstanceId& lhs, const InstanceId& rhs);
    friend void swap(InstanceId& lhs, InstanceId& rhs) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const InstanceId& instance_id);

    friend struct std::hash<InstanceId>;

    std::uint32_t m_id;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @name InstanceId operators
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Equality operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
bool operator==(const InstanceId& lhs, const InstanceId& rhs);

/// @brief Inequality operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
bool operator!=(const InstanceId& lhs, const InstanceId& rhs);

/// @brief Less operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs is less then rhs, otherwise `false`.
bool operator<(const InstanceId& lhs, const InstanceId& rhs);

/// @brief Greater operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs is greater then rhs, otherwise `false`.
bool operator>(const InstanceId& lhs, const InstanceId& rhs);

/// @brief Swaps two InstanceId's.
///
/// @param lhs Id to swap.
/// @param rhs Id to swap.
void swap(InstanceId& lhs, InstanceId& rhs) noexcept;

/// @brief Insert InstanceId to output stream.
///
/// @param os Output stream.
/// @param instance_id InstanceId to output.
std::ostream& operator<<(std::ostream& os, const InstanceId& instance_id);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework

namespace std
{
template <>
struct hash<framework::InstanceId>
{
    std::size_t operator()(const framework::InstanceId& id) const noexcept
    {
        return std::hash<decltype(id.m_id)>{}(id.m_id);
    }
};
} // namespace std

#endif
