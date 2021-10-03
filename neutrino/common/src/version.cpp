// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

namespace framework
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

} // namespace framework
