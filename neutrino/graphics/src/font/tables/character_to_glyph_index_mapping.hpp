#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_CHARACTER_TO_GLYPH_INDEX_MAPPING_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_CHARACTER_TO_GLYPH_INDEX_MAPPING_HPP

#include <unordered_map>
#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class CharacterToGlyphIndexMapping final
{
public:
    class Subtable
    {
    public:
        virtual ~Subtable() = default;

        virtual void parse(std::uint32_t offset, const BytesData& data) = 0;
        virtual GlyphId get_glyph_index(CodePoint codepoint)            = 0;

        virtual bool valid() const                     = 0;
        virtual std::unique_ptr<Subtable> copy() const = 0;
    };

    explicit CharacterToGlyphIndexMapping(const BytesData& data);

    CharacterToGlyphIndexMapping(const CharacterToGlyphIndexMapping& other);
    CharacterToGlyphIndexMapping(CharacterToGlyphIndexMapping&& other) = default;

    CharacterToGlyphIndexMapping& operator=(const CharacterToGlyphIndexMapping& other);
    CharacterToGlyphIndexMapping& operator=(CharacterToGlyphIndexMapping&& other) = default;

    ~CharacterToGlyphIndexMapping() = default;

    bool valid() const;

    GlyphId get_glyph_index(CodePoint codepoint) const;

private:
    std::uint16_t m_version = 0;
    std::unique_ptr<Subtable> m_subtable;
};

} // namespace framework::graphics::details::font

#endif
