// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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
#include <common/utils.hpp>
#include <common/zlib.hpp>

#include <graphics/src/image/png.hpp>

namespace
{
using namespace framework;
using graphics::Color;
using graphics::details::image::ImageInfo;

inline constexpr size_t signature_length = 8;
inline constexpr size_t pass_count       = 7;

std::vector<std::uint8_t> read_bytes(std::ifstream& in, size_t count)
{
    std::vector<std::uint8_t> data(count);

    in.read(reinterpret_cast<char*>(data.data()), static_cast<std::streamsize>(count));

    if (!in) {
        return std::vector<std::uint8_t>();
    }

    return data;
}

#pragma region chunk

struct Chunk
{
    enum class Type : std::uint32_t
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

    std::uint32_t length = 0;
    Type type            = Type::undefined;
    std::uint32_t crc    = 0;

    std::vector<std::uint8_t> data;

    static Chunk read(std::ifstream& in);

    bool is_critical() const;
    bool valid() const;
};

Chunk Chunk::read(std::ifstream& in)
{
    using std::begin;
    using std::end;

    char buffer[4] = {0};

    Chunk c;

    in.read(buffer, 4);
    c.length = utils::big_endian_value<std::uint32_t>(begin(buffer), end(buffer));

    in.read(buffer, 4);
    c.type = utils::big_endian_value<Chunk::Type>(begin(buffer), end(buffer));

    if (c.length > 0) {
        c.data = read_bytes(in, c.length);
    }

    in.read(buffer, 4);
    c.crc = utils::big_endian_value<std::uint32_t>(begin(buffer), end(buffer));

    return c;
}

bool Chunk::is_critical() const
{
    return (((static_cast<std::uint32_t>(type) >> 24) & 0xFF) & 0x20) == 0;
}

bool Chunk::valid() const
{
    const char* begin         = reinterpret_cast<const char*>(&type);
    const char* end           = begin + 4;
    const std::uint32_t first = utils::big_endian_value<std::uint32_t>(begin, end);

    utils::Crc32 crc_calk;
    crc_calk.update(first);
    crc_calk.update(std::begin(data), std::end(data));

    return crc_calk.current_value() == crc;
}

#pragma endregion chunk

#pragma region file header

enum class ColorType : std::uint8_t
{
    greyscale       = 0,
    truecolor       = 2,
    indexed         = 3,
    greyscale_alpha = 4,
    truecolor_alpha = 6,
};

enum class CompressionMethod : std::uint8_t
{
    deflate_inflate = 0,
};

enum class FilterMethod : std::uint8_t
{
    adaptive = 0,
};

enum class InterlaceMethod : std::uint8_t
{
    no    = 0,
    adam7 = 1,
};

struct FileHeader
{
    std::int32_t width                   = 0;
    std::int32_t height                  = 0;
    std::uint8_t bit_depth               = 0;
    ColorType color_type                 = ColorType::greyscale;
    CompressionMethod compression_method = CompressionMethod::deflate_inflate;
    FilterMethod filter_method           = FilterMethod::adaptive;
    InterlaceMethod interlace_method     = InterlaceMethod::no;

    static FileHeader read(std::ifstream& in);

    bool valid() const;
    std::int32_t samples_per_pixel() const;
    std::int32_t bits_per_pixel() const;
    std::int32_t bytes_per_pixel() const;

