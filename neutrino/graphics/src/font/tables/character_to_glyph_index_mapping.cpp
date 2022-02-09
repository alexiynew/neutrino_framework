#include <set>

#include <common/utils.hpp>

#include <graphics/src/font/tables/character_to_glyph_index_mapping.hpp>

namespace
{

namespace utils = framework::utils;

using framework::graphics::details::font::CharacterToGlyphIndexMapping;
using framework::graphics::details::font::PlatformId;
using framework::graphics::details::font::UnimplementedError;
using framework::graphics::details::font::UnsupportedError;

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
    void parse(std::uint32_t offset, const std::vector<std::uint8_t>& data) override;
    bool valid() const override;

    std::uint16_t format         = 0;
    std::uint16_t length         = 0;
    std::uint16_t language       = 0;
    std::uint16_t seg_count_x2   = 0;
    std::uint16_t search_range   = 0;
    std::uint16_t entry_selector = 0;
    std::uint16_t range_shift    = 0;
    std::vector<std::uint16_t> end_code; //[segcount]
    std::uint16_t reserved_pad = 0;
    std::vector<std::uint16_t> start_code;      //[segcount]
    std::vector<std::int16_t> id_delta;         //[segcount]
    std::vector<std::uint16_t> id_range_offset; //[segcount]
    std::vector<std::uint16_t> glyph_id_array;
};

void SubtableFormat4::parse(std::uint32_t offset, const std::vector<std::uint8_t>& data)
{
    auto from = std::next(data.begin(), offset);

    format         = utils::big_endian_value<std::uint16_t>(from, data.end());
    length         = utils::big_endian_value<std::uint16_t>(from + 2, data.end());
    language       = utils::big_endian_value<std::uint16_t>(from + 4, data.end());
    seg_count_x2   = utils::big_endian_value<std::uint16_t>(from + 6, data.end());
    search_range   = utils::big_endian_value<std::uint16_t>(from + 8, data.end());
    entry_selector = utils::big_endian_value<std::uint16_t>(from + 10, data.end());
    range_shift    = utils::big_endian_value<std::uint16_t>(from + 12, data.end());

    std::advance(from, 14);

    const size_t seg_count = seg_count_x2 / 2;

    end_code.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        end_code.push_back(utils::big_endian_value<std::uint16_t>(from, data.end()));
        std::advance(from, 2);
    }

    reserved_pad = utils::big_endian_value<std::uint16_t>(from, data.end());
    std::advance(from, 2);

    start_code.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        start_code.push_back(utils::big_endian_value<std::uint16_t>(from, data.end()));
        std::advance(from, 2);
    }

    id_delta.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        id_delta.push_back(utils::big_endian_value<std::int16_t>(from, data.end()));
        std::advance(from, 2);
    }

    id_range_offset.reserve(seg_count);
    for (size_t i = 0; i < seg_count; ++i) {
        id_range_offset.push_back(utils::big_endian_value<std::uint16_t>(from, data.end()));
        std::advance(from, 2);
    }

    const auto end    = std::next(data.begin(), length);
    const size_t size = static_cast<size_t>(std::distance(from, end) / 2);

    glyph_id_array.reserve(size);
    while (from != end) {
        glyph_id_array.push_back(utils::big_endian_value<std::uint16_t>(from, end));
        std::advance(from, 2);
    }
}

bool SubtableFormat4::valid() const
{
    return false;
}

#pragma endregion

#pragma region SubtableFormat6

class SubtableFormat6 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const std::vector<std::uint8_t>& data) override;
    bool valid() const override;

    std::uint16_t format      = 0;
    std::uint16_t length      = 0;
    std::uint16_t language    = 0;
    std::uint16_t first_code  = 0;
    std::uint16_t entry_count = 0;
    std::vector<std::uint16_t> glyph_id_array; //[entrycount]
};

void SubtableFormat6::parse(std::uint32_t, const std::vector<std::uint8_t>&)
{
    throw UnimplementedError("SubtableFormat6 parsing is not implemented yet");
}

bool SubtableFormat6::valid() const
{
    return false;
}

#pragma endregion

#pragma region SubtableFormat10

class SubtableFormat10 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const std::vector<std::uint8_t>& data) override;
    bool valid() const override;
};

void SubtableFormat10::parse(std::uint32_t, const std::vector<std::uint8_t>&)
{
    throw UnimplementedError("SubtableFormat10 parsing is not implemented yet");
}

bool SubtableFormat10::valid() const
{
    return false;
}

#pragma endregion

#pragma region SubtableFormat12

class SubtableFormat12 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const std::vector<std::uint8_t>& data) override;
    bool valid() const override;
};

void SubtableFormat12::parse(std::uint32_t, const std::vector<std::uint8_t>&)
{
    throw UnimplementedError("SubtableFormat12 parsing is not implemented yet");
}

bool SubtableFormat12::valid() const
{
    return false;
}

#pragma endregion

#pragma region SubtableFormat13

class SubtableFormat13 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const std::vector<std::uint8_t>& data) override;
    bool valid() const override;
};

void SubtableFormat13::parse(std::uint32_t, const std::vector<std::uint8_t>&)
{
    throw UnimplementedError("SubtableFormat13 parsing is not implemented yet");
}

bool SubtableFormat13::valid() const
{
    return false;
}

#pragma endregion

#pragma region SubtableFormat14

class SubtableFormat14 final : public CharacterToGlyphIndexMapping::Subtable
{
public:
    void parse(std::uint32_t offset, const std::vector<std::uint8_t>& data) override;
    bool valid() const override;
};

void SubtableFormat14::parse(std::uint32_t, const std::vector<std::uint8_t>&)
{
    throw UnimplementedError("SubtableFormat14 parsing is not implemented yet");
}

bool SubtableFormat14::valid() const
{
    return false;
}

#pragma endregion

#pragma region Helper functions

std::vector<EncodingRecord> get_encoding_records(std::uint32_t offset,
                                                 size_t num_tables,
                                                 const std::vector<std::uint8_t>& data)
{
    static constexpr size_t record_size = 8;

    std::vector<EncodingRecord> encoding_records;
    encoding_records.reserve(num_tables);

    auto from = std::next(data.begin(), offset);
    for (size_t i = 0; i < num_tables; ++i) {

        EncodingRecord record;
        record.platform_id = utils::big_endian_value<PlatformId>(from, data.end());
        record.encoding_id = utils::big_endian_value<std::uint16_t>(from + 2, data.end());
        record.offset      = utils::big_endian_value<std::uint32_t>(from + 4, data.end());

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
const std::vector<std::uint8_t>& data)
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
        std::uint16_t format = utils::big_endian_value<std::uint16_t>(from, data.end());

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

CharacterToGlyphIndexMapping::CharacterToGlyphIndexMapping(const std::vector<std::uint8_t>& data)
{
    const std::uint16_t version    = utils::big_endian_value<std::uint16_t>(data.begin(), data.end());
    const std::uint16_t num_tables = utils::big_endian_value<std::uint16_t>(data.begin() + 2, data.end());

    const std::vector<EncodingRecord> encoding_records         = get_encoding_records(4, num_tables, data);
    const std::vector<EncodingRecord> unicode_encoding_records = find_unicode_encoding_records(encoding_records);

    if (unicode_encoding_records.empty()) {
        throw UnsupportedError("Can't find unicode encoding records");
    }

    m_version  = version;
    m_subtable = parse_subtable(unicode_encoding_records, data);
}

bool CharacterToGlyphIndexMapping::valid() const
{
    return m_version == 0 && m_subtable != nullptr && m_subtable->valid();
}

} // namespace framework::graphics::details::font
