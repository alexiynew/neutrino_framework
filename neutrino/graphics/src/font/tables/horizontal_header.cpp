#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_header.hpp>

namespace framework::graphics::details::font
{

HorizontalHeader::HorizontalHeader(const std::vector<std::uint8_t>& data)
{
    m_major_version          = utils::big_endian_value<std::uint16_t>(data.begin() + 0);
    m_minor_version          = utils::big_endian_value<std::uint16_t>(data.begin() + 2);
    m_ascender               = utils::big_endian_value<FWord>(data.begin() + 4);
    m_descender              = utils::big_endian_value<FWord>(data.begin() + 6);
    m_line_gap               = utils::big_endian_value<FWord>(data.begin() + 8);
    m_advance_width_max      = utils::big_endian_value<UFWord>(data.begin() + 10);
    m_min_left_side_bearing  = utils::big_endian_value<FWord>(data.begin() + 12);
    m_min_right_side_bearing = utils::big_endian_value<FWord>(data.begin() + 14);
    m_x_max_extent           = utils::big_endian_value<FWord>(data.begin() + 16);
    m_caret_slope_rise       = utils::big_endian_value<std::int16_t>(data.begin() + 18);
    m_caret_slope_run        = utils::big_endian_value<std::int16_t>(data.begin() + 20);
    m_caret_offset           = utils::big_endian_value<std::int16_t>(data.begin() + 22);
    // skip reserved fields
    m_metric_data_format  = utils::big_endian_value<std::int16_t>(data.begin() + 32);
    m_number_of_h_metrics = utils::big_endian_value<std::uint16_t>(data.begin() + 34);
}

bool HorizontalHeader::valid() const
{
    bool valid = true;

    valid &= m_major_version == 1;
    valid &= m_minor_version == 0;
    valid &= m_metric_data_format == 0;

    return valid;
}

std::uint16_t HorizontalHeader::number_of_h_metrics() const
{
    return m_number_of_h_metrics;
}

} // namespace framework::graphics::details::font
