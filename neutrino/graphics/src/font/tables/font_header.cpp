#include <common/utils.hpp>

#include <graphics/src/font/tables/font_header.hpp>

namespace framework::graphics::details::font
{

FontHeader::FontHeader(const std::vector<std::uint8_t>& data)
{
    m_major_version        = utils::big_endian_value<std::uint16_t>(data.begin() + 0, data.end());
    m_minor_version        = utils::big_endian_value<std::uint16_t>(data.begin() + 2, data.end());
    m_font_revision        = utils::big_endian_value<Fixed>(data.begin() + 4, data.end());
    m_check_sum_adjustment = utils::big_endian_value<std::uint32_t>(data.begin() + 8, data.end());
    m_magic_number         = utils::big_endian_value<std::uint32_t>(data.begin() + 12, data.end());
    m_flags                = utils::big_endian_value<std::uint16_t>(data.begin() + 16, data.end());
    m_units_per_em         = utils::big_endian_value<std::uint16_t>(data.begin() + 18, data.end());
    m_created              = utils::big_endian_value<DateTime>(data.begin() + 20, data.end());
    m_modified             = utils::big_endian_value<DateTime>(data.begin() + 28, data.end());
    m_x_min                = utils::big_endian_value<std::int16_t>(data.begin() + 36, data.end());
    m_y_min                = utils::big_endian_value<std::int16_t>(data.begin() + 38, data.end());
    m_x_max                = utils::big_endian_value<std::int16_t>(data.begin() + 40, data.end());
    m_y_max                = utils::big_endian_value<std::int16_t>(data.begin() + 42, data.end());
    m_mac_style            = utils::big_endian_value<std::uint16_t>(data.begin() + 44, data.end());
    m_lowest_rec_ppem      = utils::big_endian_value<std::uint16_t>(data.begin() + 46, data.end());
    m_font_direction_hint  = utils::big_endian_value<std::int16_t>(data.begin() + 48, data.end());
    m_index_to_loc_format  = utils::big_endian_value<std::int16_t>(data.begin() + 50, data.end());
    m_glyph_data_format    = utils::big_endian_value<std::int16_t>(data.begin() + 52, data.end());
}

bool FontHeader::valid() const
{
    bool valid = true;

    valid &= m_major_version == 1;
    valid &= m_minor_version == 0;
    valid &= m_magic_number == 0X5F0F3CF5;
    valid &= (m_units_per_em >= 16 && m_units_per_em <= 16364);
    valid &= m_x_min < m_x_max;
    valid &= m_y_min < m_y_max;
    valid &= m_index_to_loc_format == 0 || m_index_to_loc_format == 1;
    valid &= m_glyph_data_format == 0;

    return valid;
}

std::int16_t FontHeader::index_to_loc_format() const
{
    return m_index_to_loc_format;
}

} // namespace framework::graphics::details::font
