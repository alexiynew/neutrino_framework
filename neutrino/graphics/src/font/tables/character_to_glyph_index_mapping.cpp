#include <set>

#include <common/utils.hpp>

#include <graphics/src/font/tables/character_to_glyph_index_mapping.hpp>

namespace
{

namespace utils   = framework::utils;
namespace details = framework::graphics::details::font;

using details::BytesData;
using details::CharacterToGlyphIndexMapping;
using details::CodePoint;
using details::GlyphId;
using details::NotImplementedError;
using details::PlatformId;
using details::UnsupportedError;

struct EncodingRecord
{
    PlatformId platform_id    = PlatformId::Undefined;
    std::uint16_t encoding_id = 0;
    std::uint32_t offset      = 0; // Byte offset from beginning of table to the subtable for this encoding.
};

#pragma region SubtableFormat4

class SubtableFormat4 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const BytesData& data) override;
    GlyphId get_glyph_index(CodePoint codepoint) override;

    bool valid() const override;
    std::unique_ptr<Subtable> copy() const override;

private:
    std::uint16_t m_format         = 0;
    std::uint16_t m_length         = 0;
    std::uint16_t m_language       = 0;
    std::uint16_t m_seg_count_x2   = 0;
    std::uint16_t m_search_range   = 0;
    std::uint16_t m_entry_selector = 0;
    std::uint16_t m_range_shift    = 0;
    std::vector<std::uint16_t> m_end_code; //[segcount]
    std::uint16_t m_reserved_pad = 0;
    std::vector<std::uint16_t> m_start_code;      //[segcount]
    std::vector<std::int16_t> m_id_delta;         //[segcount]
    std::vector<std::uint16_t> m_id_range_offset; //[segcount]
    std::vector<std::uint16_t> m_glyph_id_array;
};

void SubtableFormat4::parse(std::uint32_t offset, const BytesData& data)
{
    auto from = std::next(data.begin(), offset);

    m_format         = utils::big_endian_value<std::uint16_t>(from);
    m_length         = utils::big_endian_value<std::uint16_t>(from + 2);
    m_language       = utils::big_endian_value<std::uint16_t>(from + 4);
    m_seg_count_x2   = utils::big_endian_value<std::uint16_t>(from + 6);
    m_search_range   = utils::big_endian_value<std::uint16_t>(from + 8);
    m_entry_selector = utils::big_endian_value<std::uint16_t>(from + 10);
    m_range_shift    = utils::big_endian_value<std::uint16_t>(from + 12);

    std::advance(from, 14);

    const size_t seg_count = m_seg_count_x2 / 2;

    m_end_code.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        m_end_code.push_back(utils::big_endian_value<std::uint16_t>(from));
        std::advance(from, 2);
    }

    m_reserved_pad = utils::big_endian_value<std::uint16_t>(from);
    std::advance(from, 2);

    m_start_code.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        m_start_code.push_back(utils::big_endian_value<std::uint16_t>(from));
        std::advance(from, 2);
    }

    m_id_delta.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        m_id_delta.push_back(utils::big_endian_value<std::int16_t>(from));
        std::advance(from, 2);
    }

    m_id_range_offset.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        m_id_range_offset.push_back(utils::big_endian_value<std::uint16_t>(from));
        std::advance(from, 2);
    }

    const auto end    = std::next(data.begin(), m_length);
    const size_t size = static_cast<size_t>(std::distance(from, end) / 2);

    m_glyph_id_array.reserve(size);
    while (from != end) {
        m_glyph_id_array.push_back(utils::big_endian_value<std::uint16_t>(from));
        std::advance(from, 2);
    }
}

GlyphId SubtableFormat4::get_glyph_index(CodePoint)
{
    throw NotImplementedError("SubtableFormat4 get_glyph_index is not implemented yet");

    // return details::missig_glyph_id;
}

bool SubtableFormat4::valid() const
{
    const size_t seg_count = m_seg_count_x2 / 2;

    return m_format == 4 && m_end_code.size() == seg_count && m_start_code.size() == seg_count &&
           m_id_delta.size() == seg_count && m_id_range_offset.size() == seg_count && !m_glyph_id_array.empty();
}

std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> SubtableFormat4::copy() const
{
    return std::make_unique<SubtableFormat4>(*this);
}

#pragma endregion

