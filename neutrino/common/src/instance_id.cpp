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
InstanceId::InstanceId()
    : m_id(get_id())
{}

bool operator==(const InstanceId& lhs, const InstanceId& rhs)
{
    return lhs.m_id == rhs.m_id;
}

bool operator==(const InstanceId& lhs, const InstanceId::ValueType& rhs)
{
    return lhs.m_id == rhs;
}

bool operator!=(const InstanceId& lhs, const InstanceId& rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const InstanceId& lhs, const InstanceId::ValueType& rhs)
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

std::ostream& operator<<(std::ostream& os, const InstanceId& instance_id)
{
    os << instance_id.m_id;
    return os;
}

} // namespace framework
