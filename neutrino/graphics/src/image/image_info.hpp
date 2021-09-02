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

#ifndef FRAMEWORK_GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP
#define FRAMEWORK_GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP

#include <optional>
#include <tuple>
#include <variant>
#include <vector>

#include <common/types.hpp>
#include <graphics/color.hpp>

namespace framework::graphics::details::image
{
constexpr float default_gamma = 2.2f;

namespace error
{
inline constexpr char invalid_file_type[]      = "Invalid file type.";
inline constexpr char invalid_file_signature[] = "Invalid file signature.";
inline constexpr char open_file_error[]        = "Can't open file.";
inline constexpr char file_offset_error[]      = "File offset error.";
inline constexpr char read_header_error[]      = "Can't read image header.";
inline constexpr char read_data_error[]        = "Can't read image data.";
inline constexpr char unknown_error[]          = "Unknown error.";
} // namespace error

struct ImageInfo
{
    int32 width  = 0;
    int32 height = 0;

    float gamma = default_gamma;

    std::vector<Color> data;
};

using ErrorDescription = std::string;
using LoadResult       = std::variant<ImageInfo, ErrorDescription>;

} // namespace framework::graphics::details::image

#endif