#pragma region SubtableFormat6

class SubtableFormat6 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const BytesData& data) override;
    GlyphId get_glyph_index(CodePoint codepoint) override;

    bool valid() const override;
    std::unique_ptr<Subtable> copy() const override;

private:
    // std::uint16_t m_format      = 0;
    // std::uint16_t m_length      = 0;
    // std::uint16_t m_language    = 0;
    // std::uint16_t m_first_code  = 0;
    // std::uint16_t m_entry_count = 0;
    // std::vector<std::uint16_t> m_glyph_id_array; //[entrycount]
};

void SubtableFormat6::parse(std::uint32_t, const BytesData&)
{
    throw NotImplementedError("SubtableFormat6 parsing is not implemented yet");
}

GlyphId SubtableFormat6::get_glyph_index(CodePoint)
{
    throw NotImplementedError("SubtableFormat6 get_glyph_index is not implemented yet");
}

bool SubtableFormat6::valid() const
{
    return false;
}

std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> SubtableFormat6::copy() const
{
    return std::make_unique<SubtableFormat6>(*this);
}

#pragma endregion

#pragma region SubtableFormat10

class SubtableFormat10 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const BytesData& data) override;
    GlyphId get_glyph_index(CodePoint codepoint) override;

    bool valid() const override;
    std::unique_ptr<Subtable> copy() const override;
};

void SubtableFormat10::parse(std::uint32_t, const BytesData&)
{
    throw NotImplementedError("SubtableFormat10 parsing is not implemented yet");
}

GlyphId SubtableFormat10::get_glyph_index(CodePoint)
{
    throw NotImplementedError("SubtableFormat10 get_glyph_index is not implemented yet");
}

bool SubtableFormat10::valid() const
{
    return false;
}

std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> SubtableFormat10::copy() const
{
    return std::make_unique<SubtableFormat10>(*this);
}

#pragma endregion

#pragma region SubtableFormat12

class SubtableFormat12 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const BytesData& data) override;
    GlyphId get_glyph_index(CodePoint codepoint) override;

    bool valid() const override;
    std::unique_ptr<Subtable> copy() const override;
};

void SubtableFormat12::parse(std::uint32_t, const BytesData&)
{
    throw NotImplementedError("SubtableFormat12 parsing is not implemented yet");
}

GlyphId SubtableFormat12::get_glyph_index(CodePoint)
{
    throw NotImplementedError("SubtableFormat12 get_glyph_index is not implemented yet");
}

bool SubtableFormat12::valid() const
{
    return false;
}

std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> SubtableFormat12::copy() const
{
    return std::make_unique<SubtableFormat12>(*this);
}

#pragma endregion

#pragma region SubtableFormat13

class SubtableFormat13 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const BytesData& data) override;
    GlyphId get_glyph_index(CodePoint codepoint) override;

    bool valid() const override;
    std::unique_ptr<Subtable> copy() const override;
};

void SubtableFormat13::parse(std::uint32_t, const BytesData&)
{
    throw NotImplementedError("SubtableFormat13 parsing is not implemented yet");
}

GlyphId SubtableFormat13::get_glyph_index(CodePoint)
{
    throw NotImplementedError("SubtableFormat13 get_glyph_index is not implemented yet");
}

bool SubtableFormat13::valid() const
{
    return false;
}

std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> SubtableFormat13::copy() const
{
    return std::make_unique<SubtableFormat13>(*this);
}

#pragma endregion

#pragma region SubtableFormat14

class SubtableFormat14 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const BytesData& data) override;
    GlyphId get_glyph_index(CodePoint codepoint) override;

    bool valid() const override;
    std::unique_ptr<Subtable> copy() const override;
};

void SubtableFormat14::parse(std::uint32_t, const BytesData&)
{
    throw NotImplementedError("SubtableFormat14 parsing is not implemented yet");
}

GlyphId SubtableFormat14::get_glyph_index(CodePoint)
{
    throw NotImplementedError("SubtableFormat14 get_glyph_index is not implemented yet");
}

bool SubtableFormat14::valid() const
{
    return false;
}

std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> SubtableFormat14::copy() const
{
    return std::make_unique<SubtableFormat14>(*this);
}

#pragma endregion

#pragma region Helper functions

