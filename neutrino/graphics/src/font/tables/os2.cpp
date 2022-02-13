#include <common/utils.hpp>

#include <graphics/src/font/tables/os2.hpp>

namespace framework::graphics::details::font
{

Os2 Os2::parse(const std::vector<std::uint8_t>& data)
{
    Os2 table;

    table.version              = utils::big_endian_value<std::uint16_t>(data.begin() + 0);
    table.avg_char_width       = utils::big_endian_value<std::int16_t>(data.begin() + 2);
    table.weight_class         = utils::big_endian_value<std::uint16_t>(data.begin() + 4);
    table.width_class          = utils::big_endian_value<std::uint16_t>(data.begin() + 6);
    table.type                 = utils::big_endian_value<std::uint16_t>(data.begin() + 8);
    table.subscript_x_size     = utils::big_endian_value<std::int16_t>(data.begin() + 10);
    table.subscript_y_size     = utils::big_endian_value<std::int16_t>(data.begin() + 12);
    table.subscript_x_offset   = utils::big_endian_value<std::int16_t>(data.begin() + 14);
    table.subscript_y_offset   = utils::big_endian_value<std::int16_t>(data.begin() + 16);
    table.superscript_x_size   = utils::big_endian_value<std::int16_t>(data.begin() + 18);
    table.superscript_y_size   = utils::big_endian_value<std::int16_t>(data.begin() + 20);
    table.superscript_x_offset = utils::big_endian_value<std::int16_t>(data.begin() + 22);
    table.superscript_y_offset = utils::big_endian_value<std::int16_t>(data.begin() + 24);
    table.strikeout_size       = utils::big_endian_value<std::int16_t>(data.begin() + 26);
    table.strikeout_position   = utils::big_endian_value<std::int16_t>(data.begin() + 28);
    table.family_class         = utils::big_endian_value<std::int16_t>(data.begin() + 30);

    std::reverse_copy(data.begin() + 32, data.begin() + 42, table.panose.begin());

    table.unicode_range1   = utils::big_endian_value<std::uint32_t>(data.begin() + 42);
    table.unicode_range2   = utils::big_endian_value<std::uint32_t>(data.begin() + 46);
    table.unicode_range3   = utils::big_endian_value<std::uint32_t>(data.begin() + 50);
    table.unicode_range4   = utils::big_endian_value<std::uint32_t>(data.begin() + 54);
    table.ach_vend_id      = utils::big_endian_value<Tag>(data.begin() + 58);
    table.selection        = utils::big_endian_value<std::uint16_t>(data.begin() + 62);
    table.first_char_index = utils::big_endian_value<std::uint16_t>(data.begin() + 64);
    table.last_char_index  = utils::big_endian_value<std::uint16_t>(data.begin() + 66);
    table.typo_ascender    = utils::big_endian_value<std::int16_t>(data.begin() + 68);
    table.typo_descender   = utils::big_endian_value<std::int16_t>(data.begin() + 70);
    table.typo_linegap     = utils::big_endian_value<std::int16_t>(data.begin() + 72);
    table.win_ascent       = utils::big_endian_value<std::uint16_t>(data.begin() + 74);
    table.win_descent      = utils::big_endian_value<std::uint16_t>(data.begin() + 76);

    if (table.version >= 1) {
        table.code_page_range1 = utils::big_endian_value<std::uint32_t>(data.begin() + 78);
        table.code_page_range2 = utils::big_endian_value<std::uint32_t>(data.begin() + 82);
    }

    if (table.version >= 2) {
        table.height       = utils::big_endian_value<std::int16_t>(data.begin() + 86);
        table.capheight    = utils::big_endian_value<std::int16_t>(data.begin() + 88);
        table.default_char = utils::big_endian_value<std::uint16_t>(data.begin() + 90);
        table.break_char   = utils::big_endian_value<std::uint16_t>(data.begin() + 92);
        table.max_context  = utils::big_endian_value<std::uint16_t>(data.begin() + 94);
    }

    if (table.version == 5) {
        table.lower_optical_point_size = utils::big_endian_value<std::uint16_t>(data.begin() + 96);
        table.upper_optical_point_size = utils::big_endian_value<std::uint16_t>(data.begin() + 98);
    }

    return table;
}

bool Os2::valid() const
{
    bool valid = true;

    valid &= version <= 5;
    valid &= weight_class >= 1 && weight_class <= 1000;
    valid &= width_class >= 1 && width_class <= 9;

    return valid;
}

} // namespace framework::graphics::details::font
