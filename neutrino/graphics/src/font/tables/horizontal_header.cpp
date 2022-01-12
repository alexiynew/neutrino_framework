#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_header.hpp>

namespace framework::graphics::details::font
{

HorizontalHeader HorizontalHeader::parse(const std::vector<std::uint8_t>& data)
{
    HorizontalHeader table;
    table.major_version          = utils::big_endian_value<std::uint16_t>(data.begin() + 0, data.end());
    table.minor_version          = utils::big_endian_value<std::uint16_t>(data.begin() + 2, data.end());
    table.ascender               = utils::big_endian_value<FWord>(data.begin() + 4, data.end());
    table.descender              = utils::big_endian_value<FWord>(data.begin() + 6, data.end());
    table.line_gap               = utils::big_endian_value<FWord>(data.begin() + 8, data.end());
    table.advance_width_max      = utils::big_endian_value<UFWord>(data.begin() + 10, data.end());
    table.min_left_side_bearing  = utils::big_endian_value<FWord>(data.begin() + 12, data.end());
    table.min_right_side_bearing = utils::big_endian_value<FWord>(data.begin() + 14, data.end());
    table.x_max_extent           = utils::big_endian_value<FWord>(data.begin() + 16, data.end());
    table.caret_slope_rise       = utils::big_endian_value<std::int16_t>(data.begin() + 18, data.end());
    table.caret_slope_run        = utils::big_endian_value<std::int16_t>(data.begin() + 20, data.end());
    table.caret_offset           = utils::big_endian_value<std::int16_t>(data.begin() + 22, data.end());
    table.reserved1              = utils::big_endian_value<std::int16_t>(data.begin() + 24, data.end());
    table.reserved2              = utils::big_endian_value<std::int16_t>(data.begin() + 26, data.end());
    table.reserved3              = utils::big_endian_value<std::int16_t>(data.begin() + 28, data.end());
    table.reserved4              = utils::big_endian_value<std::int16_t>(data.begin() + 30, data.end());
    table.metric_data_format     = utils::big_endian_value<std::int16_t>(data.begin() + 32, data.end());
    table.number_of_h_metrics    = utils::big_endian_value<std::uint16_t>(data.begin() + 34, data.end());

    return table;
}

bool HorizontalHeader::valid() const
{
    bool valid = true;

    valid &= major_version == 1;
    valid &= minor_version == 0;
    valid &= reserved1 == 0;
    valid &= reserved2 == 0;
    valid &= reserved3 == 0;
    valid &= reserved4 == 0;
    valid &= metric_data_format == 0;

    return valid;
}

} // namespace framework::graphics::details::font
