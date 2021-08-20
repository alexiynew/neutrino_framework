////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Horizontal metrics table
/// @author Fedorov Alexey
/// @date 21.09.2020
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

#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_METRICS_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_METRICS_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct HorizontalMetrics
{
    struct Metric
    {
        std::uint16_t advance_width = 0;
        std::int16_t lsb            = 0;
    };

    static HorizontalMetrics parse(std::uint16_t number_of_h_metrics,
                                   std::uint16_t num_glyphs,
                                   const std::vector<std::uint8_t>& data);

    bool valid() const;

    std::vector<Metric> metrics;
    std::vector<std::int16_t> left_side_bearings;
};

} // namespace framework::graphics::details::font

#endif
