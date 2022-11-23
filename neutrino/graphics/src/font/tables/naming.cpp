#include <common/utf.hpp>
#include <common/utils.hpp>

#include <graphics/src/font/tables/naming.hpp>

namespace neutrino::graphics::details::font
{

Naming::Naming(const BytesData& data)
{
    auto in = utils::make_big_endian_buffer_reader(data);

    in >> m_version;
    in >> m_count;
    in >> m_storage_offset;

    m_name_records.reserve(m_count);
    for (size_t i = 0; i < m_count; ++i) {
        NameRecord record;

        in >> record.platform_id;
        in >> record.encoding_id;
        in >> record.language_id;
        in >> record.name_id;
        in >> record.length;
        in >> record.string_offset;

        m_name_records.push_back(std::move(record));
    }

    if (m_version == 1) {
        in >> m_lang_tag_count;

        m_lang_tag_records.reserve(m_lang_tag_count);
        for (size_t i = 0; i < m_lang_tag_count; ++i) {
            LangTagRecord record;
            in >> record.length;
            in >> record.lang_tag_offset;

            m_lang_tag_records.push_back(std::move(record));
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

bool Naming::is_valid() const
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

std::string Naming::read_string(Naming::NameId name_id, const BytesData& data)
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

} // namespace neutrino::graphics::details::font
