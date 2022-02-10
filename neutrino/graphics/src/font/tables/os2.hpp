#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_OS2_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_OS2_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class Os2
{
public:
    explicit Os2(const std::vector<std::uint8_t>& data);

    bool valid() const;

private:
    std::uint16_t m_version             = 0;
    std::int16_t m_avg_char_width       = 0;
    std::uint16_t m_weight_class        = 0;
    std::uint16_t m_width_class         = 0;
    std::uint16_t m_type                = 0;
    std::int16_t m_subscript_x_size     = 0;
    std::int16_t m_subscript_y_size     = 0;
    std::int16_t m_subscript_x_offset   = 0;
    std::int16_t m_subscript_y_offset   = 0;
    std::int16_t m_superscript_x_size   = 0;
    std::int16_t m_superscript_y_size   = 0;
    std::int16_t m_superscript_x_offset = 0;
    std::int16_t m_superscript_y_offset = 0;
    std::int16_t m_strikeout_size       = 0;
    std::int16_t m_strikeout_position   = 0;
    std::int16_t m_family_class         = 0;
    std::array<std::uint8_t, 10> m_panose;
    std::uint32_t m_unicode_range1   = 0; // Bits 0-31
    std::uint32_t m_unicode_range2   = 0; // Bits 32-63
    std::uint32_t m_unicode_range3   = 0; // Bits 64-95
    std::uint32_t m_unicode_range4   = 0; // Bits 96-127
    Tag m_ach_vend_id                = Tag::Invalid;
    std::uint16_t m_selection        = 0;
    std::uint16_t m_first_char_index = 0;
    std::uint16_t m_last_char_index  = 0;
    std::int16_t m_typo_ascender     = 0;
    std::int16_t m_typo_descender    = 0;
    std::int16_t m_typo_linegap      = 0;
    std::uint16_t m_win_ascent       = 0;
    std::uint16_t m_win_descent      = 0;

    // for version 1
    std::uint32_t m_code_page_range1 = 0;
    std::uint32_t m_code_page_range2 = 0;

    // for version 2, 3, 4
    std::int16_t m_height        = 0;
    std::int16_t m_capheight     = 0;
    std::uint16_t m_default_char = 0;
    std::uint16_t m_break_char   = 0;
    std::uint16_t m_max_context  = 0;

    // for version 5 only
    std::uint16_t m_lower_optical_point_size = 0;
    std::uint16_t m_upper_optical_point_size = 0;
};

} // namespace framework::graphics::details::font

#endif
