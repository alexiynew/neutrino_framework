#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_HEADER_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_HEADER_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class FontHeader final
{
public:
    explicit FontHeader(const BytesData& data);

    bool valid() const;

    std::int16_t index_to_loc_format() const;
    std::uint16_t units_per_em() const;
    bool baseline_at_y_zero() const;
    bool left_sidebearing_at_x_zero() const;

private:
    std::uint16_t m_major_version        = 0;
    std::uint16_t m_minor_version        = 0;
    Fixed m_font_revision                = 0;
    std::uint32_t m_check_sum_adjustment = 0;
    std::uint32_t m_magic_number         = 0;
    std::uint16_t m_flags                = 0;
    std::uint16_t m_units_per_em         = 0;
    DateTime m_created                   = 0;
    DateTime m_modified                  = 0;
    std::int16_t m_x_min                 = 0;
    std::int16_t m_y_min                 = 0;
    std::int16_t m_x_max                 = 0;
    std::int16_t m_y_max                 = 0;

    // TODO:  macStyle bits must agree with the OS/2 table fsSelection. Add this check.
    //        The fsSelection bits are used over the macStyle bits in Microsoft Windows.
    std::uint16_t m_mac_style          = 0;
    std::uint16_t m_lowest_rec_ppem    = 0;
    std::int16_t m_font_direction_hint = 0;
    std::int16_t m_index_to_loc_format = 0;
    std::int16_t m_glyph_data_format   = 0;
};

} // namespace framework::graphics::details::font

#endif
