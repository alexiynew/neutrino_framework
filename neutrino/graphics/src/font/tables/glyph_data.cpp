#include <common/utils.hpp>

#include <graphics/src/font/tables/glyph_data.hpp>

namespace
{
namespace utils = framework::utils;

using framework::graphics::details::font::F2Dot14;
using framework::graphics::details::font::GlyphData;
using framework::graphics::details::font::Offset32;
using framework::graphics::details::font::ParsingError;
using framework::graphics::details::font::UnimplementedError;

using DataIterator = std::vector<std::uint8_t>::const_iterator;
using BufferReader = utils::BigEndianBufferReader<DataIterator>;

namespace SimpleGlyphFlags
{
enum Flags : std::uint8_t
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
}

namespace CompositeGlyphFlags
{
enum Flags : std::uint16_t
{
    arg_1_and_2_are_words     = 0x0001,
    args_are_xy_values        = 0x0002,
    round_xy_to_grid          = 0x0004,
    we_have_a_scale           = 0x0008,
    more_components           = 0x0020,
    we_have_an_x_and_y_scale  = 0x0040,
    we_have_a_two_by_two      = 0x0080,
    we_have_instructions      = 0x0100,
    use_my_metrics            = 0x0200,
    overlap_compound          = 0x0400,
    scaled_component_offset   = 0x0800,
    unscaled_component_offset = 0x1000,
    reserved                  = 0xE010, // Bits 4, 13, 14 and 15 are reserved: set to 0.
};
}

class XCoordinatesInterpretator
{
public:
    explicit XCoordinatesInterpretator(const std::vector<std::uint8_t>& flags)
        : m_flags(flags)
    {}

    inline bool is_short(size_t index) const
    {
        return m_flags[index] & SimpleGlyphFlags::x_short_vector;
    }

    inline bool is_positive(size_t index) const
    {
        return m_flags[index] & SimpleGlyphFlags::x_is_same_or_positive_x_short_vector;
    }

    inline bool is_same(size_t index) const
    {
        return m_flags[index] & SimpleGlyphFlags::x_is_same_or_positive_x_short_vector;
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
        return m_flags[index] & SimpleGlyphFlags::y_short_vector;
    }

    inline bool is_positive(size_t index) const
    {
        return m_flags[index] & SimpleGlyphFlags::y_is_same_or_positive_y_short_vector;
    }

