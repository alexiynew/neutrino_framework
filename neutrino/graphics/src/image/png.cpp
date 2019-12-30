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
#include <functional>
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

std::vector<uint8> read_bytes(std::ifstream& in, usize count)
{
    std::vector<uint8> data(count);

    in.read(reinterpret_cast<char*>(data.data()), static_cast<std::streamsize>(count));

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

#pragma region chunk

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
    bool valid() const;
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

bool chunk_t::valid() const
{
    framework::utils::crc32 crc_calk;

    crc_calk.update(big_endian_value<uint32>(reinterpret_cast<const char*>(&type)));
    crc_calk.update(begin(data), end(data));

    return crc_calk.current_value() == crc;
}

#pragma endregion chunk

#pragma region file header

enum class color_type_t : uint8
{
    greyscale       = 0,
    truecolor       = 2,
    indexed         = 3,
    greyscale_alpha = 4,
    truecolor_alpha = 6,
};

enum class compression_method_t : uint8
{
    deflate_inflate = 0,
};

enum class filter_method_t : uint8
{
    adaptive = 0,
};

enum class interlace_method_t : uint8
{
    no    = 0,
    adam7 = 1,
};

struct file_header_t
{
    int32 width                             = 0;
    int32 height                            = 0;
    uint8 bit_depth                         = 0;
    color_type_t color_type                 = color_type_t::greyscale;
    compression_method_t compression_method = compression_method_t::deflate_inflate;
    filter_method_t filter_method           = filter_method_t::adaptive;
    interlace_method_t interlace_method     = interlace_method_t::no;

    static file_header_t read(std::ifstream& in);

    bool valid() const;
    int32 samples_per_pixel() const;
    int32 bits_per_pixel() const;
    int32 bytes_per_pixel() const;

    image_info get_image_info() const;
};

file_header_t file_header_t::read(std::ifstream& in)
{
    auto c = chunk_t::read(in);
    if (c.type != chunk_t::type_t::IHDR || !c.valid()) {
        return file_header_t();
    }

    file_header_t h;
    h.width              = big_endian_value<int32>(&c.data[0]);
    h.height             = big_endian_value<int32>(&c.data[4]);
    h.bit_depth          = c.data[8];
    h.color_type         = static_cast<color_type_t>(c.data[9]);
    h.compression_method = static_cast<compression_method_t>(c.data[10]);
    h.filter_method      = static_cast<filter_method_t>(c.data[11]);
    h.interlace_method   = static_cast<interlace_method_t>(c.data[12]);

    return h;
}

bool file_header_t::valid() const
{
    auto valid_bit_depth = [=]() {
        switch (color_type) {
            case color_type_t::greyscale:
                return (bit_depth == 1 || bit_depth == 2 || bit_depth == 4 || bit_depth == 8 || bit_depth == 16);
            case color_type_t::truecolor: return (bit_depth == 8 || bit_depth == 16);
            case color_type_t::indexed: return (bit_depth == 1 || bit_depth == 2 || bit_depth == 4 || bit_depth == 8);
            case color_type_t::greyscale_alpha: return (bit_depth == 8 || bit_depth == 16);
            case color_type_t::truecolor_alpha: return (bit_depth == 8 || bit_depth == 16);
        }
        return false;
    };

    bool valid = true;

    valid &= valid_bit_depth();
    valid &= compression_method == compression_method_t::deflate_inflate;
    valid &= filter_method == filter_method_t::adaptive;
    valid &= (interlace_method == interlace_method_t::no || interlace_method == interlace_method_t::adam7);

    return valid;
}

int32 file_header_t::samples_per_pixel() const
{
    switch (color_type) {
        case color_type_t::greyscale: return 1;
        case color_type_t::truecolor: return 3;
        case color_type_t::indexed: return 1;
        case color_type_t::greyscale_alpha: return 2;
        case color_type_t::truecolor_alpha: return 4;
    }

    return 0;
}

int32 file_header_t::bits_per_pixel() const
{
    return samples_per_pixel() * bit_depth;
}

int32 file_header_t::bytes_per_pixel() const
{
    return (bits_per_pixel() + 7) / 8;
}

image_info file_header_t::get_image_info() const
{
    return image_info{width, height, true};
}

bool check_signature(const std::vector<uint8>& data)
{
    constexpr std::array<uint8, signature_length> signature = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

    if (data.size() < signature.size()) {
        return false;
    }

    for (usize i = 0; i < signature.size(); ++i) {
        if (data[i] != signature[i]) {
            return false;
        }
    }

    return true;
}

#pragma endregion

#pragma region pass info

struct pass_info
{
    struct position_t
    {
        int32 x;
        int32 y;
    };

    struct offset_t
    {
        int32 x;
        int32 y;
    };

    pass_info(int32 w, int32 h, int32 b, position_t p, offset_t o)
        : width(w), height(h), bytes_per_scanline(b), position(p), offset(o)
    {}

    const int32 width;
    const int32 height;
    const int32 bytes_per_scanline;
    const position_t position;
    const offset_t offset;
};

std::vector<pass_info> get_pass_info(const file_header_t& header)
{
    std::vector<pass_info> info;

    switch (header.interlace_method) {
        case interlace_method_t::adam7: {
            const std::array<int32, pass_count> widths = {(header.width + 7) / 8,
                                                          (header.width + 3) / 8,
                                                          (header.width + 3) / 4,
                                                          (header.width + 1) / 4,
                                                          (header.width + 1) / 2,
                                                          (header.width + 0) / 2,
                                                          (header.width + 0) / 1};

            const std::array<int32, pass_count> heights = {(header.height + 7) / 8,
                                                           (header.height + 7) / 8,
                                                           (header.height + 3) / 8,
                                                           (header.height + 3) / 4,
                                                           (header.height + 1) / 4,
                                                           (header.height + 1) / 2,
                                                           (header.height + 0) / 2};

            const std::array<pass_info::position_t, pass_count> positions =
            {pass_info::position_t{0, 0}, {4, 0}, {0, 4}, {2, 0}, {0, 2}, {1, 0}, {0, 1}};

            const std::array<pass_info::offset_t, pass_count> offsets =
            {pass_info::offset_t{8, 8}, {8, 8}, {4, 8}, {4, 4}, {2, 4}, {2, 2}, {1, 2}};

            for (usize i = 0; i < pass_count; ++i) {
                if (widths[i] == 0 || heights[i] == 0) {
                    continue;
                }

                const int32 bytes_per_scanline = (widths[i] * header.bits_per_pixel() + 7) / 8;
                info.push_back(pass_info(widths[i], heights[i], bytes_per_scanline, positions[i], offsets[i]));
            }
        } break;
        case interlace_method_t::no: {
            info.push_back(
            pass_info(header.width, header.height, (header.width * header.bits_per_pixel() + 7) / 8, {0, 0}, {1, 1}));
        } break;
    }

    return info;
} // namespace

#pragma endregion

#pragma region filter reconstruction

template <typename In, typename Out>
inline void reconstruct_sub(In first, In last, In a, Out x)
{
    while (first != last) {
        *x++ = static_cast<uint8>((static_cast<int32>(*a++) + *first++) & 0xFF);
    }
}

template <typename In, typename Out>
inline void reconstruct_up(In first, In last, In b, Out x)
{
    while (first != last) {
        *x++ = static_cast<uint8>((static_cast<int32>(*b++) + *first++) & 0xFF);
    }
}

template <typename In, typename Out>
inline void reconstruct_average(In first, In last, In a, In b, Out x)
{
    while (first != last) {
        *x++ = static_cast<uint8>((((static_cast<int32>(*a++) + *b++) >> 1) + *first++) & 0xFF);
    }
}

uint8 paeth_predictor(int32 a, int32 b, int32 c)
{
    const int32 p  = a + b - c;
    const int32 pa = abs(p - a);
    const int32 pb = abs(p - b);
    const int32 pc = abs(p - c);

    if (pa <= pb && pa <= pc) {
        return static_cast<uint8>(a);
    } else if (pb <= pc) {
        return static_cast<uint8>(b);
    } else {
        return static_cast<uint8>(c);
    }
}

template <typename In, typename Out>
inline void reconstruct_peath(In first, In last, In a, In b, In c, Out x)
{
    while (first != last) {
        *x++ = static_cast<uint8>((static_cast<int32>(paeth_predictor(*a++, *b++, *c++)) + *first++) & 0xFF);
    }
}

enum class filter_type_t : uint8
{
    none    = 0,
    sub     = 1,
    up      = 2,
    average = 3,
    peath   = 4
};

std::tuple<std::vector<uint8>::iterator, std::vector<uint8>::iterator> reconstruct_pass(std::vector<uint8>::iterator in,
                                                                                        std::vector<uint8>::iterator out,
                                                                                        const pass_info& pass,
                                                                                        int32 bytes_per_pixel)
{
    const int32 bytes_in_row = (pass.bytes_per_scanline + bytes_per_pixel);
    std::vector<uint8> res(static_cast<usize>(bytes_in_row * (pass.height + 1)), 0);

    auto res_a = next(res.begin(), bytes_in_row);
    auto res_b = next(res.begin(), bytes_per_pixel);
    auto res_c = res.begin();
    auto res_x = next(res.begin(), bytes_in_row + bytes_per_pixel);

    for (int32 h = 0; h < pass.height; ++h) {
        const filter_type_t ft = static_cast<filter_type_t>(*in++);

        auto last = next(in, pass.bytes_per_scanline);

        switch (ft) {
            case filter_type_t::none: std::copy(in, last, res_x); break;
            case filter_type_t::sub: reconstruct_sub(in, last, res_a, res_x); break;
            case filter_type_t::up: reconstruct_up(in, last, res_b, res_x); break;
            case filter_type_t::average: reconstruct_average(in, last, res_a, res_b, res_x); break;
            case filter_type_t::peath: reconstruct_peath(in, last, res_a, res_b, res_c, res_x); break;
        }

        advance(res_a, bytes_in_row);
        advance(res_b, bytes_in_row);
        advance(res_c, bytes_in_row);
        advance(res_x, bytes_in_row);
        in = last;
    }

    auto it = next(res.begin(), bytes_in_row + bytes_per_pixel);
    for (int32 h = 0; h < pass.height; ++h) {
        auto last = next(it, static_cast<ptrdiff_t>(pass.bytes_per_scanline));

        out = std::copy(it, last, out);

        advance(it, bytes_in_row);
    }

    return std::make_tuple(in, out);
}

std::vector<uint8> reconstruct(const file_header_t& header, std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<uint8>();
    }

    std::vector<uint8> res(data.size(), 0);

    auto in  = data.begin();
    auto out = res.begin();
    for (const auto& pass : get_pass_info(header)) {
        std::tie(in, out) = reconstruct_pass(in, out, pass, header.bytes_per_pixel());
    }

    return res;
}

