#include <optional>

#include <common/utils.hpp>
#include <math/math.hpp>

#include <graphics/src/font/tables/glyph_data.hpp>

namespace
{
namespace utils   = framework::utils;
namespace details = framework::graphics::details::font;

using details::BufferReader;
using details::DataIterator;
using details::F2Dot14;
using details::GlyphData;
using details::GlyphId;
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

struct SimpleGlyph
{
    std::vector<std::uint16_t> end_pts_of_contours; // [number_of_contours]
    std::uint16_t instruction_length = 0;
    std::vector<std::uint8_t> instructions;  // [instruction_length]
    std::vector<std::uint8_t> flags;         // [end_pts_of_contours.back() + 1]
    std::vector<std::int16_t> x_coordinates; // [end_pts_of_contours.back() + 1]
    std::vector<std::int16_t> y_coordinates; // [end_pts_of_contours.back() + 1]
};

struct CompositeGlyphComponent
{
    std::uint16_t flags       = 0;
    std::uint16_t glyph_index = 0;
    std::int32_t argument1    = 0;
    std::int32_t argument2    = 0;

    F2Dot14 scale   = 0;
    F2Dot14 xscale  = 0;
    F2Dot14 scale01 = 0;
    F2Dot14 scale10 = 0;
    F2Dot14 yscale  = 0;
};

struct CompositeGlyph
{
    std::vector<CompositeGlyphComponent> components;

    std::uint16_t instruction_length = 0;
    std::vector<std::uint8_t> instructions; // [instruction_length]
};

using SimpleGlyphMap    = std::unordered_map<GlyphId, SimpleGlyph>;
using CompositeGlyphMap = std::unordered_map<GlyphId, CompositeGlyph>;

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

    std::int16_t prev_value = 0;
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

        coordinates.push_back(prev_value + offset);
        prev_value = coordinates.back();
    }

    return coordinates;
}

void check_simple_glyph(const SimpleGlyph& glyph)
{
    if (glyph.flags.size() != glyph.x_coordinates.size() || glyph.flags.size() != glyph.y_coordinates.size()) {
        throw ParsingError("Flags and coordinates arrays must be the same langth.");
    }

    // Check that the all contour endpoints do not exceeds total points amount
    bool end_points_correct = std::all_of(glyph.end_pts_of_contours.begin(),
                                          glyph.end_pts_of_contours.end(),
                                          [size = glyph.flags.size()](const auto& p) { return p < size; });
    if (!end_points_correct) {
        throw ParsingError("End points of contours is greater than count of points in contour.");
    }

    // First contour has at leas 3 points.
    end_points_correct &= glyph.end_pts_of_contours[0] > 2;

    // All other contours has at least 3 points.
    for (size_t i = 1; i < glyph.end_pts_of_contours.size(); ++i) {
        int diff = glyph.end_pts_of_contours[i] - glyph.end_pts_of_contours[i - 1];
        if (diff < 3) {
            end_points_correct = false;
            break;
        }
    }

    if (!end_points_correct) {
        throw ParsingError("All contours must have at least three points.");
    }
}

SimpleGlyph parse_simple_glyph(size_t number_of_contours, BufferReader& in)
{
    SimpleGlyph data;

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

    if (number_of_contours == 0) {
        return data;
    }

    // end_pts_of_contours stores the index of the end points.
    // Therefore the number of coordinates is the last index + 1
    const std::uint16_t points_count = data.end_pts_of_contours.back() + 1;

    data.flags         = parse_flags(points_count, in);
    data.x_coordinates = parse_coordinates(points_count, XCoordinatesInterpretator(data.flags), in);
    data.y_coordinates = parse_coordinates(points_count, YCoordinatesInterpretator(data.flags), in);

    check_simple_glyph(data);

    return data;
}