std::vector<EncodingRecord> get_encoding_records(std::uint32_t offset, size_t num_tables, const BytesData& data)
{
    static constexpr size_t record_size = 8;

    std::vector<EncodingRecord> encoding_records;
    encoding_records.reserve(num_tables);

    auto from = std::next(data.begin(), offset);
    for (size_t i = 0; i < num_tables; ++i) {

        EncodingRecord record;
        record.platform_id = utils::big_endian_value<PlatformId>(from);
        record.encoding_id = utils::big_endian_value<std::uint16_t>(from + 2);
        record.offset      = utils::big_endian_value<std::uint32_t>(from + 4);

        encoding_records.push_back(record);
        std::advance(from, record_size);
    }

    return encoding_records;
}

std::vector<EncodingRecord> find_unicode_encoding_records(const std::vector<EncodingRecord>& encoding_records)
{
    using framework::graphics::details::font::PlatformId;

    auto is_unicode = [](const EncodingRecord& record) {
        constexpr static std::array<std::uint16_t, 4> supported_encoding_ids = {3, 4, 5, 6};

        const bool supported_encoding = std::find(supported_encoding_ids.begin(),
                                                  supported_encoding_ids.end(),
                                                  record.encoding_id) != supported_encoding_ids.end();
        return record.platform_id == PlatformId::Unicode && supported_encoding;
    };

    std::vector<EncodingRecord> unicode_records;
    std::copy_if(encoding_records.begin(), encoding_records.end(), std::back_inserter(unicode_records), is_unicode);

    return unicode_records;
}

std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> parse_subtable(
const std::vector<EncodingRecord>& encoding_records,
const BytesData& data)
{
    auto create_subtable = [](std::uint16_t format) -> std::unique_ptr<CharacterToGlyphIndexMapping::Subtable> {
        switch (format) {
            case 4: return std::make_unique<SubtableFormat4>();
            case 6: return std::make_unique<SubtableFormat6>();
            case 10: return std::make_unique<SubtableFormat10>();
            case 12: return std::make_unique<SubtableFormat12>();
            case 13: return std::make_unique<SubtableFormat13>();
            case 14: return std::make_unique<SubtableFormat14>();
        }

        return nullptr;
    };

    for (const auto& record : encoding_records) {
        const auto from      = std::next(data.begin(), record.offset);
        std::uint16_t format = utils::big_endian_value<std::uint16_t>(from);

        auto subtable = create_subtable(format);
        if (subtable) {
            subtable->parse(record.offset, data);
            return subtable;
        }
    }

    return nullptr;
}

#pragma endregion

} // namespace

namespace framework::graphics::details::font
{

CharacterToGlyphIndexMapping::CharacterToGlyphIndexMapping(const BytesData& data)
{
    const std::uint16_t version    = utils::big_endian_value<std::uint16_t>(data.begin());
    const std::uint16_t num_tables = utils::big_endian_value<std::uint16_t>(data.begin() + 2);

    const std::vector<EncodingRecord> encoding_records         = get_encoding_records(4, num_tables, data);
    const std::vector<EncodingRecord> unicode_encoding_records = find_unicode_encoding_records(encoding_records);

    if (unicode_encoding_records.empty()) {
        throw UnsupportedError("Can't find unicode encoding records");
    }

    m_version  = version;
    m_subtable = parse_subtable(unicode_encoding_records, data);
}

CharacterToGlyphIndexMapping::CharacterToGlyphIndexMapping(const CharacterToGlyphIndexMapping& other)
    : m_version(other.m_version)
    , m_subtable(other.m_subtable->copy())
{}

CharacterToGlyphIndexMapping& CharacterToGlyphIndexMapping::operator=(const CharacterToGlyphIndexMapping& other)
{
    using std::swap;

    CharacterToGlyphIndexMapping tmp(other);

    swap(tmp.m_version, m_version);
    swap(tmp.m_subtable, m_subtable);

    return *this;
}

bool CharacterToGlyphIndexMapping::valid() const
{
    return m_version == 0 && m_subtable != nullptr && m_subtable->valid();
}

GlyphId CharacterToGlyphIndexMapping::get_glyph_index(CodePoint codepoint) const
{
    if (m_subtable) {
        return m_subtable->get_glyph_index(codepoint);
    }

    return missig_glyph_id;
}

} // namespace framework::graphics::details::font