    ImageInfo image_info() const;
};

FileHeader FileHeader::read(std::ifstream& in)
{
    auto c = Chunk::read(in);
    if (c.type != Chunk::Type::IHDR || !c.valid()) {
        return FileHeader();
    }

    FileHeader h;
    h.width              = utils::big_endian_value<std::int32_t>(c.data.begin(), c.data.end());
    h.height             = utils::big_endian_value<std::int32_t>(c.data.begin() + 4, c.data.end());
    h.bit_depth          = c.data[8];
    h.color_type         = static_cast<ColorType>(c.data[9]);
    h.compression_method = static_cast<CompressionMethod>(c.data[10]);
    h.filter_method      = static_cast<FilterMethod>(c.data[11]);
    h.interlace_method   = static_cast<InterlaceMethod>(c.data[12]);

    return h;
}

bool FileHeader::valid() const
{
    auto valid_bit_depth = [=]() {
        switch (color_type) {
            case ColorType::greyscale:
                return (bit_depth == 1 || bit_depth == 2 || bit_depth == 4 || bit_depth == 8 || bit_depth == 16);
            case ColorType::truecolor: return (bit_depth == 8 || bit_depth == 16);
            case ColorType::indexed: return (bit_depth == 1 || bit_depth == 2 || bit_depth == 4 || bit_depth == 8);
            case ColorType::greyscale_alpha: return (bit_depth == 8 || bit_depth == 16);
            case ColorType::truecolor_alpha: return (bit_depth == 8 || bit_depth == 16);
        }
        return false;
    };

    bool valid = true;

    valid &= valid_bit_depth();
    valid &= compression_method == CompressionMethod::deflate_inflate;
    valid &= filter_method == FilterMethod::adaptive;
    valid &= (interlace_method == InterlaceMethod::no || interlace_method == InterlaceMethod::adam7);

    return valid;
}

std::int32_t FileHeader::samples_per_pixel() const
{
    switch (color_type) {
        case ColorType::greyscale: return 1;
        case ColorType::truecolor: return 3;
        case ColorType::indexed: return 1;
        case ColorType::greyscale_alpha: return 2;
        case ColorType::truecolor_alpha: return 4;
    }

    return 0;
}

std::int32_t FileHeader::bits_per_pixel() const
{
    return samples_per_pixel() * bit_depth;
}

std::int32_t FileHeader::bytes_per_pixel() const
{
    return (bits_per_pixel() + 7) / 8;
}

ImageInfo FileHeader::image_info() const
{
    return ImageInfo{width, height, true, {}};
}

bool check_signature(const std::vector<std::uint8_t>& data)
{
    constexpr std::array<std::uint8_t, signature_length> signature = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

    if (data.size() < signature.size()) {
        return false;
    }

    for (size_t i = 0; i < signature.size(); ++i) {
        if (data[i] != signature[i]) {
            return false;
        }
    }

    return true;
}

#pragma endregion

#pragma region pass info

struct PassInfo
{
    struct Position
    {
        std::int32_t x;
        std::int32_t y;
    };

    struct Offset
    {
        std::int32_t x;
        std::int32_t y;
    };

    PassInfo(std::int32_t w, std::int32_t h, std::int32_t b, Position p, Offset o)
        : width(w)
        , height(h)
        , bytes_per_scanline(b)
        , position(p)
        , offset(o)
    {}

