#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_header.hpp>

namespace framework::graphics::details::font
{

HorizontalHeader::HorizontalHeader(const BytesData& data)
{
    auto in = utils::make_big_endian_buffer_reader(data);

    in >> m_major_version;
    in >> m_minor_version;
    in >> m_ascender;
    in >> m_descender;
    in >> m_line_gap;
    in >> m_advance_width_max;
    in >> m_min_left_side_bearing;
    in >> m_min_right_side_bearing;
    in >> m_x_max_extent;
    in >> m_caret_slope_rise;
    in >> m_caret_slope_run;
    in >> m_caret_offset;

    // skip reserved fields
    in.skip<std::int16_t>(4);

    in >> m_metric_data_format;
    in >> m_number_of_h_metrics;
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
