////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Horizontal metrics table
/// @author Fedorov Alexey
/// @date 21.09.2020
////////////////////////////////////////////////////////////////////////////////

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

#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_metrics.hpp>

namespace framework::graphics::details::font
{

HorizontalMetrics HorizontalMetrics::parse(std::uint16_t number_of_h_metrics,
                                           std::uint16_t num_glyphs,
                                           const std::vector<std::uint8_t>& data)
{
    auto from = data.begin();

    HorizontalMetrics table;
    table.metrics.reserve(number_of_h_metrics);
    for (size_t i = 0; i < number_of_h_metrics; ++i) {
        HorizontalMetrics::Metric metric;
        metric.advance_width = utils::big_endian_value<std::uint16_t>(from, data.end());
        metric.lsb           = utils::big_endian_value<std::int16_t>(from + 2, data.end());

        table.metrics.push_back(metric);
        std::advance(from, 4);
    }

    if (num_glyphs > number_of_h_metrics) {
        for (size_t i = 0; i < number_of_h_metrics; ++i) {
            table.left_side_bearings.push_back(utils::big_endian_value<std::int16_t>(from, data.end()));
            std::advance(from, 2);
        }
    }

    return table;
}

bool HorizontalMetrics::valid() const
{
    return true;
}

} // namespace framework::graphics::details::font