    const std::int32_t width;
    const std::int32_t height;
    const std::int32_t bytes_per_scanline;
    const Position position;
    const Offset offset;
};

std::vector<PassInfo> get_pass_info(const FileHeader& header)
{
    std::vector<PassInfo> info;

    switch (header.interlace_method) {
        case InterlaceMethod::adam7: {
            const std::array<std::int32_t, pass_count> widths = {(header.width + 7) / 8,
                                                                 (header.width + 3) / 8,
                                                                 (header.width + 3) / 4,
                                                                 (header.width + 1) / 4,
                                                                 (header.width + 1) / 2,
                                                                 (header.width + 0) / 2,
                                                                 (header.width + 0) / 1};

            const std::array<std::int32_t, pass_count> heights = {(header.height + 7) / 8,
                                                                  (header.height + 7) / 8,
                                                                  (header.height + 3) / 8,
                                                                  (header.height + 3) / 4,
                                                                  (header.height + 1) / 4,
                                                                  (header.height + 1) / 2,
                                                                  (header.height + 0) / 2};

            const std::array<PassInfo::Position, pass_count> positions =
            {PassInfo::Position{0, 0}, {4, 0}, {0, 4}, {2, 0}, {0, 2}, {1, 0}, {0, 1}};

            const std::array<PassInfo::Offset, pass_count> offsets =
            {PassInfo::Offset{8, 8}, {8, 8}, {4, 8}, {4, 4}, {2, 4}, {2, 2}, {1, 2}};

            for (size_t i = 0; i < pass_count; ++i) {
                if (widths[i] == 0 || heights[i] == 0) {
                    continue;
                }

                const std::int32_t bytes_per_scanline = (widths[i] * header.bits_per_pixel() + 7) / 8;
                info.push_back(PassInfo(widths[i], heights[i], bytes_per_scanline, positions[i], offsets[i]));
            }
        } break;
        case InterlaceMethod::no: {
            info.push_back(
            PassInfo(header.width, header.height, (header.width * header.bits_per_pixel() + 7) / 8, {0, 0}, {1, 1}));
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
        *x++ = static_cast<std::uint8_t>((static_cast<std::int32_t>(*a++) + *first++) & 0xFF);
    }
}

template <typename In, typename Out>
inline void reconstruct_up(In first, In last, In b, Out x)
{
    while (first != last) {
        *x++ = static_cast<std::uint8_t>((static_cast<std::int32_t>(*b++) + *first++) & 0xFF);
    }
}

template <typename In, typename Out>
inline void reconstruct_average(In first, In last, In a, In b, Out x)
{
    while (first != last) {
        *x++ = static_cast<std::uint8_t>((((static_cast<std::int32_t>(*a++) + *b++) >> 1) + *first++) & 0xFF);
    }
}

std::uint8_t paeth_predictor(std::int32_t a, std::int32_t b, std::int32_t c)
{
    const std::int32_t p  = a + b - c;
    const std::int32_t pa = abs(p - a);
    const std::int32_t pb = abs(p - b);
    const std::int32_t pc = abs(p - c);

    if (pa <= pb && pa <= pc) {
        return static_cast<std::uint8_t>(a);
    } else if (pb <= pc) {
        return static_cast<std::uint8_t>(b);
    } else {
        return static_cast<std::uint8_t>(c);
    }
}

template <typename In, typename Out>
inline void reconstruct_peath(In first, In last, In a, In b, In c, Out x)
{
    while (first != last) {
        *x++ = static_cast<std::uint8_t>((static_cast<std::int32_t>(paeth_predictor(*a++, *b++, *c++)) + *first++) &
                                         0xFF);
    }
}

enum class filter_type_t : std::uint8_t
{
    none    = 0,
    sub     = 1,
    up      = 2,
    average = 3,
    peath   = 4
};

std::tuple<std::vector<std::uint8_t>::iterator, std::vector<std::uint8_t>::iterator> reconstruct_pass(
std::vector<std::uint8_t>::iterator in,
std::vector<std::uint8_t>::iterator out,
const PassInfo& pass,
std::int32_t bytes_per_pixel)
{
    const std::int32_t bytes_in_row        = (pass.bytes_per_scanline + bytes_per_pixel);
    const size_t result_size               = static_cast<size_t>(bytes_in_row) * (static_cast<size_t>(pass.height) + 1);
    const std::ptrdiff_t second_row_offset = static_cast<std::ptrdiff_t>(bytes_in_row + bytes_per_pixel);

    std::vector<std::uint8_t> res(result_size, 0);

    auto res_a = next(res.begin(), bytes_in_row);
    auto res_b = next(res.begin(), bytes_per_pixel);
    auto res_c = res.begin();
    auto res_x = next(res.begin(), second_row_offset);

    for (std::int32_t h = 0; h < pass.height; ++h) {
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

    auto it = next(res.begin(), second_row_offset);
    for (std::int32_t h = 0; h < pass.height; ++h) {
        auto last = next(it, static_cast<ptrdiff_t>(pass.bytes_per_scanline));

        out = std::copy(it, last, out);

        advance(it, bytes_in_row);
    }

    return std::make_tuple(in, out);
}

std::vector<std::uint8_t> reconstruct(const FileHeader& header, std::vector<std::uint8_t>&& data)
{
    if (data.empty()) {
        return std::vector<std::uint8_t>();
    }

    std::vector<std::uint8_t> res(data.size(), 0);

    auto in  = data.begin();
    auto out = res.begin();
    for (const auto& pass : get_pass_info(header)) {
        std::tie(in, out) = reconstruct_pass(in, out, pass, header.bytes_per_pixel());
    }

    return res;
}

#pragma endregion

#pragma region unserialize

template <size_t BitDepth>
constexpr std::uint8_t sample(size_t input)
{
    static_assert(BitDepth < 8);
    constexpr size_t maxinput  = (1 << BitDepth) - 1;
    constexpr size_t maxoutput = (1 << 8) - 1;
    return static_cast<std::uint8_t>(input * maxoutput / maxinput);
}

template <size_t N, size_t Size = (1 << N)>
using Palette = std::array<Color, Size>;

template <size_t BitDepth>
constexpr Palette<BitDepth> greyscale_palette()
{
    static_assert(BitDepth < 8);
    Palette<BitDepth> res = {Color(0x000000FFU)};

    for (size_t input = 0; input < res.size(); input++) {
        const std::uint8_t c = sample<BitDepth>(input);
        res[input]           = Color(c, c, c, 0xFF);
    }

    return res;
}

template <size_t BitDepth>
Palette<BitDepth> read_palette(const Chunk chunk)
{
    static_assert(BitDepth <= 8);
    Palette<BitDepth> res = {Color(0x000000FFU)};

    if (chunk.type != Chunk::Type::PLTE || (chunk.data.size() % 3 != 0)) {
        return res;
    }

    for (size_t i = 0; i < chunk.data.size() / 3; ++i) {
        res[i].r = chunk.data[i * 3];
        res[i].g = chunk.data[i * 3 + 1];
        res[i].b = chunk.data[i * 3 + 2];
    }

    return res;
}

using SampleTuple = std::tuple<Color, std::vector<std::uint8_t>::iterator>;

template <ColorType CType, std::uint8_t BitDepth>
inline SampleTuple get_color(std::vector<std::uint8_t>::iterator in);

template <>
inline SampleTuple get_color<ColorType::greyscale, 8>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t c = *in++;
    return std::make_tuple(Color(c, c, c, 0xFF), in);
}

template <>
inline SampleTuple get_color<ColorType::greyscale, 16>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t c = *in++;
    in++;
    return std::make_tuple(Color(c, c, c, 0xFF), in);
}

template <>
inline SampleTuple get_color<ColorType::truecolor, 8>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t r = *in++;
    const std::uint8_t g = *in++;
    const std::uint8_t b = *in++;