#pragma endregion

#pragma region unserialize

template <usize BitDepth>
constexpr uint8 sample(usize input)
{
    static_assert(BitDepth < 8);
    constexpr usize maxinput  = (1 << BitDepth) - 1;
    constexpr usize maxoutput = (1 << 8) - 1;
    return static_cast<uint8>(input * maxoutput / maxinput);
}

template <usize N, usize Size = (1 << N)>
using palette_t = std::array<color_t, Size>;

template <usize BitDepth>
constexpr palette_t<BitDepth> greyscale_palette()
{
    static_assert(BitDepth < 8);
    palette_t<BitDepth> res = {color_t(0x000000FFU)};

    for (usize input = 0; input < res.size(); input++) {
        const uint8 c = sample<BitDepth>(input);
        res[input]    = color_t(c, c, c, 0xFF);
    }

    return res;
}

template <usize BitDepth>
palette_t<BitDepth> read_palette(const chunk_t chunk)
{
    static_assert(BitDepth <= 8);
    palette_t<BitDepth> res = {color_t(0x000000FFU)};

    if (chunk.type != chunk_t::type_t::PLTE || (chunk.data.size() % 3 != 0)) {
        return res;
    }

    for (usize i = 0; i < chunk.data.size() / 3; ++i) {
        res[i].r = chunk.data[i * 3];
        res[i].g = chunk.data[i * 3 + 1];
        res[i].b = chunk.data[i * 3 + 2];
    }

    return res;
}

