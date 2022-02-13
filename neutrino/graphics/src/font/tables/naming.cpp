#include <common/utf.hpp>
#include <common/utils.hpp>

#include <graphics/src/font/tables/naming.hpp>

namespace framework::graphics::details::font
{

Naming::Naming(const std::vector<std::uint8_t>& data)
{
    m_version        = utils::big_endian_value<std::uint16_t>(data.begin(), data.end());
    m_count          = utils::big_endian_value<std::uint16_t>(data.begin() + 2, data.end());
    m_storage_offset = utils::big_endian_value<Offset16>(data.begin() + 4, data.end());

    auto from = std::next(data.begin(), 6);

    m_name_records.reserve(m_count);

    for (size_t i = 0; i < m_count; ++i) {

        NameRecord record;

        record.platform_id   = utils::big_endian_value<PlatformId>(from, data.end());
        record.encoding_id   = utils::big_endian_value<std::uint16_t>(from + 2, data.end());
        record.language_id   = utils::big_endian_value<std::uint16_t>(from + 4, data.end());
        record.name_id       = utils::big_endian_value<NameId>(from + 6, data.end());
        record.length        = utils::big_endian_value<std::uint16_t>(from + 8, data.end());
        record.string_offset = utils::big_endian_value<Offset16>(from + 10, data.end());

        m_name_records.push_back(std::move(record));
        std::advance(from, 12);
    }

    if (m_version == 1) {
        m_lang_tag_count = utils::big_endian_value<std::uint16_t>(from, data.end());
        std::advance(from, 2);

        m_lang_tag_records.reserve(m_lang_tag_count);
        for (size_t i = 0; i < m_lang_tag_count; ++i) {

            LangTagRecord record;
            record.length          = utils::big_endian_value<std::uint16_t>(from, data.end());
            record.lang_tag_offset = utils::big_endian_value<Offset16>(from + 2, data.end());

            m_lang_tag_records.push_back(std::move(record));
            std::advance(from, 4);
        }
    }

    for (const auto& name : {NameId::Copyright,
                             NameId::FontFamilyName,
                             NameId::FontSubfamilyName,
                             NameId::FullFontName,
                             NameId::VersionString,
                             NameId::PostScriptName,
                             NameId::Trademark,
                             NameId::ManufacturerName,
                             NameId::Designer,
                             NameId::Description,
                             NameId::UrlVendor,
                             NameId::UrlDesigner,
                             NameId::LicenseDescription,
                             NameId::LicenseInfoUrl,
                             NameId::TypographicFamilyName,
                             NameId::TypographicSubfamilyName,
                             NameId::CompatibleFullName,
                             NameId::SampleText,
                             NameId::PostScriptCIDFindfontName,
                             NameId::WWSFamilyName,
                             NameId::WWSSubfamilyName,
                             NameId::LightBackgroundPalette,
                             NameId::DarkBackgroundPalette,
                             NameId::VariationsPostScriptNamePrefix}) {
        m_strings[name] = read_string(name, data);
    }
}

bool Naming::valid() const
{
    bool valid = true;

    valid &= m_version == 0 || m_version == 1;

    return valid;
}

std::string Naming::get_string(NameId name_id) const
{
    if (const auto& it = m_strings.find(name_id); it != m_strings.end()) {
        return it->second;
    }

    return std::string();
}

std::string Naming::read_string(Naming::NameId name_id, const std::vector<std::uint8_t>& data)
{
    auto is_unicode = [name_id](const NameRecord& record) {
        constexpr static std::array<std::uint16_t, 2> unicode_encoding_ids = {3, 4};

        const bool supported_encoding = std::find(unicode_encoding_ids.begin(),
                                                  unicode_encoding_ids.end(),
                                                  record.encoding_id) != unicode_encoding_ids.end();

        return record.name_id == name_id && record.platform_id == PlatformId::Unicode && supported_encoding;
    };

    auto is_windows = [name_id](const NameRecord& record) {
        constexpr std::uint16_t windows_encoding_id = 1;

        return record.name_id == name_id && record.platform_id == PlatformId::Windows &&
               record.encoding_id == windows_encoding_id;
    };

    auto it = std::find_if(m_name_records.begin(), m_name_records.end(), is_unicode);

    if (it == m_name_records.end()) {
        it = std::find_if(m_name_records.begin(), m_name_records.end(), is_windows);
    }

    if (it == m_name_records.end()) {
        return std::string();
    }

    const size_t offset = static_cast<size_t>(m_storage_offset) + it->string_offset;
    if (data.size() < offset + it->length) {
        return std::string();
    }

    const size_t length = it->length / sizeof(char16_t);

    auto from = data.begin() + static_cast<std::ptrdiff_t>(offset);
    std::u16string str(length, '\0');
    for (size_t i = 0; i < length; i++) {
        str[i] = utils::big_endian_value<char16_t>(from);
        std::advance(from, sizeof(char16_t));
    }

    return utf::to_utf8(str);
}

} // namespace framework::graphics::details::font
