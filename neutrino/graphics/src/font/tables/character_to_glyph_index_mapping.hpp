#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_CHARACTER_TO_GLYPH_INDEX_MAPPING_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_CHARACTER_TO_GLYPH_INDEX_MAPPING_HPP

#include <unordered_map>
#include <vector>

#include <common/utf.hpp>

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

        virtual void parse(std::uint32_t offset, const std::vector<std::uint8_t>& data) = 0;
        virtual bool valid() const                                                      = 0;
    };

    explicit CharacterToGlyphIndexMapping(const std::vector<std::uint8_t>& data);

    bool valid() const;

    GlyphId get_glyph_index(utf::CodePoint code_point);

private:
    std::uint16_t m_version = 0;
    std::unique_ptr<Subtable> m_subtable;
};

} // namespace framework::graphics::details::font

#endif
