#include <common/utils.hpp>

#include <graphics/src/font/tables/font_header.hpp>

namespace framework::graphics::details::font
{

FontHeader::FontHeader(const BytesData& data)
{
    auto in = utils::make_big_endian_buffer_reader(data);

    in >> m_major_version;
    in >> m_minor_version;
    in >> m_font_revision;
    in >> m_check_sum_adjustment;
    in >> m_magic_number;
    in >> m_flags;
    in >> m_units_per_em;
    in >> m_created;
    in >> m_modified;
    in >> m_x_min;
    in >> m_y_min;
    in >> m_x_max;
    in >> m_y_max;
    in >> m_mac_style;
    in >> m_lowest_rec_ppem;
    in >> m_font_direction_hint;
    in >> m_index_to_loc_format;
    in >> m_glyph_data_format;
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

std::int16_t FontHeader::units_per_em() const
{
    return m_units_per_em;
}

bool FontHeader::baseline_at_y_zero() const
{
    return (m_flags & 0x0001u) != 0;
}

bool FontHeader::left_sidebearing_at_x_zero() const
{
    return (m_flags & 0x0002u) != 0;
}

} // namespace framework::graphics::details::font