using sample_tuple_t = std::tuple<color_t, std::vector<uint8>::iterator>;

template <color_type_t ColorType, uint8 BitDepth>
inline sample_tuple_t get_color(std::vector<uint8>::iterator in);

template <>
inline sample_tuple_t get_color<color_type_t::greyscale, 8>(std::vector<uint8>::iterator in)
{
    const uint8 c = *in++;
    return std::make_tuple(color_t(c, c, c, 0xFF), in);
}

template <>
inline sample_tuple_t get_color<color_type_t::greyscale, 16>(std::vector<uint8>::iterator in)
{
    const uint8 c = *in++;
    in++;
    return std::make_tuple(color_t(c, c, c, 0xFF), in);
}

template <>
inline sample_tuple_t get_color<color_type_t::truecolor, 8>(std::vector<uint8>::iterator in)
{
    const uint8 r = *in++;
    const uint8 g = *in++;
    const uint8 b = *in++;

    return std::make_tuple(color_t(r, g, b, 0xFF), in);
}

template <>
inline sample_tuple_t get_color<color_type_t::truecolor, 16>(std::vector<uint8>::iterator in)
{
    const uint8 r = *in++;
    in++;
    const uint8 g = *in++;
    in++;
    const uint8 b = *in++;
    in++;

    return std::make_tuple(color_t(r, g, b, 0xFF), in);
}