    inline bool is_same(size_t index) const
    {
        return m_flags[index] & SimpleGlyphFlags::y_is_same_or_positive_y_short_vector;
    }

private:
    const std::vector<std::uint8_t>& m_flags;
};

GlyphData::GlyphHeader parse_header(BufferReader& in)
{
    GlyphData::GlyphHeader header;

    in >> header.number_of_contours;
    in >> header.x_min;
    in >> header.y_min;
    in >> header.x_max;
    in >> header.y_max;

    return header;
}

std::vector<std::uint8_t> parse_flags(const std::uint16_t points_count, BufferReader& in)
{
    std::vector<std::uint8_t> flags;
    flags.reserve(points_count);

    for (size_t i = 0; i < points_count; ++i) {
        const std::uint8_t flag = in.get<std::uint8_t>();
        flags.push_back(flag);

        if (flag & SimpleGlyphFlags::repeat_flag) {
            const std::uint8_t repeat_count = in.get<std::uint8_t>();
            flags.insert(flags.end(), repeat_count, flag);
            i += repeat_count;
        }
    }

    const bool valid = std::all_of(flags.begin(), flags.end(), [](std::uint8_t flag) {
        return (flag & SimpleGlyphFlags::reserved) == 0;
    });

    if (!valid) {
        throw ParsingError("Simple glyph flags reserved bit is not zero");
    }

    return flags;
}

template <typename CoordinatesInterpretator>
std::vector<std::int16_t> parse_coordinates(const size_t points_count,
                                            const CoordinatesInterpretator& flags_interpretator,
                                            BufferReader& in)
{
    std::vector<std::int16_t> coordinates;
    coordinates.reserve(points_count);

    for (size_t i = 0; i < points_count; ++i) {
        const bool is_short    = flags_interpretator.is_short(i);
        const bool is_positive = flags_interpretator.is_positive(i);
        const bool is_same     = flags_interpretator.is_same(i);

        std::uint16_t offset = 0;
        if (is_short) {
            // offset is 1 byte long
            offset = in.get<std::uint8_t>();
            offset *= (1 - (2 * static_cast<int>(!is_positive)));
        } else if (!is_same) {
            // If the coordinate is the same there is no offset. so offset == 0.
            // Otherwise offset is two bytes long

            offset = in.get<std::int16_t>();
        }

        coordinates.push_back(offset);
    }

    return coordinates;
}

GlyphData::SimpleGlyph parse_simple_glyph(const GlyphData::GlyphHeader& header, BufferReader& in)
{
    GlyphData::SimpleGlyph data;

    data.end_pts_of_contours.reserve(header.number_of_contours);
    for (int i = 0; i < header.number_of_contours; ++i) {
        data.end_pts_of_contours.push_back(in.get<std::uint16_t>());
    }

    data.instruction_length = in.get<std::uint16_t>();

    if (data.instruction_length > 0) {
        for (size_t i = 0; i < data.instruction_length; ++i) {
            data.instructions.push_back(in.get<std::uint8_t>());
        }
    }

    // end_pts_of_contours stores the index of the end points.
    // Therefore the number of coordinates is the last index + 1
    const std::uint16_t points_count = data.end_pts_of_contours.back() + 1;

    data.flags         = parse_flags(points_count, in);
    data.x_coordinates = parse_coordinates(points_count, XCoordinatesInterpretator(data.flags), in);
    data.y_coordinates = parse_coordinates(points_count, YCoordinatesInterpretator(data.flags), in);

    return data;
}

std::vector<GlyphData::CompositeGlyphComponent> parse_composite_glyph_components(BufferReader& in)
{
    std::vector<GlyphData::CompositeGlyphComponent> components;

    do {
        GlyphData::CompositeGlyphComponent component;

        in >> component.flags;
        in >> component.glyph_index;

        if (component.flags & CompositeGlyphFlags::arg_1_and_2_are_words) {
            // arguments are 16-bit
            if (component.flags & CompositeGlyphFlags::args_are_xy_values) {
                component.argument1 = in.get<std::int16_t>();
                component.argument2 = in.get<std::int16_t>();
            } else {
                component.argument1 = in.get<std::uint16_t>();
                component.argument2 = in.get<std::uint16_t>();
            }
        } else {
            // arguments they are bytes
            if (component.flags & CompositeGlyphFlags::args_are_xy_values) {
                component.argument1 = in.get<std::int8_t>();
                component.argument2 = in.get<std::int8_t>();
            } else {
                component.argument1 = in.get<std::uint8_t>();
                component.argument2 = in.get<std::uint8_t>();
            }
        }

        if (component.flags & CompositeGlyphFlags::we_have_a_scale) {
            F2Dot14 scale = in.get<F2Dot14>();
        } else if (component.flags & CompositeGlyphFlags::we_have_an_x_and_y_scale) {
            F2Dot14 xscale = in.get<F2Dot14>();
            F2Dot14 yscale = in.get<F2Dot14>();
        } else if (component.flags & CompositeGlyphFlags::we_have_a_two_by_two) {
            F2Dot14 xscale  = in.get<F2Dot14>();
            F2Dot14 scale01 = in.get<F2Dot14>();
            F2Dot14 scale10 = in.get<F2Dot14>();
            F2Dot14 yscale  = in.get<F2Dot14>();
        }

        components.push_back(component);
    } while (components.back().flags & CompositeGlyphFlags::more_components);

    return components;
}

GlyphData::CompositeGlyph parse_composite_glyph(BufferReader& in)
{
    GlyphData::CompositeGlyph data;

    data.components = parse_composite_glyph_components(in);

    if (data.components.back().flags & CompositeGlyphFlags::we_have_instructions) {
        in >> data.instruction_length;

        if (data.instruction_length > 0) {
            for (size_t i = 0; i < data.instruction_length; ++i) {
                data.instructions.push_back(in.get<std::uint8_t>());
            }
        } else {
            throw ParsingError(
            "The CompositeGlyphFlags::we_have_instructions flag is set but instructions length is zero.");
        }
    }

    const bool valid = std::all_of(data.components.begin(),
                                   data.components.end(),
                                   [](const GlyphData::CompositeGlyphComponent& component) {
                                       return (component.flags & CompositeGlyphFlags::reserved) == 0;
                                   });

    if (!valid) {
        throw ParsingError("Composite glyph component flags reserved bits is not zero");
    }

    return data;
}

GlyphData::Glyph parse_glyph(BufferReader& in)
{
    GlyphData::Glyph glyph;

    if (!in.good()) {
        // Glyph has no outline
        return glyph;
    }

    glyph.header = parse_header(in);

    if (glyph.header.number_of_contours >= 0) {
        glyph.simple_glyph = parse_simple_glyph(glyph.header, in);
    } else {
        glyph.composite_glyph = parse_composite_glyph(in);
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
        DataIterator end   = std::next(data.begin(), offsets[i + 1]);

        BufferReader in = utils::make_big_endian_buffer_reader(begin, end);

        m_glyphs.emplace(i, parse_glyph(in));
    }
}

bool GlyphData::valid() const
{
    return false;
}

} // namespace framework::graphics::details::font
