#include <common/utils.hpp>

#include <graphics/src/font/tables/glyph_data.hpp>

namespace
{
namespace utils   = framework::utils;
namespace details = framework::graphics::details::font;

using details::BufferReader;
using details::DataIterator;
using details::F2Dot14;
using details::GlyphData;
using details::NotImplementedError;
using details::Offset32;
using details::ParsingError;

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

        std::int16_t offset = 0;
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

GlyphData::SimpleGlyph parse_simple_glyph(size_t number_of_contours, BufferReader& in)
{
    GlyphData::SimpleGlyph data;

    data.end_pts_of_contours.reserve(number_of_contours);
    for (size_t i = 0; i < number_of_contours; ++i) {
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
            component.scale = in.get<F2Dot14>();
        } else if (component.flags & CompositeGlyphFlags::we_have_an_x_and_y_scale) {
            component.xscale = in.get<F2Dot14>();
            component.yscale = in.get<F2Dot14>();
        } else if (component.flags & CompositeGlyphFlags::we_have_a_two_by_two) {
            component.xscale  = in.get<F2Dot14>();
            component.scale01 = in.get<F2Dot14>();
            component.scale10 = in.get<F2Dot14>();
            component.yscale  = in.get<F2Dot14>();
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
        }
    }

    return data;
}

} // namespace

namespace framework::graphics::details::font
{

#pragma region class GlyphHeader

GlyphData::GlyphHeader::GlyphHeader(BufferReader& in)
{
    in >> m_number_of_contours;
    in >> m_x_min;
    in >> m_y_min;
    in >> m_x_max;
    in >> m_y_max;
}

bool GlyphData::GlyphHeader::is_simple_glyph() const
{
    return m_number_of_contours >= 0;
}

std::int16_t GlyphData::GlyphHeader::number_of_contours() const
{
    return m_number_of_contours;
}

std::int16_t GlyphData::GlyphHeader::x_min() const
{
    return m_x_min;
}

std::int16_t GlyphData::GlyphHeader::y_min() const
{
    return m_y_min;
}

std::int16_t GlyphData::GlyphHeader::x_max() const
{
    return m_x_max;
}

std::int16_t GlyphData::GlyphHeader::y_max() const
{
    return m_y_max;
}

#pragma endregion

GlyphData::Glyph::Glyph(BufferReader& in)
    : m_header(in)
{
    if (!in.good() || m_header.number_of_contours() == 0) {
        // Glyph has no outline
        return;
    }

    if (m_header.is_simple_glyph()) {
        m_simple_glyph = parse_simple_glyph(static_cast<size_t>(m_header.number_of_contours()), in);
    } else {
        m_composite_glyph = parse_composite_glyph(in);
    }
}

const GlyphData::GlyphHeader& GlyphData::Glyph::header() const
{
    return m_header;
}

const GlyphData::SimpleGlyph& GlyphData::Glyph::simple_glyph() const
{
    return m_simple_glyph;
}

const GlyphData::CompositeGlyph& GlyphData::Glyph::composite_glyph() const
{
    return m_composite_glyph;
}

GlyphData::GlyphData(std::uint16_t num_glyphs, const std::vector<Offset32>& offsets, const BytesData& data)
{
    m_glyphs.reserve(num_glyphs);

    for (GlyphId i = 0; i < num_glyphs; ++i) {
        DataIterator begin = std::next(data.begin(), offsets[i]);
        DataIterator end   = std::next(data.begin(), offsets[i + 1u]);

        BufferReader in = utils::make_big_endian_buffer_reader(begin, end);
        if (in) {
            m_glyphs.emplace(i, Glyph(in));
        }
    }
}

bool GlyphData::valid() const
{
    return !m_glyphs.empty();
}

const GlyphData::Glyph& GlyphData::at(GlyphId index) const
{
    return m_glyphs.at(index);
}

} // namespace framework::graphics::details::font
