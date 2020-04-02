////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Instance id.
/// @author Fedorov Alexey
/// @date 31.03.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_COMMON_UNIQUE_ID_HPP
#define FRAMEWORK_COMMON_UNIQUE_ID_HPP

#include <cstdint>
#include <functional>

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
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup common_types_module
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Id of any object.
///
/// Every default constructed instance id guaranteed to be unique.
////////////////////////////////////////////////////////////////////////////////
class InstanceId final
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates InstanceId with unique index.
    ////////////////////////////////////////////////////////////////////////////
    InstanceId();

private:
    friend bool operator==(const InstanceId& lhs, const InstanceId& rhs);
    friend bool operator<(const InstanceId& lhs, const InstanceId& rhs);
    friend void swap(InstanceId& lhs, InstanceId& rhs) noexcept;

    friend struct std::hash<InstanceId>;

    std::uint32_t m_id;
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Equality operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator==(const InstanceId& lhs, const InstanceId& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Inequality operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator!=(const InstanceId& lhs, const InstanceId& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Less operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs is less then rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator<(const InstanceId& lhs, const InstanceId& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Greater operator for InstanceId's.
///
/// @param lhs Id to compare.
/// @param rhs Id to compare.
///
/// @return `true` if lhs is greater then rhs, otherwise `false`.
////////////////////////////////////////////////////////////////////////////////
bool operator>(const InstanceId& lhs, const InstanceId& rhs);

////////////////////////////////////////////////////////////////////////////////
/// @brief Swaps two InstanceId's.
///
/// @param lhs Id to swap.
/// @param rhs Id to swap.
////////////////////////////////////////////////////////////////////////////////
void swap(InstanceId& lhs, InstanceId& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////
} // namespace framework

namespace std
{
template <>
struct hash<framework::InstanceId>
{
    std::size_t operator()(framework::InstanceId const& id) const noexcept
    {
        return std::hash<decltype(id.m_id)>{}(id.m_id);
    }
};
} // namespace std

#endif