    return std::make_tuple(Color(r, g, b, 0xFF), in);
}

template <>
inline SampleTuple get_color<ColorType::truecolor, 16>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t r = *in++;
    in++;
    const std::uint8_t g = *in++;
    in++;
    const std::uint8_t b = *in++;
    in++;

    return std::make_tuple(Color(r, g, b, 0xFF), in);
}

template <>
inline SampleTuple get_color<ColorType::greyscale_alpha, 8>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t c = *in++;
    const std::uint8_t a = *in++;
    return std::make_tuple(Color(c, c, c, a), in);
}

template <>
inline SampleTuple get_color<ColorType::greyscale_alpha, 16>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t c = *in++;
    in++;
    const std::uint8_t a = *in++;
    in++;
    return std::make_tuple(Color(c, c, c, a), in);
}

template <>
inline SampleTuple get_color<ColorType::truecolor_alpha, 8>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t r = *in++;
    const std::uint8_t g = *in++;
    const std::uint8_t b = *in++;
    const std::uint8_t a = *in++;

    return std::make_tuple(Color(r, g, b, a), in);
}

template <>
inline SampleTuple get_color<ColorType::truecolor_alpha, 16>(std::vector<std::uint8_t>::iterator in)
{
    const std::uint8_t r = *in++;
    in++;
    const std::uint8_t g = *in++;
    in++;
    const std::uint8_t b = *in++;
    in++;
    const std::uint8_t a = *in++;
    in++;

    return std::make_tuple(Color(r, g, b, a), in);
}

template <ColorType ColorType, std::uint8_t BitDepth>
inline std::vector<std::uint8_t>::iterator unserialize_pass(std::vector<std::uint8_t>::iterator in,
                                                            const PassInfo& pass,
                                                            const FileHeader& header,
                                                            std::vector<Color>& out)
{
    static_assert(BitDepth == 8 || BitDepth == 16);
    for (std::int32_t h = 0; h < pass.height; ++h) {
        std::uint32_t pos = static_cast<std::uint32_t>(
        (header.height - 1 - (pass.position.y + pass.offset.y * h)) * header.width + pass.position.x);
        for (std::int32_t w = 0; w < pass.width; ++w) {
            std::tie(out[pos], in) = get_color<ColorType, BitDepth>(in);
            pos += static_cast<std::uint32_t>(pass.offset.x);
        }
    }

    return in;
}

