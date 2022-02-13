#include <common/utils.hpp>

#include <graphics/src/font/tables/os2.hpp>

namespace framework::graphics::details::font
{

Os2::Os2(const std::vector<std::uint8_t>& data)
{
    auto in = utils::make_big_endian_buffer_reader(data);

    in >> m_version;
    in >> m_avg_char_width;
    in >> m_weight_class;
    in >> m_width_class;
    in >> m_type;
    in >> m_subscript_x_size;
    in >> m_subscript_y_size;
    in >> m_subscript_x_offset;
    in >> m_subscript_y_offset;
    in >> m_superscript_x_size;
    in >> m_superscript_y_size;
    in >> m_superscript_x_offset;
    in >> m_superscript_y_offset;
    in >> m_strikeout_size;
    in >> m_strikeout_position;
    in >> m_family_class;

    std::reverse_copy(data.begin() + 32, data.begin() + 42, m_panose.begin());
    in.skip<std::uint8_t>(10);

    in >> m_unicode_range1;
    in >> m_unicode_range2;
    in >> m_unicode_range3;
    in >> m_unicode_range4;
    in >> m_ach_vend_id;
    in >> m_selection;
    in >> m_first_char_index;
    in >> m_last_char_index;
    in >> m_typo_ascender;
    in >> m_typo_descender;
    in >> m_typo_linegap;
    in >> m_win_ascent;
    in >> m_win_descent;

    if (m_version >= 1) {
        in >> m_code_page_range1;
        in >> m_code_page_range2;
    }

    if (m_version >= 2) {
        in >> m_height;
        in >> m_capheight;
        in >> m_default_char;
        in >> m_break_char;
        in >> m_max_context;
    }

    if (m_version == 5) {
        in >> m_lower_optical_point_size;
        in >> m_upper_optical_point_size;
    }
}

bool Os2::valid() const
{
    bool valid = true;

    valid &= m_version <= 5; // all versions supported
    valid &= m_weight_class >= 1 && m_weight_class <= 1000;
    valid &= m_width_class >= 1 && m_width_class <= 9;

    return valid;
}

} // namespace framework::graphics::details::font
