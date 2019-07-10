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

#include <array>
#include <fstream>
#include <vector>

#include <common/crc.hpp>
#include <common/types.hpp>

#include <graphics/details/image/png.hpp>

namespace
{
using framework::uint32;
using framework::uint8;
using crc32png = framework::utils::crc<32, 0xEDB88320, 0xFFFFFFFF, true, true, 0xFFFFFFFF>;

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

struct chunk
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

    static chunk read(std::ifstream& in);
};

chunk chunk::read(std::ifstream& in)
{
    chunk c;

    char buffer[4];

    in.read(buffer, 4);
    c.length = big_endian_value<uint32>(buffer);

    in.read(buffer, 4);
    c.type = big_endian_value<chunk::type_t>(buffer);

    if (c.length > 0) {
        c.data = read_bytes(in, c.length);
    }

    in.read(buffer, 4);
    c.crc = big_endian_value<uint32>(buffer);

    return c;
}

struct file_header
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

    static file_header read(std::ifstream& in);
};

bool check_crc(const chunk&)
{
    // TODO(alex) make crc checking
    return true;
}

file_header file_header::read(std::ifstream& in)
{
    auto c = chunk::read(in);
    if (c.type != chunk::type_t::IHDR || !check_crc(c)) {
        return file_header();
    }

    file_header h;
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
    constexpr std::array<uint8, 8> signature = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

    for (uint32 i = 0; i < signature.size(); ++i) {
        if (data[i] != signature[i]) {
            return false;
        }
    }

    return true;
}

bool check_header(const file_header& h)
{
    bool valid = true;

    valid &= [&h]() {
        using ct = file_header::color_type_t;

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

    valid &= h.compression_method == file_header::compression_method_t::deflate_inflate;
    valid &= h.filter_method == file_header::filter_method_t::adaptive;
    valid &= (h.interlace_method == file_header::interlace_method_t::no ||
              h.interlace_method == file_header::interlace_method_t::adam7);

    return valid;
}

void process(const file_header&, const chunk&)
{}

} // namespace

namespace framework::graphics::details::image::png
{
load_result_t load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return load_result_t();
    }

    auto signature = read_bytes(file, 8);
    if (!check_signature(signature)) {
        return load_result_t();
    }

    file_header h = file_header::read(file);
    if (!check_header(h)) {
        return load_result_t();
    }

    for (chunk c = chunk::read(file); file && c.type != chunk::type_t::IEND; c = chunk::read(file)) {
        switch (c.type) {
            case chunk::type_t::PLTE: process(h, c); break;
            case chunk::type_t::IDAT: process(h, c); break;
            case chunk::type_t::IEND: process(h, c); break;
            case chunk::type_t::cHRM: process(h, c); break;
            case chunk::type_t::gAMA: process(h, c); break;
            case chunk::type_t::iCCP: process(h, c); break;
            case chunk::type_t::sBIT: process(h, c); break;
            case chunk::type_t::sRGB: process(h, c); break;
            case chunk::type_t::bKGD: process(h, c); break;
            case chunk::type_t::hIST: process(h, c); break;
            case chunk::type_t::tRNS: process(h, c); break;
            case chunk::type_t::pHYs: process(h, c); break;
            case chunk::type_t::sPLT: process(h, c); break;
            case chunk::type_t::tIME: process(h, c); break;
            case chunk::type_t::iTXt: process(h, c); break;
            case chunk::type_t::tEXt: process(h, c); break;
            case chunk::type_t::zTXt: process(h, c); break;
            default: break;
        }
    }

    return load_result_t();
}

bool is_png(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    return check_signature(read_bytes(file, 8));
}

} // namespace framework::graphics::details::image