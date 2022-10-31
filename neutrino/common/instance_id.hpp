#ifndef COMMON_INSTANCE_ID_HPP
#define COMMON_INSTANCE_ID_HPP

#include <cstdint>
#include <functional>
#include <ostream>

namespace neutrino
{
class InstanceId;
}

namespace std
{
template <>
struct hash<neutrino::InstanceId>;
} // namespace std

namespace neutrino
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
    using ValueType = std::uint32_t;

    /// @brief Creates InstanceId with unique index.
    InstanceId();

private:
    friend bool operator==(const InstanceId& lhs, const InstanceId& rhs);
    friend bool operator==(const InstanceId& lhs, const ValueType& rhs);
    friend bool operator<(const InstanceId& lhs, const InstanceId& rhs);
    friend void swap(InstanceId& lhs, InstanceId& rhs) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const InstanceId& instance_id);

    friend struct std::hash<InstanceId>;

    ValueType m_id;
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

/// @brief Equality operator for InstanceId and internal type representation.
///
/// @param lhs Id to compare.
/// @param rhs Value to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
bool operator==(const InstanceId& lhs, const InstanceId::ValueType& rhs);

/// @brief Inequality operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
bool operator!=(const InstanceId& lhs, const InstanceId& rhs);

/// @brief Inequality operator for InstanceId and internal type representation.
///
/// @param lhs Id to compare.
/// @param rhs Value to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
bool operator!=(const InstanceId& lhs, const InstanceId::ValueType& rhs);

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

} // namespace neutrino

namespace std
{
template <>
struct hash<neutrino::InstanceId>
{
    std::size_t operator()(const neutrino::InstanceId& id) const noexcept
    {
        return std::hash<decltype(id.m_id)>{}(id.m_id);
    }
};
} // namespace std

#endif