template <>
inline sample_tuple_t get_color<color_type_t::greyscale_alpha, 8>(std::vector<uint8>::iterator in)
{
    const uint8 c = *in++;
    const uint8 a = *in++;
    return std::make_tuple(color_t(c, c, c, a), in);
}

template <>
inline sample_tuple_t get_color<color_type_t::greyscale_alpha, 16>(std::vector<uint8>::iterator in)
{
    const uint8 c = *in++;
    in++;
    const uint8 a = *in++;
    in++;
    return std::make_tuple(color_t(c, c, c, a), in);
}

template <>
inline sample_tuple_t get_color<color_type_t::truecolor_alpha, 8>(std::vector<uint8>::iterator in)
{
    const uint8 r = *in++;
    const uint8 g = *in++;
    const uint8 b = *in++;
    const uint8 a = *in++;

    return std::make_tuple(color_t(r, g, b, a), in);
}

template <>
inline sample_tuple_t get_color<color_type_t::truecolor_alpha, 16>(std::vector<uint8>::iterator in)
{
    const uint8 r = *in++;
    in++;
    const uint8 g = *in++;
    in++;
    const uint8 b = *in++;
    in++;
    const uint8 a = *in++;
    in++;

    return std::make_tuple(color_t(r, g, b, a), in);
}

template <color_type_t ColorType, uint8 BitDepth>
inline std::vector<uint8>::iterator unserialize_pass(std::vector<uint8>::iterator in,
                                                     const pass_info& pass,
                                                     const file_header_t& header,
                                                     std::vector<color_t>& out)
{
    static_assert(BitDepth == 8 || BitDepth == 16);
    for (int32 h = 0; h < pass.height; ++h) {
        uint32 pos = static_cast<uint32>((header.height - 1 - (pass.position.y + pass.offset.y * h)) * header.width +
                                         pass.position.x);
        for (int32 w = 0; w < pass.width; ++w) {
            std::tie(out[pos], in) = get_color<ColorType, BitDepth>(in);
            pos += static_cast<uint32>(pass.offset.x);
        }
    }

    return in;
}

