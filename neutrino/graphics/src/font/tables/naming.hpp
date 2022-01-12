#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_NAMING_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_NAMING_HPP

#include <unordered_map>
#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct Naming
{
    // Some name id's
    enum class NameId : std::uint16_t
    {
        Copyright         = 0,
        FontFamilyName    = 1,
        FontSubfamilyName = 2,
        FullFontName      = 4,
        VersionString     = 5,

        Undefined = 0xFFFF,
    };

    struct NameRecord
    {
        PlatformId platform_id    = PlatformId::Undefined;
        std::uint16_t encoding_id = 0;
        std::uint16_t language_id = 0;
        NameId name_id            = NameId::Undefined;
        std::uint16_t length      = 0;
        Offset16 offset           = 0;
    };

    struct LangTagRecord
    {
        std::uint16_t length = 0;
        Offset16 offset      = 0;
    };

    using NamesMap = std::unordered_map<NameId, std::string>;

    static Naming parse(const std::vector<std::uint8_t>& data);

    bool valid() const;
    std::string get_string(NameId name_id) const;

    std::uint16_t format   = 0;
    std::uint16_t count    = 0;
    Offset16 string_offset = 0;
    std::vector<NameRecord> name_records;

    // for format 1 only
    std::uint16_t lang_tag_count = 0;
    std::vector<LangTagRecord> lang_tag_records;

private:
    static std::string read_string(Naming table, NameId name_id, const std::vector<std::uint8_t>& data);

    NamesMap m_strings;
};

} // namespace framework::graphics::details::font

#endif
