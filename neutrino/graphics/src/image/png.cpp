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
#include <cmath>
#include <fstream>
#include <vector>

#include <common/crc.hpp>
#include <common/types.hpp>
#include <common/zlib.hpp>
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

constexpr usize signature_length = 8;
constexpr usize pass_count       = 7;

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
    return (((static_cast<uint32>(type) >> 24) & 0xFF) & 0x20) == 0;
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

enum class filter_type_t
{
    none    = 0,
    sub     = 1,
    up      = 2,
    average = 3,
    peath   = 4
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

struct pass_info
{
    usize width;
    usize height;
    struct
    {
        usize w, h;
    } pos;
    struct
    {
        usize w, h;
    } offset;
};

inline std::array<pass_info, pass_count> get_pass_info(const file_header_t& header)
{
    std::array<pass_info, pass_count> info;

    info[0].width  = (header.width + 7) / 8;
    info[0].height = (header.height + 7) / 8;
    info[0].pos    = {0, 0};
    info[0].offset = {8, 8};

    info[1].width  = (header.width + 3) / 8;
    info[1].height = (header.height + 7) / 8;
    info[1].pos    = {4, 0};
    info[1].offset = {8, 8};

    info[2].width  = (header.width + 3) / 4;
    info[2].height = (header.height + 3) / 8;
    info[2].pos    = {0, 4};
    info[2].offset = {4, 8};

    info[3].width  = (header.width + 1) / 4;
    info[3].height = (header.height + 3) / 4;
    info[3].pos    = {2, 0};
    info[3].offset = {4, 4};

    info[4].width  = (header.width + 1) / 2;
    info[4].height = (header.height + 1) / 4;
    info[4].pos    = {0, 2};
    info[4].offset = {2, 4};

    info[5].width  = (header.width + 0) / 2;
    info[5].height = (header.height + 1) / 2;
    info[5].pos    = {1, 0};
    info[5].offset = {2, 2};

    info[6].width  = (header.width + 0) / 1;
    info[6].height = (header.height + 0) / 2;
    info[6].pos    = {0, 1};
    info[6].offset = {1, 2};

    return info;
}

std::vector<uint8> generate_samples(uint8 bit_depth)
{
    std::vector<uint8> res(static_cast<usize>(std::pow(2, bit_depth)));

    const uint32 maxinput  = static_cast<uint32>(std::pow(2, bit_depth) - 1);
    const uint32 maxoutput = static_cast<uint32>(std::pow(2, 8) - 1);
    const uint32 factor    = maxoutput / maxinput;

    for (uint32 input = 0; input <= maxinput; input++) {
        res[input] = static_cast<uint8>(input * factor);
    }

    return res;
}

std::vector<uint8> reconstruct(const file_header_t& header, std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<uint8>();
    }

    std::vector<uint8> res;

    auto reconstruct_pass = [&res, bit_depth = header.bit_depth](const pass_info& pass,
                                                                 std::vector<uint8>::iterator it) {
        const usize bytes = (pass.width * bit_depth + 7) / 8;
        for (usize h = 0; h < pass.height; ++h) {
            const filter_type_t ft = static_cast<filter_type_t>(*it++);
            for (usize b = 0; b < bytes; ++b) {
                switch (ft) {
                    case filter_type_t::none: res.push_back(*it++); break;
                    case filter_type_t::sub: break;
                    case filter_type_t::up: break;
                    case filter_type_t::average: break;
                    case filter_type_t::peath: break;
                }
            }
        }

        return it;
    };

    switch (header.interlace_method) {
        case file_header_t::interlace_method_t::adam7: {
            auto it = data.begin();
            for (const auto& info : get_pass_info(header)) {
                it = reconstruct_pass(info, it);
            }
        } break;
        case file_header_t::interlace_method_t::no:
            reconstruct_pass({header.width, header.height, {0, 0}, {1, 1}}, data.begin());
            break;
    }

    return res;
}

std::vector<color_t> unserialize(const file_header_t& header, std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<color_t>();
    }

    const auto samples = generate_samples(header.bit_depth);

    std::vector<color_t> res(header.width * header.height, color_t(uint32(0xFF0000FF)));

    auto unserialize_pass = [&res, &header, &samples](const pass_info& pass, std::vector<uint8>::iterator it) {
        const usize bytes = (pass.width * header.bit_depth + 7) / 8;

        auto [x, y] = pass.pos;
        for (usize h = 0; h < pass.height; ++h) {
            const usize pos = (header.height - y - 1) * header.width;
            for (usize b = 0, w = 0; b < bytes && w < pass.width; ++b) {
                const uint8 value = *it++;
                switch (header.bit_depth) {
                    case 1:
                        for (usize i = 0; i < 8 && w < pass.width; ++i, ++w) {
                            const uint8 color = samples[(value >> (7 - i)) & 0x01];
                            res[pos + x]      = color_t(color, color, color, 0xFF);
                            x += pass.offset.w;
                        }
                        break;
                    case 2:
                        for (usize i = 0; i < 8 && w < pass.width; i += 2, ++w) {
                            const uint8 color = samples[(value >> (6 - i)) & 0x03];
                            res[pos + x]      = color_t(color, color, color, 0xFF);
                            x += pass.offset.w;
                        }
                        break;
                    case 4:
                        for (usize i = 0; i < 8 && w < pass.width; i += 4, ++w) {
                            const uint8 color = samples[(value >> (4 - i)) & 0x0F];
                            res[pos + x]      = color_t(color, color, color, 0xFF);
                            x += pass.offset.w;
                        }
                        break;
                    default: break;
                }
            }
            x = pass.pos.w;
            y += pass.offset.h;
        }

        return it;
    };

    switch (header.interlace_method) {
        case file_header_t::interlace_method_t::adam7: {
            auto it     = data.begin();
            auto passes = get_pass_info(header);

            it = unserialize_pass(passes[0], it);
            it = unserialize_pass(passes[1], it);
            it = unserialize_pass(passes[2], it);
            it = unserialize_pass(passes[3], it);
            it = unserialize_pass(passes[4], it);
            it = unserialize_pass(passes[5], it);
            it = unserialize_pass(passes[6], it);
        } break;
        case file_header_t::interlace_method_t::no:
            unserialize_pass({header.width, header.height, {0, 0}, {1, 1}}, data.begin());
            break;
    }

    return res;
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

    std::vector<color_t> res = unserialize(header, reconstruct(header, utils::zlib::inflate(data)));

    return std::make_optional(std::make_tuple(make_image_info(header), std::move(res)));
}

bool is_png(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    return check_signature(read_bytes(file, signature_length));
}

} // namespace framework::graphics::details::image::png