template <uint8 BitDepth>
inline std::vector<uint8>::iterator unserialize_palette_pass(std::vector<uint8>::iterator in,
                                                             const pass_info& pass,
                                                             const file_header_t& header,
                                                             const palette_t<BitDepth>& palette,
                                                             std::vector<color_t>& out)
{
    static_assert(BitDepth <= 8);
    constexpr usize mask = (1 << BitDepth) - 1;

    for (int32 h = 0; h < pass.height; ++h) {
        uint32 pos = static_cast<uint32>((header.height - 1 - (pass.position.y + pass.offset.y * h)) * header.width +
                                         pass.position.x);
        uint8 byte = 0;
        for (int32 w = 0, i = 0; w < pass.width; ++w, i = (i + BitDepth) % 8) {
            if (i == 0) {
                byte = *in++;
            }
            out[pos] = palette[(byte >> ((8 - BitDepth) - i)) & mask];
            pos += static_cast<uint32>(pass.offset.x);
        }
    }

    return in;
}

template <color_type_t ColorType, uint8 BitDepth>
inline std::vector<color_t> unserialize_impl(const file_header_t& header, std::vector<uint8>&& data)
{
    static_assert(BitDepth == 8 || BitDepth == 16);
    std::vector<color_t> res(static_cast<usize>(header.width * header.height), color_t(uint32(0x000000FF)));

    auto in = data.begin();
    for (const auto& pass : get_pass_info(header)) {
        in = unserialize_pass<ColorType, BitDepth>(in, pass, header, res);
    }

    return res;
}

template <uint8 BitDepth>
inline std::vector<color_t> unserialize_palette_impl(const file_header_t& header,
                                                     const palette_t<BitDepth>& palette,
                                                     std::vector<uint8>&& data)
{
    static_assert(BitDepth <= 8);
    std::vector<color_t> res(static_cast<usize>(header.width * header.height), color_t(uint32(0x000000FF)));

    auto in = data.begin();
    for (const auto& pass : get_pass_info(header)) {
        in = unserialize_palette_pass<BitDepth>(in, pass, header, palette, res);
    }

    return res;
}

inline std::vector<color_t> unserialize_greyscale(const file_header_t& header, std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<color_t>();
    }

    switch (header.bit_depth) {
        case 1: return unserialize_palette_impl<1>(header, greyscale_palette<1>(), std::move(data));
        case 2: return unserialize_palette_impl<2>(header, greyscale_palette<2>(), std::move(data));
        case 4: return unserialize_palette_impl<4>(header, greyscale_palette<4>(), std::move(data));
        case 8: return unserialize_impl<color_type_t::greyscale, 8>(header, std::move(data));
        case 16: return unserialize_impl<color_type_t::greyscale, 16>(header, std::move(data));
    }

    return std::vector<color_t>();
}

inline std::vector<color_t> unserialize_truecolor(const file_header_t& header, std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<color_t>();
    }

    switch (header.bit_depth) {
        case 8: return unserialize_impl<color_type_t::truecolor, 8>(header, std::move(data));
        case 16: return unserialize_impl<color_type_t::truecolor, 16>(header, std::move(data));
    }

    return std::vector<color_t>();
}

inline std::vector<color_t> unserialize_indexed(const file_header_t& header,
                                                const chunk_t& plte_chunk,
                                                std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<color_t>();
    }

    switch (header.bit_depth) {
        case 1: return unserialize_palette_impl<1>(header, read_palette<1>(plte_chunk), std::move(data));
        case 2: return unserialize_palette_impl<2>(header, read_palette<2>(plte_chunk), std::move(data));
        case 4: return unserialize_palette_impl<4>(header, read_palette<4>(plte_chunk), std::move(data));
        case 8: return unserialize_palette_impl<8>(header, read_palette<8>(plte_chunk), std::move(data));
    }

    return std::vector<color_t>();
}

