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

#include <atomic>
#include <utility>

#include <common/instance_id.hpp>

namespace
{
std::uint32_t get_id()
{
    static std::atomic<std::uint32_t> uid{0};
    return ++uid;
}
} // namespace

namespace framework
{
InstanceId::InstanceId() : m_id(get_id())
{}

bool operator==(const InstanceId& lhs, const InstanceId& rhs)
{
    return lhs.m_id == rhs.m_id;
}

bool operator!=(const InstanceId& lhs, const InstanceId& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const InstanceId& lhs, const InstanceId& rhs)
{
    return lhs.m_id < rhs.m_id;
}

bool operator>(const InstanceId& lhs, const InstanceId& rhs)
{
    return rhs < lhs;
}

void swap(InstanceId& lhs, InstanceId& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_id, rhs.m_id);
}

} // namespace framework
