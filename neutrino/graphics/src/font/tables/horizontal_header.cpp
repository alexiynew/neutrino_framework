#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_header.hpp>

namespace framework::graphics::details::font
{

HorizontalHeader HorizontalHeader::parse(const std::vector<std::uint8_t>& data)
{
    HorizontalHeader table;
    table.major_version          = utils::big_endian_value<std::uint16_t>(data.begin() + 0);
    table.minor_version          = utils::big_endian_value<std::uint16_t>(data.begin() + 2);
    table.ascender               = utils::big_endian_value<FWord>(data.begin() + 4);
    table.descender              = utils::big_endian_value<FWord>(data.begin() + 6);
    table.line_gap               = utils::big_endian_value<FWord>(data.begin() + 8);
    table.advance_width_max      = utils::big_endian_value<UFWord>(data.begin() + 10);
    table.min_left_side_bearing  = utils::big_endian_value<FWord>(data.begin() + 12);
    table.min_right_side_bearing = utils::big_endian_value<FWord>(data.begin() + 14);
    table.x_max_extent           = utils::big_endian_value<FWord>(data.begin() + 16);
    table.caret_slope_rise       = utils::big_endian_value<std::int16_t>(data.begin() + 18);
    table.caret_slope_run        = utils::big_endian_value<std::int16_t>(data.begin() + 20);
    table.caret_offset           = utils::big_endian_value<std::int16_t>(data.begin() + 22);
    table.reserved1              = utils::big_endian_value<std::int16_t>(data.begin() + 24);
    table.reserved2              = utils::big_endian_value<std::int16_t>(data.begin() + 26);
    table.reserved3              = utils::big_endian_value<std::int16_t>(data.begin() + 28);
    table.reserved4              = utils::big_endian_value<std::int16_t>(data.begin() + 30);
    table.metric_data_format     = utils::big_endian_value<std::int16_t>(data.begin() + 32);
    table.number_of_h_metrics    = utils::big_endian_value<std::uint16_t>(data.begin() + 34);

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