template <std::uint8_t BitDepth>
inline std::vector<std::uint8_t>::iterator unserialize_palette_pass(std::vector<std::uint8_t>::iterator in,
                                                                    const PassInfo& pass,
                                                                    const FileHeader& header,
                                                                    const Palette<BitDepth>& palette,
                                                                    std::vector<Color>& out)
{
    static_assert(BitDepth <= 8);
    constexpr size_t mask = (1 << BitDepth) - 1;

    for (std::int32_t h = 0; h < pass.height; ++h) {
        std::uint32_t pos = static_cast<std::uint32_t>(
        (header.height - 1 - (pass.position.y + pass.offset.y * h)) * header.width + pass.position.x);
        std::uint8_t byte = 0;
        for (std::int32_t w = 0, i = 0; w < pass.width; ++w, i = (i + BitDepth) % 8) {
            if (i == 0) {
                byte = *in++;
            }
            out[pos] = palette[(byte >> ((8 - BitDepth) - i)) & mask];
            pos += static_cast<std::uint32_t>(pass.offset.x);
        }
    }

    return in;
}

template <ColorType ColorType, std::uint8_t BitDepth>
inline std::vector<Color> unserialize_impl(const FileHeader& header, std::vector<std::uint8_t>&& data)
{
    static_assert(BitDepth == 8 || BitDepth == 16);

    const size_t result_size = static_cast<size_t>(header.width * header.height);

    std::vector<Color> res(result_size, Color(std::uint32_t(0x000000FF)));

    auto in = data.begin();
    for (const auto& pass : get_pass_info(header)) {
        in = unserialize_pass<ColorType, BitDepth>(in, pass, header, res);
    }

    return res;
}

template <std::uint8_t BitDepth>
inline std::vector<Color> unserialize_palette_impl(const FileHeader& header,
                                                   const Palette<BitDepth>& palette,
                                                   std::vector<std::uint8_t>&& data)
{
    static_assert(BitDepth <= 8);

    const size_t result_size = static_cast<size_t>(header.width * header.height);

    std::vector<Color> res(result_size, Color(std::uint32_t(0x000000FF)));

    auto in = data.begin();
    for (const auto& pass : get_pass_info(header)) {
        in = unserialize_palette_pass<BitDepth>(in, pass, header, palette, res);
    }

    return res;
}

inline std::vector<Color> unserialize_greyscale(const FileHeader& header, std::vector<std::uint8_t>&& data)
{
    if (data.empty()) {
        return std::vector<Color>();
    }

    switch (header.bit_depth) {
        case 1: return unserialize_palette_impl<1>(header, greyscale_palette<1>(), std::move(data));
        case 2: return unserialize_palette_impl<2>(header, greyscale_palette<2>(), std::move(data));
        case 4: return unserialize_palette_impl<4>(header, greyscale_palette<4>(), std::move(data));
        case 8: return unserialize_impl<ColorType::greyscale, 8>(header, std::move(data));
        case 16: return unserialize_impl<ColorType::greyscale, 16>(header, std::move(data));
    }

    return std::vector<Color>();
}

inline std::vector<Color> unserialize_truecolor(const FileHeader& header, std::vector<std::uint8_t>&& data)
{
    if (data.empty()) {
        return std::vector<Color>();
    }

    switch (header.bit_depth) {
        case 8: return unserialize_impl<ColorType::truecolor, 8>(header, std::move(data));
        case 16: return unserialize_impl<ColorType::truecolor, 16>(header, std::move(data));
    }

    return std::vector<Color>();
}

inline std::vector<Color> unserialize_indexed(const FileHeader& header,
                                              const Chunk& plte_chunk,
                                              std::vector<std::uint8_t>&& data)
{
    if (data.empty()) {
        return std::vector<Color>();
    }

    switch (header.bit_depth) {
        case 1: return unserialize_palette_impl<1>(header, read_palette<1>(plte_chunk), std::move(data));
        case 2: return unserialize_palette_impl<2>(header, read_palette<2>(plte_chunk), std::move(data));
        case 4: return unserialize_palette_impl<4>(header, read_palette<4>(plte_chunk), std::move(data));
        case 8: return unserialize_palette_impl<8>(header, read_palette<8>(plte_chunk), std::move(data));
    }

    return std::vector<Color>();
}

inline std::vector<Color> unserialize_greyscale_alpha(const FileHeader& header, std::vector<std::uint8_t>&& data)
{
    if (data.empty()) {
        return std::vector<Color>();
    }

    switch (header.bit_depth) {
        case 8: return unserialize_impl<ColorType::greyscale_alpha, 8>(header, std::move(data));
        case 16: return unserialize_impl<ColorType::greyscale_alpha, 16>(header, std::move(data));
    }

    return std::vector<Color>();
}

