#include <sstream>

#include <common/version.hpp>

namespace
{
int get_number(std::istringstream& ins)
{
    std::string number;
    if (!std::getline(ins, number, '.')) {
        return 0;
    }

    if (number.empty()) {
        return 0;
    }

    return std::stoi(number);
}

} // namespace

namespace neutrino
{
Version::Version(int major_v, int minor_v, int patch_v, int build_n) noexcept
    : m_major_version(major_v)
    , m_minor_version(minor_v)
    , m_patch_version(patch_v)
    , m_build_number(build_n)
{}

Version::Version(const std::string& version_string)
{
    std::istringstream input(version_string);

    m_major_version = get_number(input);
    m_minor_version = get_number(input);
    m_patch_version = get_number(input);
    m_build_number  = get_number(input);
}

std::string Version::as_string() const
{
    return std::to_string(m_major_version) + '.' + std::to_string(m_minor_version) + '.' +
           std::to_string(m_patch_version) + '.' + std::to_string(m_build_number);
}

int Version::major() const
{
    return m_major_version;
}

int Version::minor() const
{
    return m_minor_version;
}

int Version::patch() const
{
    return m_patch_version;
}

int Version::build_number() const
{
    return m_build_number;
}

} // namespace neutrino
