/// @file
/// @brief Image info.
/// @author Fedorov Alexey
/// @date 18.04.2019

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

#ifndef FRAMEWORK_GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP
#define FRAMEWORK_GRAPHICS_SRC_IMAGE_IMAGE_INFO_HPP

#include <optional>
#include <tuple>
#include <vector>

#include <common/types.hpp>
#include <graphics/color_type.hpp>

namespace framework::graphics::details::image
{
constexpr float32 default_gamma = 2.2f;

struct ImageInfo
{
    int32 width  = 0;
    int32 height = 0;

    float32 gamma = default_gamma;
};

using ImageData  = std::tuple<ImageInfo, std::vector<Color>>;
using LoadResult = std::optional<ImageData>;

} // namespace framework::graphics::details::image

#endif