inline std::vector<Color> unserialize_truecolor_alpha(const FileHeader& header, std::vector<std::uint8_t>&& data)
{
    if (data.empty()) {
        return std::vector<Color>();
    }

    switch (header.bit_depth) {
        case 8: return unserialize_impl<ColorType::truecolor_alpha, 8>(header, std::move(data));
        case 16: return unserialize_impl<ColorType::truecolor_alpha, 16>(header, std::move(data));
    }

    return std::vector<Color>();
}

inline std::vector<Color> unserialize(const FileHeader& header,
                                      const Chunk& plte_chunk,
                                      std::vector<std::uint8_t>&& data)
{
    switch (header.color_type) {
        case ColorType::greyscale: return unserialize_greyscale(header, std::move(data));
        case ColorType::truecolor: return unserialize_truecolor(header, std::move(data));
        case ColorType::indexed: return unserialize_indexed(header, plte_chunk, std::move(data));
        case ColorType::greyscale_alpha: return unserialize_greyscale_alpha(header, std::move(data));
        case ColorType::truecolor_alpha: return unserialize_truecolor_alpha(header, std::move(data));
    }

    return std::vector<Color>();
}

#pragma endregion

float decode_gamma(const Chunk& chunk)
{
    if (chunk.type != Chunk::Type::gAMA) {
        return 1.0f;
    }

    const float gamma = static_cast<float>(
    utils::big_endian_value<std::uint32_t>(chunk.data.begin(), chunk.data.end()));

    return (gamma / 100000.0f);
}

} // namespace

namespace framework::graphics::details::image::png
{
LoadResult load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return LoadResult(error::open_file_error);
    }

    auto signature = read_bytes(file, signature_length);
    if (!check_signature(signature)) {
        return LoadResult(error::invalid_file_signature);
    }

    FileHeader header = FileHeader::read(file);
    if (!header.valid()) {
        return LoadResult(error::read_header_error);
    }

    Chunk plte_chunk;
    float gamma = default_gamma;

    std::vector<std::uint8_t> data;
    for (Chunk chunk = Chunk::read(file); file && chunk.type != Chunk::Type::IEND; chunk = Chunk::read(file)) {
        if (!chunk.valid() && chunk.is_critical()) {
            return LoadResult(error::read_data_error);
        }

        switch (chunk.type) {
            case Chunk::Type::IHDR: break; // error
            case Chunk::Type::PLTE: {
                plte_chunk = chunk;
            } break;
            case Chunk::Type::IDAT: {
                data.insert(end(data), begin(chunk.data), end(chunk.data));
            } break;
            case Chunk::Type::IEND: break; // end
            case Chunk::Type::cHRM: break; /// ???
            case Chunk::Type::gAMA: gamma = decode_gamma(chunk); break;
            case Chunk::Type::iCCP: break;
            case Chunk::Type::sBIT: break; // ignore
            case Chunk::Type::sRGB: break;
            case Chunk::Type::bKGD: break; // ignore
            case Chunk::Type::hIST: break; // ???
            case Chunk::Type::tRNS: break;
            case Chunk::Type::pHYs: break;      // ignore
            case Chunk::Type::sPLT: break;      // ignore
            case Chunk::Type::tIME: break;      // ignore
            case Chunk::Type::iTXt: break;      // ignore
            case Chunk::Type::tEXt: break;      // ignore
            case Chunk::Type::zTXt: break;      // ignore
            case Chunk::Type::undefined: break; // error
        }
    }

    if (data.empty()) {
        return LoadResult(error::read_data_error);
    }

    if (header.color_type == ColorType::indexed && plte_chunk.data.empty()) {
        return LoadResult(error::read_data_error);
    }

    std::vector<std::uint8_t> recontructed = reconstruct(header, zlib::inflate(data));
    std::vector<Color> image_data          = unserialize(header, plte_chunk, std::move(recontructed));

    auto info  = header.image_info();
    info.gamma = gamma;
    info.data  = std::move(image_data);
    return LoadResult(info);
}

bool is_png(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    return check_signature(read_bytes(file, signature_length));
}

} // namespace framework::graphics::details::image::png
