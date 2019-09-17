/// @file
/// @brief Png image implementation.
/// @author Fedorov Alexey
/// @date 05.04.2019

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

#include <common/crc.hpp>
#include <common/types.hpp>
#include <graphics/src/image/png.hpp>

namespace
{
using framework::int32;
using framework::uint16;
using framework::uint32;
using framework::uint8;
using framework::usize;
using framework::graphics::color_t;
using framework::graphics::details::image::image_info;

constexpr int signature_length = 8;

std::vector<uint8> read_bytes(std::ifstream& in, uint32 count)
{
    std::vector<uint8> data(count);
    in.read(reinterpret_cast<char*>(data.data()), count);

    if (!in) {
        return std::vector<uint8>();
    }

    return data;
}

template <typename T, typename B>
inline constexpr T big_endian_value(const B* buffer) noexcept
{
    constexpr uint32 size = sizeof(T);

    uint8 tmp[size];
    for (uint32 i = 0; i < size; ++i) {
        tmp[i] = (reinterpret_cast<const uint8*>(buffer))[size - i - 1];
    }

    return *(reinterpret_cast<T*>(tmp));
}

struct chunk_t
{
    enum class type_t : uint32
    {
        undefined = 0,
        IHDR      = 0x49484452,
        PLTE      = 0x504c5445,
        IDAT      = 0x49444154,
        IEND      = 0x49454e44,
        cHRM      = 0x6348524d,
        gAMA      = 0x67414d41,
        iCCP      = 0x69434350,
        sBIT      = 0x73424954,
        sRGB      = 0x73524742,
        bKGD      = 0x624b4744,
        hIST      = 0x68495354,
        tRNS      = 0x74524e53,
        pHYs      = 0x70485973,
        sPLT      = 0x73504c54,
        tIME      = 0x74494d45,
        iTXt      = 0x69545874,
        tEXt      = 0x74455874,
        zTXt      = 0x7a545874,
    };

    uint32 length = 0;
    type_t type   = type_t::undefined;
    uint32 crc    = 0;

    std::vector<uint8> data;

    static chunk_t read(std::ifstream& in);

    bool is_critical() const;
};

chunk_t chunk_t::read(std::ifstream& in)
{
    chunk_t c;

    char buffer[4];

    in.read(buffer, 4);
    c.length = big_endian_value<uint32>(buffer);

    in.read(buffer, 4);
    c.type = big_endian_value<chunk_t::type_t>(buffer);

    if (c.length > 0) {
        c.data = read_bytes(in, c.length);
    }

    in.read(buffer, 4);
    c.crc = big_endian_value<uint32>(buffer);

    return c;
}

bool chunk_t::is_critical() const
{
    return (((static_cast<uint32>(type) >> 24) && 0xFF) & 0x20) == 0;
}

struct file_header_t
{
    enum color_type_t : uint8
    {
        greyscale        = 0,
        truecolour       = 2,
        indexed          = 3,
        greyscale_alpha  = 4,
        truecolour_alpha = 6,
    };

    enum compression_method_t : uint8
    {
        deflate_inflate = 0,
    };

    enum filter_method_t : uint8
    {
        adaptive = 0,
    };

    enum interlace_method_t : uint8
    {
        no    = 0,
        adam7 = 1,
    };

    uint32 width                            = 0;
    uint32 height                           = 0;
    uint8 bit_depth                         = 0;
    color_type_t colour_type                = color_type_t::greyscale;
    compression_method_t compression_method = compression_method_t::deflate_inflate;
    filter_method_t filter_method           = filter_method_t::adaptive;
    interlace_method_t interlace_method     = interlace_method_t::no;

    static file_header_t read(std::ifstream& in);
};

bool check_crc(const chunk_t& c)
{
    framework::utils::crc32 crc;

    crc.update(big_endian_value<uint32>(reinterpret_cast<const char*>(&c.type)));
    crc.update(begin(c.data), end(c.data));

    return crc.current_value() == c.crc;
}

file_header_t file_header_t::read(std::ifstream& in)
{
    auto c = chunk_t::read(in);
    if (c.type != chunk_t::type_t::IHDR || !check_crc(c)) {
        return file_header_t();
    }

    file_header_t h;
    h.width              = big_endian_value<uint32>(&c.data[0]);
    h.height             = big_endian_value<uint32>(&c.data[4]);
    h.bit_depth          = c.data[8];
    h.colour_type        = static_cast<color_type_t>(c.data[9]);
    h.compression_method = static_cast<compression_method_t>(c.data[10]);
    h.filter_method      = static_cast<filter_method_t>(c.data[11]);
    h.interlace_method   = static_cast<interlace_method_t>(c.data[12]);

    return h;
}

bool check_signature(const std::vector<uint8>& data)
{
    constexpr std::array<uint8, signature_length> signature = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

    if (data.size() < signature.size()) {
        return false;
    }

    for (uint32 i = 0; i < signature.size(); ++i) {
        if (data[i] != signature[i]) {
            return false;
        }
    }

    return true;
}

bool check_header(const file_header_t& h)
{
    bool valid = true;

    valid &= [&h]() {
        using ct = file_header_t::color_type_t;

        switch (h.colour_type) {
            case ct::greyscale:
                return (h.bit_depth == 1 || h.bit_depth == 2 || h.bit_depth == 4 || h.bit_depth == 8 ||
                        h.bit_depth == 16);
            case ct::truecolour: return (h.bit_depth == 8 || h.bit_depth == 16);
            case ct::indexed: return (h.bit_depth == 1 || h.bit_depth == 2 || h.bit_depth == 4 || h.bit_depth == 8);
            case ct::greyscale_alpha: return (h.bit_depth == 8 || h.bit_depth == 16);
            case ct::truecolour_alpha: return (h.bit_depth == 8 || h.bit_depth == 16);
            default: break;
        }
        return false;
    }();

    valid &= h.compression_method == file_header_t::compression_method_t::deflate_inflate;
    valid &= h.filter_method == file_header_t::filter_method_t::adaptive;
    valid &= (h.interlace_method == file_header_t::interlace_method_t::no ||
              h.interlace_method == file_header_t::interlace_method_t::adam7);

    return valid;
}

inline image_info make_image_info(const file_header_t& header)
{
    return image_info{static_cast<int32>(header.width), static_cast<int32>(header.height), true};
}

struct zlib_header_t
{
    uint8 compression_method : 4;
    uint8 compression_info : 4;
    uint8 check_bits : 5;
    uint8 dictinary : 1;
    uint8 compression_level : 2;
};

class bit_stream
{
public:
    bit_stream(const std::vector<uint8>&);

