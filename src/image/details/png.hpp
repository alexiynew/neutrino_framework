/// @file
/// @brief Png image implementation.
/// @author Fedorov Alexey
/// @date 04.04.2019

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

#ifndef FRAMEWORK_IMAGE_DETAILS_PNG_HPP
#define FRAMEWORK_IMAGE_DETAILS_PNG_HPP

#include <string>
#include <vector>
#include <optional>
#include <tuple>

#include <common/types.hpp>
#include <image/details/image_info.hpp>

namespace framework::image::details::png
{
using data_t        = std::vector<framework::uint8>;
using image_data_t  = std::tuple<image_info, data_t>;
using load_result_t = std::optional<image_data_t>;

load_result_t load(const std::string& filename);
bool save(const std::string& filename);

bool is_png(const std::string& filename);

} // namespace framework::image::details::png

#endif
