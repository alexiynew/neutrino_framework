////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Font.
/// @author Fedorov Alexey
/// @date 04.09.2020
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

#include <algorithm>
#include <array>
#include <cstdint>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <graphics/font.hpp>

#include <graphics/src/font/tables.hpp>
#include <common/utils.hpp>

using namespace framework;
using namespace framework::graphics::details::font;

namespace
{} // namespace

namespace framework::graphics
{

Font::Font()
{}

Font::Font(const Font&) = default;
Font& Font::operator=(const Font&) = default;

Font::Font(Font&&)  = default;
Font& Font::operator=(Font&&) = default;

bool Font::load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return false;
    }

    OffsetTable offset_table = utils::big_endian_value<OffsetTable>(file);
    if (!file || !offset_table.valid()) {

        return false;
    }

    std::vector<TableRecord> records = read_table_records(file, offset_table.num_tables);
    if (!file || records.size() != offset_table.num_tables || !has_required_tables(records)) {
        return false;
    }

    std::unordered_map<Tag, Table> tables;

    std::transform(records.begin(), records.end(), std::inserter(tables, tables.end()), [](const TableRecord& record) {
        return std::pair{record.tag, Table{record, {}}};
    });

    for (auto& table : tables) {
        if (!table.second.read_data(file)) {
            return false;
        }

        if (!table.second.valid()) {
            return false;
        }
    }

    FontHeaderTable head                   = FontHeaderTable::read(tables.at(Tag::head).data);
    CharacterToGlyphIndexMappingTable cmap = CharacterToGlyphIndexMappingTable::read(tables.at(Tag::cmap).data);
    HorizontalHeaderTable hhea             = HorizontalHeaderTable::read(tables.at(Tag::hhea).data);
    MaximumProfileTable maxp    = MaximumProfileTable::read(offset_table.sfnt_version, tables.at(Tag::maxp).data);
    HorizontalMetricsTable hmtx = HorizontalMetricsTable::read(hhea.number_of_h_metrics,
                                                               maxp.num_glyphs,
                                                               tables.at(Tag::hmtx).data);

    return false;
}

} // namespace framework::graphics
