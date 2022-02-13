#include <common/utils.hpp>

#include <graphics/src/font/tables/font_header.hpp>

namespace framework::graphics::details::font
{

FontHeader FontHeader::parse(const std::vector<std::uint8_t>& data)
{
    FontHeader table;
    table.major_version        = utils::big_endian_value<std::uint16_t>(data.begin() + 0);
    table.minor_version        = utils::big_endian_value<std::uint16_t>(data.begin() + 2);
    table.font_revision        = utils::big_endian_value<Fixed>(data.begin() + 4);
    table.check_sum_adjustment = utils::big_endian_value<std::uint32_t>(data.begin() + 8);
    table.magic_number         = utils::big_endian_value<std::uint32_t>(data.begin() + 12);
    table.flags                = utils::big_endian_value<std::uint16_t>(data.begin() + 16);
    table.units_per_em         = utils::big_endian_value<std::uint16_t>(data.begin() + 18);
    table.created              = utils::big_endian_value<DateTime>(data.begin() + 20);
    table.modified             = utils::big_endian_value<DateTime>(data.begin() + 28);
    table.x_min                = utils::big_endian_value<std::int16_t>(data.begin() + 36);
    table.y_min                = utils::big_endian_value<std::int16_t>(data.begin() + 38);
    table.x_max                = utils::big_endian_value<std::int16_t>(data.begin() + 40);
    table.y_max                = utils::big_endian_value<std::int16_t>(data.begin() + 42);
    table.mac_style            = utils::big_endian_value<std::uint16_t>(data.begin() + 44);
    table.lowest_rec_ppem      = utils::big_endian_value<std::uint16_t>(data.begin() + 46);
    table.font_direction_hint  = utils::big_endian_value<std::int16_t>(data.begin() + 48);
    table.index_to_loc_format  = utils::big_endian_value<std::int16_t>(data.begin() + 50);
    table.glyph_data_format    = utils::big_endian_value<std::int16_t>(data.begin() + 52);

    return table;
}

bool FontHeader::valid() const
{
    bool valid = true;

    valid &= major_version == 1;
    valid &= minor_version == 0;
    valid &= magic_number == 0X5F0F3CF5;
    valid &= (units_per_em >= 16 && units_per_em <= 16364);
    valid &= x_min < x_max;
    valid &= y_min < y_max;
    valid &= index_to_loc_format == 0 || index_to_loc_format == 1;
    valid &= glyph_data_format == 0;

    return valid;
}

} // namespace framework::graphics::details::font
