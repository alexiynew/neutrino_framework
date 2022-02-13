#include <common/utils.hpp>

#include <graphics/src/font/tables/glyph_data.hpp>

namespace
{
namespace utils = framework::utils;

using framework::graphics::details::font::GlyphData;
using framework::graphics::details::font::Offset32;
using framework::graphics::details::font::ParsingError;

using DataIterator = std::vector<std::uint8_t>::const_iterator;

enum Flags
{
    on_curve_point                       = 0x01,
    x_short_vector                       = 0x02,
    y_short_vector                       = 0x04,
    repeat_flag                          = 0x08,
    x_is_same_or_positive_x_short_vector = 0x10,
    y_is_same_or_positive_y_short_vector = 0x20,
    overlap_simple                       = 0x40,
    reserved                             = 0x80,
};

class XCoordinatesInterpretator
{
public:
    explicit XCoordinatesInterpretator(const std::vector<std::uint8_t>& flags)
        : m_flags(flags)
    {}

    inline bool is_short(size_t index) const
    {
        return m_flags[index] & Flags::x_short_vector;
    }

    inline bool is_positive(size_t index) const
    {
        return m_flags[index] & Flags::x_is_same_or_positive_x_short_vector;
    }

    inline bool is_same(size_t index) const
    {
        return m_flags[index] & Flags::x_is_same_or_positive_x_short_vector;
    }

private:
    const std::vector<std::uint8_t>& m_flags;
};

struct YCoordinatesInterpretator
{
public:
    explicit YCoordinatesInterpretator(const std::vector<std::uint8_t>& flags)
        : m_flags(flags)
    {}

    inline bool is_short(size_t index) const
    {
        return m_flags[index] & Flags::y_short_vector;
    }

    inline bool is_positive(size_t index) const
    {
        return m_flags[index] & Flags::y_is_same_or_positive_y_short_vector;
    }

    inline bool is_same(size_t index) const
    {
        return m_flags[index] & Flags::y_is_same_or_positive_y_short_vector;
    }

private:
    const std::vector<std::uint8_t>& m_flags;
};

GlyphData::GlyphHeader parse_header(const DataIterator& begin)
{
    GlyphData::GlyphHeader header;

    header.number_of_contours = utils::big_endian_value<std::int16_t>(begin);
    header.x_min              = utils::big_endian_value<std::int16_t>(begin + 2);
    header.y_min              = utils::big_endian_value<std::int16_t>(begin + 4);
    header.x_max              = utils::big_endian_value<std::int16_t>(begin + 6);
    header.y_max              = utils::big_endian_value<std::int16_t>(begin + 8);

    return header;
}

std::pair<std::vector<std::uint8_t>, DataIterator> parse_flags(const std::uint16_t points_count,
                                                               const DataIterator& begin)
{
    DataIterator from = begin;

    std::vector<std::uint8_t> flags;
    flags.reserve(points_count);

    for (size_t i = 0; i < points_count; ++i) {
        const std::uint8_t flag = utils::big_endian_value<std::uint8_t>(from);
        std::advance(from, 1);

        flags.push_back(flag);

        if (flag & Flags::repeat_flag) {
            const std::uint8_t repeat_count = utils::big_endian_value<std::uint8_t>(from);
            std::advance(from, 1);

            flags.insert(flags.end(), repeat_count, flag);
            i += repeat_count;
        }
    }

    const bool valid = std::all_of(flags.begin(), flags.end(), [](std::uint8_t flag) {
        return (flag & Flags::reserved) == 0;
    });

    if (!valid) {
        throw ParsingError("Glyph flags reserved bit is not zero");
    }

    return std::make_pair(std::move(flags), from);
}

template <typename CoordinatesInterpretator>
std::pair<std::vector<std::int16_t>, DataIterator> parse_coordinates(const size_t points_count,
                                                                     const CoordinatesInterpretator& flags_interpretator,
                                                                     const DataIterator& begin)
{
    DataIterator from = begin;

    std::vector<std::int16_t> coordinates;
    coordinates.reserve(points_count);

    for (size_t i = 0; i < points_count; ++i) {
        const bool is_short    = flags_interpretator.is_short(i);
        const bool is_positive = flags_interpretator.is_positive(i);
        const bool is_same     = flags_interpretator.is_same(i);

        std::uint16_t offset = 0;
        if (is_short) {
            // offset is 1 byte long
            offset = utils::big_endian_value<std::uint8_t>(from);
            offset *= (1 - (2 * static_cast<int>(!is_positive)));

            std::advance(from, 1);
        } else if (!is_same) {
            // If the coordinate is the same there is no offset. so offset == 0.
            // Otherwise offset is two bytes long

            offset = utils::big_endian_value<std::int16_t>(from);
            std::advance(from, 2);
        }

        coordinates.push_back(offset);
    }

    return std::make_pair(std::move(coordinates), from);
}

GlyphData::SimpleGlyph parse_simple_glyph(const GlyphData::GlyphHeader& header, const DataIterator& begin)
{
    DataIterator from = begin;

    GlyphData::SimpleGlyph data;

    data.end_pts_of_contours.reserve(header.number_of_contours);
    for (int i = 0; i < header.number_of_contours; ++i) {
        data.end_pts_of_contours.push_back(utils::big_endian_value<std::uint16_t>(from));
        std::advance(from, 2);
    }

    data.instruction_length = utils::big_endian_value<std::uint16_t>(from);
    std::advance(from, 2);

    if (data.instruction_length > 0) {
        for (size_t i = 0; i < data.instruction_length; ++i) {
            data.instructions.push_back(utils::big_endian_value<std::uint8_t>(from));
            std::advance(from, 1);
        }
    }

    // end_pts_of_contours stores the index of the end points.
    // Therefore the number of coordinates is the last index + 1
    const std::uint16_t count = data.end_pts_of_contours.back() + 1;

    std::tie(data.flags, from)         = parse_flags(count, from);
    std::tie(data.x_coordinates, from) = parse_coordinates(count, XCoordinatesInterpretator(data.flags), from);
    std::tie(data.y_coordinates, from) = parse_coordinates(count, YCoordinatesInterpretator(data.flags), from);

    return data;
}

GlyphData::Glyph parse_glyph(const DataIterator& begin)
{

    GlyphData::Glyph glyph;
    glyph.header = parse_header(begin);

    DataIterator from = std::next(begin, 10);

    if (glyph.header.number_of_contours >= 0) {
        glyph.data = parse_simple_glyph(glyph.header, from);
    } else {
        // composite glyph
    }

    return glyph;
}

} // namespace

namespace framework::graphics::details::font
{

GlyphData::GlyphData(std::uint16_t num_glyphs,
                     const std::vector<Offset32>& offsets,
                     const std::vector<std::uint8_t>& data)
{
    m_glyphs.reserve(num_glyphs);

    for (GlyphId i = 0; i < num_glyphs; ++i) {
        DataIterator begin = std::next(data.begin(), offsets[i]);
        // DataIterator end   = std::next(data.begin(), offsets[i + 1]);

        m_glyphs.emplace(i, parse_glyph(begin));
    }
}

bool GlyphData::valid() const
{
    return false;
}

} // namespace framework::graphics::details::font