std::vector<CompositeGlyphComponent> parse_composite_glyph_components(BufferReader& in)
{
    std::vector<CompositeGlyphComponent> components;

    do {
        CompositeGlyphComponent component;

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

    if (components.empty()) {
        throw ParsingError("All composite glyphs must have components.");
    }

    if ((components.front().flags & CompositeGlyphFlags::args_are_xy_values) == 0) {
        throw ParsingError("The CompositeGlyphFlags::args_are_xy_values for first component must be set.");
    }

    return components;
}

CompositeGlyph parse_composite_glyph(BufferReader& in)
{
    CompositeGlyph data;

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

GlyphData::Contours get_glyph_contours(const SimpleGlyph& glyph)
{
    using framework::math::Vector2f;

    GlyphData::Contours result;

    std::size_t contour_start_point = 0;
    for (std::uint16_t contour_last_point : glyph.end_pts_of_contours) {
        const std::size_t contour_size = contour_last_point + 1;

        GlyphData::ControlPoint prev_point;

        GlyphData::ContourType contour;
        contour.reserve(contour_size);

        for (std::size_t i = contour_start_point; i < contour_size; ++i) {
            auto pos         = Vector2f{glyph.x_coordinates[i], glyph.y_coordinates[i]};
            bool is_on_curve = (glyph.flags[i] & SimpleGlyphFlags::on_curve_point);

            // Two control point is not on contour. Need to insert real point between them.
            if (!prev_point.is_on_curve && !is_on_curve) {
                contour.push_back({mix(prev_point.position, pos, 0.5f), true});
            }

            contour.push_back({pos, is_on_curve});
            prev_point = contour.back();
        }

        result.push_back(contour);

        contour_start_point = contour_size;
    }

    return result;
}

#pragma region class GlyphData::GlyphHeader

class GlyphHeader
{
public:
    explicit GlyphHeader(BufferReader& in);

    std::int16_t number_of_contours = 0;
    std::int16_t x_min              = 0;
    std::int16_t y_min              = 0;
    std::int16_t x_max              = 0;
    std::int16_t y_max              = 0;
};

GlyphHeader::GlyphHeader(BufferReader& in)
{
    in >> number_of_contours;
    in >> x_min;
    in >> y_min;
    in >> x_max;
    in >> y_max;
}

#pragma endregion

void add_component_data(SimpleGlyph& new_glyph,
                        const CompositeGlyphComponent& component,
                        const SimpleGlyph& component_glyph)
{
    if (component.flags & CompositeGlyphFlags::args_are_xy_values) {
        const std::uint16_t end_pts_offset = static_cast<std::uint16_t>(new_glyph.flags.size());
        std::transform(component_glyph.end_pts_of_contours.begin(),
                       component_glyph.end_pts_of_contours.end(),
                       std::inserter(new_glyph.end_pts_of_contours, new_glyph.end_pts_of_contours.end()),
                       [end_pts_offset](const auto& end_point_of_contour) {
                           return static_cast<std::uint16_t>(end_point_of_contour + end_pts_offset);
                       });

        new_glyph.flags.insert(new_glyph.flags.end(), component_glyph.flags.begin(), component_glyph.flags.end());

        std::transform(component_glyph.x_coordinates.begin(),
                       component_glyph.x_coordinates.end(),
                       std::inserter(new_glyph.x_coordinates, new_glyph.x_coordinates.end()),
                       [dx = component.argument1](const auto& x) { return static_cast<std::int16_t>(x + dx); });

        std::transform(component_glyph.y_coordinates.begin(),
                       component_glyph.y_coordinates.end(),
                       std::inserter(new_glyph.y_coordinates, new_glyph.y_coordinates.end()),
                       [dy = component.argument2](const auto& y) { return static_cast<std::int16_t>(y + dy); });

    } else {
        throw NotImplementedError("add_component_data: Offset componrnts by point is not inmplemented.");
    }
}

std::optional<SimpleGlyph> convert_composite_glyph(const CompositeGlyph& glyph, const SimpleGlyphMap& simple_glyphs)
{
    SimpleGlyph new_glyph;

    for (const auto& component : glyph.components) {
        const auto& component_glyph = simple_glyphs.find(component.glyph_index);
        if (component_glyph == simple_glyphs.end()) {
            return std::nullopt;
        }
        add_component_data(new_glyph, component, component_glyph->second);
    }

    check_simple_glyph(new_glyph);
    return {new_glyph};
}

} // namespace

namespace framework::graphics::details::font
{

GlyphData::GlyphData(std::uint16_t num_glyphs, const std::vector<Offset32>& offsets, const BytesData& data)
{
    m_glyphs.reserve(num_glyphs);

    SimpleGlyphMap simple_glyphs;
    CompositeGlyphMap composite_glyphs;

    for (GlyphId id = 0; id < num_glyphs; ++id) {
        DataIterator begin = std::next(data.begin(), offsets[id]);
        DataIterator end   = std::next(data.begin(), offsets[id + 1u]);

        BufferReader in = utils::make_big_endian_buffer_reader(begin, end);
        if (in) {
            const GlyphHeader header(in);
            if (header.number_of_contours >= 0) {
                simple_glyphs.emplace(id, parse_simple_glyph(static_cast<size_t>(header.number_of_contours), in));
            } else {
                composite_glyphs.emplace(id, parse_composite_glyph(in));
            }
        } else {
            // Glyph has no outline, e.g. some space character
            m_glyphs.emplace(id, Contours{});
        }
    }

    for (int counter = 0; counter < 32 && !composite_glyphs.empty(); ++counter) {
        for (auto it = composite_glyphs.begin(); it != composite_glyphs.end();) {
            const auto res = convert_composite_glyph(it->second, simple_glyphs);
            if (res.has_value()) {
                simple_glyphs.emplace(it->first, res.value());
                it = composite_glyphs.erase(it);
            } else {
                ++it;
            }
        }
    }

    if (!composite_glyphs.empty()) {
        throw ParsingError("All composite glyphs must be converted to simple glyphs.");
    }

    for (const auto& [id, simple_glyph] : simple_glyphs) {
        m_glyphs.emplace(id, get_glyph_contours(simple_glyph));
    }
}

bool GlyphData::valid() const
{
    return !m_glyphs.empty();
}

bool GlyphData::has(GlyphId index) const
{
    return m_glyphs.count(index) != 0;
}

const GlyphData::Contours& GlyphData::at(GlyphId index) const
{
    return m_glyphs.at(index);
}

} // namespace framework::graphics::details::font
