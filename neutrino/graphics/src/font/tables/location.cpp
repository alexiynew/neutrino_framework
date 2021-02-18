////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Index ot location table
/// @author Fedorov Alexey
/// @date 28.09.2020
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

#include <common/utils.hpp>

#include <graphics/src/font/tables/location.hpp>

namespace framework::graphics::details::font
{

Location Location::parse(std::int16_t format, std::uint16_t num_glyphs, const std::vector<std::uint8_t>& data)
{
    const size_t size = num_glyphs + 1;

    Location table;

    table.offsets.reserve(size);

    auto from = data.begin();
    for (size_t i = 0; i < num_glyphs; ++i) {
        switch (format) {
            case 0:
                table.offsets.push_back(utils::big_endian_value<Offset16>(from, data.end()));
                std::advance(from, sizeof(Offset16));
                break;

            case 1:
                table.offsets.push_back(utils::big_endian_value<Offset32>(from, data.end()));
                std::advance(from, sizeof(Offset32));
                break;
        }
    }

    return table;
}

} // namespace framework::graphics::details::font