    uint8 get_bits(uint8 count);
    void skip_current_byte();
    uint8 get_bytes(uint8);

    operator bool() const;

private:
    const std::vector<uint8>& m_data;
    usize m_byte_pos = 0;
    usize m_bit_pos  = 0;
};

bit_stream::bit_stream(const std::vector<uint8>& data) : m_data(data)
{}

bit_stream::operator bool() const
{
    return m_byte_pos < m_data.size() && m_bit_pos < 8;
}

uint8 bit_stream::get_bits(uint8 count)
{
    constexpr std::array<uint8, 9> mask = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};

    count = static_cast<uint8>(count % 8);

    uint8 byte          = m_data[m_byte_pos];
    const uint8 portion = std::min(static_cast<uint8>(7 - m_bit_pos), count);

    uint8 result = static_cast<uint8>((byte >> m_bit_pos) & mask[portion]);

    count = static_cast<uint8>(count - portion);
    m_bit_pos += portion;

    if (m_bit_pos == 7) {
        m_bit_pos = 0;
        m_byte_pos++;
    }

    if (count == 0) {
        return result;
    }

    byte = m_data[m_byte_pos];

    result = static_cast<uint8>(result | ((byte & mask[count]) << portion));
    m_bit_pos += count;

    return result;
}

void bit_stream::skip_current_byte()
{
    m_byte_pos++;
    m_bit_pos = 0;
}

std::vector<color_t> inflate(const file_header_t header, const std::vector<uint8>& data)
{
    std::vector<color_t> result;

    zlib_header_t zlib_header = *reinterpret_cast<const zlib_header_t*>(data.data());

    if (header.compression_method == file_header_t::compression_method_t::deflate_inflate &&
        zlib_header.compression_method != 8) {
        return std::vector<color_t>();
    }

    if (zlib_header.dictinary != 0) {
        return std::vector<color_t>();
    }

    bit_stream in(data);

    while (in) {
        uint8 block = in.get_bits(3);

        if ((block & 0x6) == 0) {
            in.skip_current_byte();
            const uint8 len  = in.get_bits(2);
            const uint8 nlen = in.get_bits(2);

            for (usize i = 0; i < len; ++i) {
            }
            // no compression
        } else {
        }
    }

    /*
    do
        read block header from input stream.
        if stored with no compression
            skip any remaining bits in current partially processed byte
            read LEN and NLEN (see next section)
            copy LEN bytes of data to output
        otherwise
            if compressed with dynamic Huffman codes
                read representation of code trees (see subsection below)
            loop (until end of block code recognized)
                decode literal/length value from input stream
                if value < 256
                    copy value (literal byte) to output stream
                otherwise
                    if value = end of block (256)
                        break from loop
                    otherwise (value = 257..285)
                        decode distance from input stream

                        move backwards distance bytes in the output
                        stream, and copy length bytes from this
                        position to the output stream.
            end loop
    while not last block
    */

    return result;
}

} // namespace

namespace framework::graphics::details::image::png
{
load_result_t load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return load_result_t();
    }

    auto signature = read_bytes(file, signature_length);
    if (!check_signature(signature)) {
        return load_result_t();
    }

    file_header_t header = file_header_t::read(file);
    if (!check_header(header)) {
        return load_result_t();
    }

    std::vector<uint8> data;
    for (chunk_t chunk = chunk_t::read(file); file && chunk.type != chunk_t::type_t::IEND;
         chunk         = chunk_t::read(file)) {
        if (!check_crc(chunk) && chunk.is_critical()) {
            return load_result_t();
        }

        switch (chunk.type) {
            case chunk_t::type_t::PLTE: break;
            case chunk_t::type_t::IDAT: {
                data.insert(end(data), begin(chunk.data), end(chunk.data));
            } break;
            case chunk_t::type_t::IEND: break;
            case chunk_t::type_t::cHRM: break;
            case chunk_t::type_t::gAMA: break;
            case chunk_t::type_t::iCCP: break;
            case chunk_t::type_t::sBIT: break;
            case chunk_t::type_t::sRGB: break;
            case chunk_t::type_t::bKGD: break;
            case chunk_t::type_t::hIST: break;
            case chunk_t::type_t::tRNS: break;
            case chunk_t::type_t::pHYs: break;
            case chunk_t::type_t::sPLT: break;
            case chunk_t::type_t::tIME: break;
            case chunk_t::type_t::iTXt: break;
            case chunk_t::type_t::tEXt: break;
            case chunk_t::type_t::zTXt: break;
            default: break;
        }
    }

    return std::make_optional(std::make_tuple(make_image_info(header), inflate(header, data)));
}

bool is_png(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    return check_signature(read_bytes(file, signature_length));
}

} // namespace framework::graphics::details::image::png