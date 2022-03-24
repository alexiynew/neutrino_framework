#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_NAMING_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_NAMING_HPP

#include <unordered_map>
#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class Naming final
{
public:
    // Some name id's
    enum class NameId : std::uint16_t
    {
        Copyright          = 0,
        FontFamilyName     = 1,
        FontSubfamilyName  = 2,
        FullFontName       = 4,
        VersionString      = 5,
        PostScriptName     = 6,
        Trademark          = 7,
        ManufacturerName   = 8,
        Designer           = 9,
        Description        = 10,
        UrlVendor          = 11,
        UrlDesigner        = 12,
        LicenseDescription = 13,
        LicenseInfoUrl     = 14,

        // Id 15 is reserved

        TypographicFamilyName          = 16,
        TypographicSubfamilyName       = 17,
        CompatibleFullName             = 18,
        SampleText                     = 19,
        PostScriptCIDFindfontName      = 20,
        WWSFamilyName                  = 21,
        WWSSubfamilyName               = 22,
        LightBackgroundPalette         = 23,
        DarkBackgroundPalette          = 24,
        VariationsPostScriptNamePrefix = 25,

        Undefined = 0xFFFF,
    };

    explicit Naming(const BytesData& data);

    bool valid() const;
    std::string get_string(NameId name_id) const;

private:
    struct NameRecord
    {
        PlatformId platform_id    = PlatformId::Undefined;
        std::uint16_t encoding_id = 0;
        std::uint16_t language_id = 0;
        NameId name_id            = NameId::Undefined;
        std::uint16_t length      = 0;
        Offset16 string_offset    = 0;
    };

    struct LangTagRecord
    {
        std::uint16_t length     = 0;
        Offset16 lang_tag_offset = 0;
    };

    using NamesMap = std::unordered_map<NameId, std::string>;

    std::string read_string(NameId name_id, const BytesData& data);

    std::uint16_t m_version   = 0;
    std::uint16_t m_count     = 0;
    Offset16 m_storage_offset = 0;
    std::vector<NameRecord> m_name_records; // [m_count]

    // for format 1 only
    std::uint16_t m_lang_tag_count = 0;
    std::vector<LangTagRecord> m_lang_tag_records; // [m_lang_tag_count]

    NamesMap m_strings;
};

} // namespace framework::graphics::details::font

#endif
