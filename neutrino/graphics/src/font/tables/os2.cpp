#include <common/utils.hpp>

#include <graphics/src/font/tables/os2.hpp>

namespace framework::graphics::details::font
{

Os2::Os2(const std::vector<std::uint8_t>& data)
{
    m_version              = utils::big_endian_value<std::uint16_t>(data.begin() + 0);
    m_avg_char_width       = utils::big_endian_value<std::int16_t>(data.begin() + 2);
    m_weight_class         = utils::big_endian_value<std::uint16_t>(data.begin() + 4);
    m_width_class          = utils::big_endian_value<std::uint16_t>(data.begin() + 6);
    m_type                 = utils::big_endian_value<std::uint16_t>(data.begin() + 8);
    m_subscript_x_size     = utils::big_endian_value<std::int16_t>(data.begin() + 10);
    m_subscript_y_size     = utils::big_endian_value<std::int16_t>(data.begin() + 12);
    m_subscript_x_offset   = utils::big_endian_value<std::int16_t>(data.begin() + 14);
    m_subscript_y_offset   = utils::big_endian_value<std::int16_t>(data.begin() + 16);
    m_superscript_x_size   = utils::big_endian_value<std::int16_t>(data.begin() + 18);
    m_superscript_y_size   = utils::big_endian_value<std::int16_t>(data.begin() + 20);
    m_superscript_x_offset = utils::big_endian_value<std::int16_t>(data.begin() + 22);
    m_superscript_y_offset = utils::big_endian_value<std::int16_t>(data.begin() + 24);
    m_strikeout_size       = utils::big_endian_value<std::int16_t>(data.begin() + 26);
    m_strikeout_position   = utils::big_endian_value<std::int16_t>(data.begin() + 28);
    m_family_class         = utils::big_endian_value<std::int16_t>(data.begin() + 30);

    std::reverse_copy(data.begin() + 32, data.begin() + 42, m_panose.begin());

    m_unicode_range1   = utils::big_endian_value<std::uint32_t>(data.begin() + 42);
    m_unicode_range2   = utils::big_endian_value<std::uint32_t>(data.begin() + 46);
    m_unicode_range3   = utils::big_endian_value<std::uint32_t>(data.begin() + 50);
    m_unicode_range4   = utils::big_endian_value<std::uint32_t>(data.begin() + 54);
    m_ach_vend_id      = utils::big_endian_value<Tag>(data.begin() + 58);
    m_selection        = utils::big_endian_value<std::uint16_t>(data.begin() + 62);
    m_first_char_index = utils::big_endian_value<std::uint16_t>(data.begin() + 64);
    m_last_char_index  = utils::big_endian_value<std::uint16_t>(data.begin() + 66);
    m_typo_ascender    = utils::big_endian_value<std::int16_t>(data.begin() + 68);
    m_typo_descender   = utils::big_endian_value<std::int16_t>(data.begin() + 70);
    m_typo_linegap     = utils::big_endian_value<std::int16_t>(data.begin() + 72);
    m_win_ascent       = utils::big_endian_value<std::uint16_t>(data.begin() + 74);
    m_win_descent      = utils::big_endian_value<std::uint16_t>(data.begin() + 76);

    if (m_version >= 1) {
        m_code_page_range1 = utils::big_endian_value<std::uint32_t>(data.begin() + 78);
        m_code_page_range2 = utils::big_endian_value<std::uint32_t>(data.begin() + 82);
    }

    if (m_version >= 2) {
        m_height       = utils::big_endian_value<std::int16_t>(data.begin() + 86);
        m_capheight    = utils::big_endian_value<std::int16_t>(data.begin() + 88);
        m_default_char = utils::big_endian_value<std::uint16_t>(data.begin() + 90);
        m_break_char   = utils::big_endian_value<std::uint16_t>(data.begin() + 92);
        m_max_context  = utils::big_endian_value<std::uint16_t>(data.begin() + 94);
    }

    if (m_version == 5) {
        m_lower_optical_point_size = utils::big_endian_value<std::uint16_t>(data.begin() + 96);
        m_upper_optical_point_size = utils::big_endian_value<std::uint16_t>(data.begin() + 98);
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
