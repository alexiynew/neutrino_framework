#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_GLYPH_MAP_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_GLYPH_MAP_HPP

#include <unordered_map>
#include <vector>

#include <common/utf.hpp>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct GlyphMap
{
    using GlyphIndex    = std::uint32_t;
    using GlyphIndexMap = std::unordered_map<utf::CodePoint, GlyphIndex>;

    struct EncodingRecord
    {
        PlatformId platform_id    = PlatformId::Undefined;
        std::uint16_t encoding_id = 0;
        std::uint32_t offset      = 0; // Byte offset from beginning of table to the subtable for this encoding.
    };

    static GlyphMap parse(const std::vector<std::uint8_t>& data);

    bool valid() const;

    std::uint16_t version    = 0;
    std::uint16_t num_tables = 0;
    std::vector<EncodingRecord> encoding_records;

    GlyphIndexMap glyphs;
};

} // namespace framework::graphics::details::font

#endif
