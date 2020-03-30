/// @file
/// @brief Version number abstraction
/// @author Fedorov Alexey
/// @date 13.09.2018

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

#include <sstream>

#include <common/version.hpp>

namespace
{
framework::int32 get_number(std::istringstream& ins)
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
Version::Version(int32 major_v, int32 minor_v, int32 patch_v, int32 build_n) noexcept
    : major_version(major_v), minor_version(minor_v), patch_version(patch_v), build_number(build_n)
{}

Version::Version(const std::string& version_string)
{
    std::istringstream input(version_string);

    major_version = get_number(input);
    minor_version = get_number(input);
    patch_version = get_number(input);
    build_number  = get_number(input);
}

std::string Version::as_string() const
{
    return std::to_string(major_version) + '.' + std::to_string(minor_version) + '.' + std::to_string(patch_version) +
           '.' + std::to_string(build_number);
}

} // namespace framework::utils