inline std::vector<color_t> unserialize_greyscale_alpha(const file_header_t& header, std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<color_t>();
    }

    switch (header.bit_depth) {
        case 8: return unserialize_impl<color_type_t::greyscale_alpha, 8>(header, std::move(data));
        case 16: return unserialize_impl<color_type_t::greyscale_alpha, 16>(header, std::move(data));
    }

    return std::vector<color_t>();
}

inline std::vector<color_t> unserialize_truecolor_alpha(const file_header_t& header, std::vector<uint8>&& data)
{
    if (data.empty()) {
        return std::vector<color_t>();
    }

    switch (header.bit_depth) {
        case 8: return unserialize_impl<color_type_t::truecolor_alpha, 8>(header, std::move(data));
        case 16: return unserialize_impl<color_type_t::truecolor_alpha, 16>(header, std::move(data));
    }

    return std::vector<color_t>();
}

inline std::vector<color_t> unserialize(const file_header_t& header,
                                        const chunk_t& plte_chunk,
                                        std::vector<uint8>&& data)
{
    switch (header.color_type) {
        case color_type_t::greyscale: return unserialize_greyscale(header, std::move(data));
        case color_type_t::truecolor: return unserialize_truecolor(header, std::move(data));
        case color_type_t::indexed: return unserialize_indexed(header, plte_chunk, std::move(data));
        case color_type_t::greyscale_alpha: return unserialize_greyscale_alpha(header, std::move(data));
        case color_type_t::truecolor_alpha: return unserialize_truecolor_alpha(header, std::move(data));
    }

    return std::vector<color_t>();
}

#pragma endregion

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
    if (!header.valid()) {
        return load_result_t();
    }

    chunk_t plte_chunk;

    std::vector<uint8> data;
    for (chunk_t chunk = chunk_t::read(file); file && chunk.type != chunk_t::type_t::IEND;
         chunk         = chunk_t::read(file)) {
        if (!chunk.valid() && chunk.is_critical()) {
            return load_result_t();
        }

        switch (chunk.type) {
            case chunk_t::type_t::IHDR: break; // error
            case chunk_t::type_t::PLTE: {
                plte_chunk = chunk;
            } break;
            case chunk_t::type_t::IDAT: {
                data.insert(end(data), begin(chunk.data), end(chunk.data));
            } break;
            case chunk_t::type_t::IEND: break; // end
            case chunk_t::type_t::cHRM: break;
            case chunk_t::type_t::gAMA: break; // TODO (alex): gamma correction support
            case chunk_t::type_t::iCCP: break;
            case chunk_t::type_t::sBIT: break; // ignore
            case chunk_t::type_t::sRGB: break;
            case chunk_t::type_t::bKGD: break;
            case chunk_t::type_t::hIST: break;
            case chunk_t::type_t::tRNS: break;
            case chunk_t::type_t::pHYs: break;
            case chunk_t::type_t::sPLT: break;      // ignore
            case chunk_t::type_t::tIME: break;      // ignore
            case chunk_t::type_t::iTXt: break;      // ignore
            case chunk_t::type_t::tEXt: break;      // ignore
            case chunk_t::type_t::zTXt: break;      // ignore
            case chunk_t::type_t::undefined: break; // error
        }
    }

    std::vector<uint8> recontructed = reconstruct(header, utils::zlib::inflate(data));
    std::vector<color_t> image_data = unserialize(header, plte_chunk, std::move(recontructed));

    return std::make_optional(std::make_tuple(header.get_image_info(), std::move(image_data)));
}

bool is_png(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    return check_signature(read_bytes(file, signature_length));
}

} // namespace framework::graphics::details::image::png
