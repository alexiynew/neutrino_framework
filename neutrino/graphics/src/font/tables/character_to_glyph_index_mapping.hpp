#ifndef GRAPHICS_SRC_FONT_TABLES_CHARACTER_TO_GLYPH_INDEX_MAPPING_HPP
#define GRAPHICS_SRC_FONT_TABLES_CHARACTER_TO_GLYPH_INDEX_MAPPING_HPP

#include <unordered_map>
#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class Subtable;

class CharacterToGlyphIndexMapping final
{
public:
    explicit CharacterToGlyphIndexMapping(const BytesData& data);

    CharacterToGlyphIndexMapping(const CharacterToGlyphIndexMapping& other);
    CharacterToGlyphIndexMapping(CharacterToGlyphIndexMapping&& other);

    ~CharacterToGlyphIndexMapping();

    CharacterToGlyphIndexMapping& operator=(const CharacterToGlyphIndexMapping& other);
    CharacterToGlyphIndexMapping& operator=(CharacterToGlyphIndexMapping&& other);

    bool valid() const;

    GlyphId glyph_index(CodePoint codepoint) const;

private:
    std::uint16_t m_version = 0;
    std::unique_ptr<Subtable> m_subtable;
};

} // namespace framework::graphics::details::font

#endif
