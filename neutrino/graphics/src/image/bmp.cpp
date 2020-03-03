/// @file
/// @brief Bmp image implementation.
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
#include <cmath>
#include <fstream>
#include <memory>
#include <vector>

#include <common/types.hpp>
#include <common/utils.hpp>
#include <graphics/color_type.hpp>
#include <graphics/src/image/bmp.hpp>

namespace
{
using namespace framework;
using graphics::color_t;
using graphics::details::image::image_info_t;

//  | signature | file size | reserved | reserved | pixel array offset |
//  |------------------------------------------------------------------|
//  | 2         | 4         | 2        | 2        | 4                  |
struct file_header_t
{
    uint16 signature          = 0;
    uint32 file_size          = 0;
    uint32 pixel_array_offset = 0;

    bool valid() const;

    static file_header_t read(std::ifstream& in);

    static constexpr uint32 size = 14;
};

struct info_header_t
{
    enum class type_t
    {
        undefined             = 0,
        bitmapcoreheader      = 12,
        os22xbitmapheader     = 16,
        bitmapinfoheader      = 40,
        bitmapv2infoheader    = 52,
        bitmapv3infoheader    = 56,
        os22xbitmapheaderfull = 64,
        bitmapv4header        = 108,
        bitmapv5header        = 124
    };

    enum class compression_t : uint32
    {
        bi_rgb            = 0, // none
        bi_rle8           = 1, // RLE 8-bit/pixel
        bi_rle4           = 2, // RLE 4-bit/pixel
        bi_bitfields      = 3, // OS22XBITMAPHEADER: Huffman 1D
        bi_jpeg           = 4, //
        bi_png            = 5, //
        bi_alphabitfields = 6, // RGBA bit field masks
    };

    enum class color_space_type_t : uint32
    {
        lcs_calibrated_rgb      = 0,          // Use endpoints
        lcs_srgb                = 0x73524742, // sRGB
        lcs_windows_color_space = 0x57696E20, // System color space (sRBG by default)
        profile_linked          = 0x4C494E4B, // Profile in another file
        profile_embedded        = 0x4D424544, // Profile in this file
    };

    struct ciexyz
    {
        uint32 x = 0;
        uint32 y = 0;
        uint32 z = 0;
    };

    struct ciexyztriple
    {
        ciexyz red;
        ciexyz green;
        ciexyz blue;
    };

    using color_table_t = std::vector<color_t>;

    // BITMAPCOREHEADER
    uint32 size           = 0;
    int32 width           = 0;
    int32 height          = 0;
    uint16 planes         = 0;
    uint16 bits_per_pixel = 0;

    // BITMAPINFOHEADER
    compression_t compression = compression_t::bi_rgb;
    uint32 image_size         = 0;
    int32 x_ppm               = 0;
    int32 y_ppm               = 0;
    uint32 colors_in_table    = 0;
    uint32 important_colors   = 0;

    // BITMAPV2INFOHEADER
    uint32 red_chanel_bitmask   = 0; //  +-
    uint32 green_chanel_bitmask = 0; //  | matter only if bits_per_pixel == 16 or 32
    uint32 blue_chanel_bitmask  = 0; //  |
                                     //  |
    // BITMAPV3INFOHEADER            //  |
    uint32 alpha_chanel_bitmask = 0; //  +-

    // BITMAPV4HEADER
    color_space_type_t color_space_type = color_space_type_t::lcs_calibrated_rgb;
    ciexyztriple endpoints; //  +-
    uint32 gamma_red   = 0; //  | matter only if color_space_type == lcs_calibrated_rgb
    uint32 gamma_green = 0; //  |
    uint32 gamma_blue  = 0; //  +-

    // BITMAPV4HEADER
    uint32 intent               = 0;
    uint32 color_profile_offset = 0;
    uint32 color_profile_size   = 0;
    uint32 reserved             = 0;

    color_table_t color_table;

    bool valid() const;

    type_t type() const;
    bool bottom_up() const;
    std::tuple<uint32, uint32, uint32, uint32> chanel_masks() const;

    static info_header_t read(std::ifstream& in);
    static color_table_t read_color_table(std::ifstream& in, const info_header_t& info);
};

inline bool check_signature(const file_header_t& h) noexcept
{
    switch (h.signature) {
        case 0x424D: return true; // BM
        case 0x4241: return true; // BA
        case 0x4349: return true; // CI
        case 0x4350: return true; // CP
        case 0x4943: return true; // IC
        case 0x5054: return true; // PT
        default: break;
    }

    return false;
}

bool file_header_t::valid() const
{
    constexpr usize max_file_size = 1024 * 1024 * 1024;
    return check_signature(*this) && file_size < max_file_size;
}

file_header_t file_header_t::read(std::ifstream& in)
{
    char buffer[file_header_t::size];

    in.read(buffer, file_header_t::size);

    file_header_t h;
    h.signature          = utils::big_endian_value<uint16>(buffer);
    h.file_size          = utils::little_endian_value<uint32>(buffer + 2);
    h.pixel_array_offset = utils::little_endian_value<uint32>(buffer + 10);

    return h;
}

inline bool check_size(const info_header_t& h) noexcept
{
    constexpr int32 max_size      = 30000;
    constexpr int32 max_data_size = 1024 * 1024 * 1024;
    constexpr int32 max_ppm       = 10000;
    const int32 abs_height        = std::abs(h.height);

    return h.width > 0 && abs_height > 0 && h.width <= max_size && abs_height <= max_size &&
           h.image_size < max_data_size && h.width * abs_height * static_cast<int32>(sizeof(color_t)) < max_data_size &&
           h.x_ppm < max_ppm && h.y_ppm < max_ppm;
}

inline bool check_compression(const info_header_t& h) noexcept
{
    if (h.type() == info_header_t::type_t::bitmapcoreheader) {
        return true;
    }

    switch (h.compression) {
        case info_header_t::compression_t::bi_rgb: return h.bits_per_pixel != 0;
        case info_header_t::compression_t::bi_rle8: return h.bits_per_pixel == 8 && h.height > 0;
        case info_header_t::compression_t::bi_rle4: return h.bits_per_pixel == 4 && h.height > 0;
        case info_header_t::compression_t::bi_bitfields: return h.bits_per_pixel == 16 || h.bits_per_pixel == 32;
        case info_header_t::compression_t::bi_jpeg: return false; // unsupported
        case info_header_t::compression_t::bi_png: return false;  // unsupported
        case info_header_t::compression_t::bi_alphabitfields: return h.bits_per_pixel == 16 || h.bits_per_pixel == 32;
    }

    return false;
}

inline bool check_color_space_type(const info_header_t& h) noexcept
{
    if (h.size < static_cast<uint32>(info_header_t::type_t::bitmapv4header)) {
        return true;
    }

    switch (h.color_space_type) {
        case info_header_t::color_space_type_t::lcs_calibrated_rgb: return true;
        case info_header_t::color_space_type_t::lcs_srgb: return true;
        case info_header_t::color_space_type_t::lcs_windows_color_space: return true;
        case info_header_t::color_space_type_t::profile_linked: return false;   // unsupported
        case info_header_t::color_space_type_t::profile_embedded: return false; // unsupported
    }

    return false;
}

inline bool check_bits_per_pixel(const info_header_t& h) noexcept
{
    switch (h.bits_per_pixel) {
        case 1:
        case 2:
        case 4:
        case 8:
        case 16:
        case 24:
        case 32: return true;
        default: break;
    }

    return false;
}

bool info_header_t::valid() const
{
    bool result = type() != info_header_t::type_t::undefined;
    result      = result && planes == 1;
    result      = result && check_size(*this);
    result      = result && check_compression(*this);
    result      = result && check_color_space_type(*this);
    result      = result && check_bits_per_pixel(*this);

    return result;
}

inline info_header_t::type_t info_header_t::type() const
{
    switch (static_cast<type_t>(size)) {
        case type_t::undefined: return type_t::undefined;

        case type_t::bitmapcoreheader:
        case type_t::os22xbitmapheader:
        case type_t::bitmapinfoheader:
        case type_t::bitmapv2infoheader:
        case type_t::bitmapv3infoheader:
        case type_t::os22xbitmapheaderfull:
        case type_t::bitmapv4header:
        case type_t::bitmapv5header: return static_cast<type_t>(size);
    }

    return type_t::undefined;
}

inline bool info_header_t::bottom_up() const
{
    return type() == info_header_t::type_t::bitmapcoreheader ? true : height > 0;
}

inline std::tuple<uint32, uint32, uint32, uint32> info_header_t::chanel_masks() const
{
    const uint32 alpha_mask = alpha_chanel_bitmask ? alpha_chanel_bitmask : 0;

    if (red_chanel_bitmask || green_chanel_bitmask || blue_chanel_bitmask) {
        return std::make_tuple(red_chanel_bitmask, green_chanel_bitmask, blue_chanel_bitmask, alpha_mask);
    } else if (bits_per_pixel == 16) {
        return std::make_tuple(0x7C00, 0x03E0, 0x001F, alpha_mask);
    } else if (bits_per_pixel == 32) {
        return std::make_tuple(0xFF0000, 0x00FF00, 0x0000FF, alpha_mask);
    }

    return std::make_tuple(0, 0, 0, 0);
}

info_header_t info_header_t::read(std::ifstream& in)
{
    char size_buffer[4];
    in.read(size_buffer, sizeof(size_buffer));

    info_header_t h;
    h.size = utils::little_endian_value<uint32>(size_buffer);

    std::unique_ptr<char[]> buffer(new char[h.size - sizeof(size_buffer)]);
    in.read(buffer.get(), h.size - sizeof(size_buffer));

    if (h.type() == type_t::bitmapcoreheader) {
        h.width          = utils::little_endian_value<uint16>(buffer.get());
        h.height         = utils::little_endian_value<uint16>(buffer.get() + 2);
        h.planes         = utils::little_endian_value<uint16>(buffer.get() + 4);
        h.bits_per_pixel = utils::little_endian_value<uint16>(buffer.get() + 6);
    } else {
        h.width          = utils::little_endian_value<int32>(buffer.get());
        h.height         = utils::little_endian_value<int32>(buffer.get() + 4);
        h.planes         = utils::little_endian_value<uint16>(buffer.get() + 8);
        h.bits_per_pixel = utils::little_endian_value<uint16>(buffer.get() + 10);
    }

    if (h.size >= static_cast<uint32>(info_header_t::type_t::bitmapinfoheader)) {
        h.compression      = utils::little_endian_value<compression_t>(buffer.get() + 12);
        h.image_size       = utils::little_endian_value<uint32>(buffer.get() + 16);
        h.x_ppm            = utils::little_endian_value<int32>(buffer.get() + 20);
        h.y_ppm            = utils::little_endian_value<int32>(buffer.get() + 24);
        h.colors_in_table  = utils::little_endian_value<uint32>(buffer.get() + 28);
        h.important_colors = utils::little_endian_value<uint32>(buffer.get() + 32);
    }

    if (h.type() == info_header_t::type_t::bitmapinfoheader &&
        (h.compression == compression_t::bi_bitfields || h.compression == compression_t::bi_alphabitfields)) {
        char mask_buffer[3 * sizeof(uint32)] = {};
        in.read(mask_buffer, sizeof(mask_buffer));

        h.red_chanel_bitmask   = utils::little_endian_value<uint32>(mask_buffer);
        h.green_chanel_bitmask = utils::little_endian_value<uint32>(mask_buffer + 4);
        h.blue_chanel_bitmask  = utils::little_endian_value<uint32>(mask_buffer + 8);
    }

    if (h.size == static_cast<uint32>(info_header_t::type_t::bitmapinfoheader) &&
        h.compression == compression_t::bi_alphabitfields) {
        char mask_buffer[sizeof(uint32)] = {};
        in.read(mask_buffer, sizeof(mask_buffer));

        h.alpha_chanel_bitmask = utils::little_endian_value<uint32>(mask_buffer);
    }

    if (h.size >= static_cast<uint32>(info_header_t::type_t::bitmapv2infoheader)) {
        h.red_chanel_bitmask   = utils::little_endian_value<uint32>(buffer.get() + 36);
        h.green_chanel_bitmask = utils::little_endian_value<uint32>(buffer.get() + 40);
        h.blue_chanel_bitmask  = utils::little_endian_value<uint32>(buffer.get() + 44);
    }

    if (h.size >= static_cast<uint32>(info_header_t::type_t::bitmapv3infoheader)) {
        h.alpha_chanel_bitmask = utils::little_endian_value<uint32>(buffer.get() + 48);
    }

    if (h.size >= static_cast<uint32>(info_header_t::type_t::bitmapv4header)) {
        h.color_space_type = utils::little_endian_value<color_space_type_t>(buffer.get() + 52);

        h.endpoints.red.x   = utils::little_endian_value<uint32>(buffer.get() + 56);
        h.endpoints.red.y   = utils::little_endian_value<uint32>(buffer.get() + 60);
        h.endpoints.red.z   = utils::little_endian_value<uint32>(buffer.get() + 64);
        h.endpoints.green.x = utils::little_endian_value<uint32>(buffer.get() + 68);
        h.endpoints.green.y = utils::little_endian_value<uint32>(buffer.get() + 72);
        h.endpoints.green.z = utils::little_endian_value<uint32>(buffer.get() + 76);
        h.endpoints.blue.x  = utils::little_endian_value<uint32>(buffer.get() + 80);
        h.endpoints.blue.y  = utils::little_endian_value<uint32>(buffer.get() + 84);
        h.endpoints.blue.z  = utils::little_endian_value<uint32>(buffer.get() + 88);

        h.gamma_red   = utils::little_endian_value<uint32>(buffer.get() + 92);
        h.gamma_green = utils::little_endian_value<uint32>(buffer.get() + 96);
        h.gamma_blue  = utils::little_endian_value<uint32>(buffer.get() + 100);
    }

    if (h.size >= static_cast<uint32>(info_header_t::type_t::bitmapv5header)) {
        h.intent               = utils::little_endian_value<uint32>(buffer.get() + 104);
        h.color_profile_offset = utils::little_endian_value<uint32>(buffer.get() + 108);
        h.color_profile_size   = utils::little_endian_value<uint32>(buffer.get() + 112);
        h.reserved             = utils::little_endian_value<uint32>(buffer.get() + 116);
    }

    if (h.bits_per_pixel <= 8) {
        h.color_table = read_color_table(in, h);
    }

    return h;
}

info_header_t::color_table_t info_header_t::read_color_table(std::ifstream& in, const info_header_t& info)
{
    const uint32 colors_count = [&info]() {
        if (info.bits_per_pixel >= 1 && info.bits_per_pixel <= 8 &&
            (info.type() == type_t::bitmapcoreheader || info.colors_in_table == 0)) {
            return static_cast<uint32>(std::pow(2, info.bits_per_pixel));
        }

        return info.colors_in_table;
    }();

    const uint32 cell_size = [&info]() -> uint32 {
        switch (info.type()) {
            case type_t::undefined: return 0;
            case type_t::bitmapcoreheader: return 3;
            case type_t::os22xbitmapheader:
            case type_t::bitmapinfoheader:
            case type_t::bitmapv2infoheader:
            case type_t::bitmapv3infoheader:
            case type_t::os22xbitmapheaderfull:
            case type_t::bitmapv4header:
            case type_t::bitmapv5header: return 4;
        }

        return 0;
    }();

    if (colors_count == 0 || cell_size == 0) {
        return color_table_t();
    }

    std::unique_ptr<char[]> buffer(new char[colors_count * cell_size]);
    in.read(buffer.get(), colors_count * cell_size);

    if (!in) {
        return color_table_t();
    }

    color_table_t table(colors_count);
    for (uint32 i = 0; i < colors_count; ++i) {
        const uint32 offset = i * cell_size;

        table[i].r = static_cast<uint8>(buffer[offset + 2]);
        table[i].g = static_cast<uint8>(buffer[offset + 1]);
        table[i].b = static_cast<uint8>(buffer[offset + 0]);
        table[i].a = 255;
    }

    return table;
}

inline image_info_t make_image_info(const info_header_t& h) noexcept
{
    return image_info_t{h.width, std::abs(h.height), graphics::details::image::default_gamma};
}

inline uint32 get_offset(uint32 value)
{
    uint32 count = 0;
    while ((value & 1) == 0) {
        count++;
        value >>= 1;
    }

    return count;
}

inline uint8 masked_value(uint32 pixel, uint32 mask, uint32 offset)
{
    const uint32 value = (pixel & mask) >> offset;
    const uint32 scale = mask >> offset;
    return scale ? static_cast<uint8>((static_cast<float>(value) / static_cast<float>(scale)) * 255) : 0;
}

std::vector<color_t>::iterator process_row_1bpp(std::vector<uint8>::iterator in,
                                                std::vector<color_t>::iterator out,
                                                const info_header_t& info)
{
    for (int32 x = 0; x < info.width; ++in) {
        for (int32 bit = 7; bit >= 0 && x < info.width; --bit, ++x) {
            const uint32 color_index = (*in & (1 << bit)) ? 1 : 0;

            *out++ = info.color_table[color_index];
        }
    }

    return out;
}

std::vector<color_t>::iterator process_row_2bpp(std::vector<uint8>::iterator in,
                                                std::vector<color_t>::iterator out,
                                                const info_header_t& info)
{
    const auto end = next(out, info.width);

    int32 offset = 6;
    while (out != end) {
        *out++ = info.color_table[(*in >> offset) & 0x03];

        if (offset == 0) {
            offset = 6;
            in++;
        } else {
            offset -= 2;
        }
    }

    return out;
}

std::vector<color_t>::iterator process_row_4bpp(std::vector<uint8>::iterator in,
                                                std::vector<color_t>::iterator out,
                                                const info_header_t& info)
{
    for (int32 x = 0, offset = 4; x < info.width; ++x, offset = ((offset + 4) % 8)) {
        *out++ = info.color_table[(*in >> offset) & 0x0F];
        if (offset == 0) {
            in++;
        }
    }
    return out;
}

std::vector<color_t>::iterator process_row_8bpp(std::vector<uint8>::iterator in,
                                                std::vector<color_t>::iterator out,
                                                const info_header_t& info)
{
    for (int32 x = 0; x < info.width; ++x) {
        *out++ = info.color_table[*in++];
    }
    return out;
}

std::vector<color_t>::iterator process_row_16bpp(std::vector<uint8>::iterator in,
                                                 std::vector<color_t>::iterator out,
                                                 const info_header_t& info)
{
    const auto [red_mask, green_mask, blue_mask, alpha_mask] = info.chanel_masks();

    const uint32 red_offset   = (red_mask ? get_offset(red_mask) : 0);
    const uint32 green_offset = (green_mask ? get_offset(green_mask) : 0);
    const uint32 blue_offset  = (blue_mask ? get_offset(blue_mask) : 0);
    const uint32 alpha_offset = (alpha_mask ? get_offset(alpha_mask) : 0);

    for (int32 x = 0; x < info.width; ++x) {
        uint32 pixel = *in++;
        pixel += static_cast<uint32>(*in++ << 8);

        const color_t color(masked_value(pixel, red_mask, red_offset),
                            masked_value(pixel, green_mask, green_offset),
                            masked_value(pixel, blue_mask, blue_offset),
                            (alpha_mask ? masked_value(pixel, alpha_mask, alpha_offset) : 255));
        *out++ = color;
    }

    return out;
}

std::vector<color_t>::iterator process_row_24bpp(std::vector<uint8>::iterator in,
                                                 std::vector<color_t>::iterator out,
                                                 const info_header_t& info)
{
    for (int32 x = 0; x < info.width; ++x) {
        const color_t color(*in++, *in++, *in++, 255U);
        *out++ = color;
    }

    return out;
}

std::vector<color_t>::iterator process_row_32bpp(std::vector<uint8>::iterator in,
                                                 std::vector<color_t>::iterator out,
                                                 const info_header_t& info)
{
    const auto [red_mask, green_mask, blue_mask, alpha_mask] = info.chanel_masks();
    const uint32 red_offset                                  = (red_mask ? get_offset(red_mask) : 0);
    const uint32 green_offset                                = (green_mask ? get_offset(green_mask) : 0);
    const uint32 blue_offset                                 = (blue_mask ? get_offset(blue_mask) : 0);
    const uint32 alpha_offset                                = (alpha_mask ? get_offset(alpha_mask) : 0);

    for (int32 x = 0; x < info.width; ++x) {
        uint32 pixel = *in++;
        pixel += static_cast<uint32>(*in++ << 8);
        pixel += static_cast<uint32>(*in++ << 16);
        pixel += static_cast<uint32>(*in++ << 24);

        const color_t color(masked_value(pixel, red_mask, red_offset),
                            masked_value(pixel, green_mask, green_offset),
                            masked_value(pixel, blue_mask, blue_offset),
                            (alpha_mask ? masked_value(pixel, alpha_mask, alpha_offset) : 255));
        *out++ = color;
    }

    return out;
}

std::vector<color_t>::iterator process_row(std::vector<uint8>::iterator in,
                                           std::vector<color_t>::iterator out,
                                           const info_header_t& info)
{
    switch (info.bits_per_pixel) {
        case 1: return process_row_1bpp(in, out, info);
        case 2: return process_row_2bpp(in, out, info);
        case 4: return process_row_4bpp(in, out, info);
        case 8: return process_row_8bpp(in, out, info);
        case 16: return process_row_16bpp(in, out, info);
        case 24: return process_row_24bpp(in, out, info);
        case 32: return process_row_32bpp(in, out, info);
        default: break;
    }

    return out;
}

std::vector<color_t> read_data_raw(std::ifstream& in, const info_header_t& info)
{
    const int32 height = std::abs(info.height);
    std::vector<color_t> image_data(static_cast<usize>(info.width * height));

    const uint32 row_size = static_cast<uint32>(((info.bits_per_pixel * info.width + 31) / 32) * 4);
    std::vector<uint8> buffer(row_size);

    auto out = begin(image_data);
    for (int32 y = 0; y < height && in; ++y) {
        if (in.read(reinterpret_cast<char*>(buffer.data()), row_size)) {
            out = process_row(buffer.begin(), out, info);
        }
    }

    return image_data;
}

inline std::vector<color_t>::iterator fill_with_color_4(std::vector<color_t>::iterator out,
                                                        const info_header_t::color_table_t& color_table,
                                                        const std::vector<uint8>::iterator it,
                                                        int32 count)
{
    for (int32 c = 0, offset = 4; c < count; ++c) {
        const usize color_index = static_cast<usize>((*it >> offset) & 0x0F);
        *out++                  = color_index < color_table.size() ? color_table[color_index] : color_t(0x000000FFU);
        offset                  = (offset == 0 ? 4 : 0);
    }
    return out;
}

inline std::vector<color_t>::iterator fill_with_color_8(std::vector<color_t>::iterator out,
                                                        const info_header_t::color_table_t& color_table,
                                                        const std::vector<uint8>::iterator it,
                                                        int32 count)
{
    const usize color_index = static_cast<usize>(*it);
    const color_t color     = color_index < color_table.size() ? color_table[color_index] : color_t(0x000000FFU);
    for (int32 c = 0; c < count; ++c) {
        *out++ = color;
    }
    return out;
}

inline std::vector<color_t>::iterator fill_from_buffer_4(std::vector<color_t>::iterator out,
                                                         const info_header_t::color_table_t& color_table,
                                                         std::vector<uint8>::iterator it,
                                                         int32 count)
{
    const int32 colors_in_byte = 2;
    while (count > 0) {
        out = fill_with_color_4(out, color_table, it, (count >= colors_in_byte ? colors_in_byte : 1));
        count -= colors_in_byte;
        it++;
    }
    return out;
}

inline std::vector<color_t>::iterator fill_from_buffer_8(std::vector<color_t>::iterator out,
                                                         const info_header_t::color_table_t& color_table,
                                                         std::vector<uint8>::iterator it,
                                                         int32 count)
{
    while (count-- > 0) {
        const usize color_index = static_cast<usize>(*it++);
        *out++                  = color_index < color_table.size() ? color_table[color_index] : color_t(0x000000FFU);
    }
    return out;
}

std::vector<color_t> read_data_rle(std::ifstream& input, const info_header_t& info)
{
    const int32 height     = std::abs(info.height);
    const int32 image_size = info.width * height;
    std::vector<color_t> image_data(static_cast<usize>(image_size));

    std::vector<uint8> buffer(info.image_size);
    input.read(reinterpret_cast<char*>(buffer.data()), info.image_size);

    auto in  = begin(buffer);
    auto out = begin(image_data);

    while (in != end(buffer) && out != end(image_data)) {
        if (*in == 0x00) {
            ++in;
            switch (*in) {
                case 0x00: {
                    const int32 d = static_cast<int32>(distance(image_data.begin(), out)) % info.width;
                    if (d != 0) {
                        advance(out, info.width - d);
                    }
                    in++;
                } break;
                case 0x01: in = end(buffer); break;
                case 0x02: {
                    in++;

                    const int32 w = *in++;
                    const int32 h = *in++;

                    advance(out, h * info.width + w);
                } break;
                default: {
                    const int32 count = *in++;

                    if (next(out, count) > end(image_data)) {
                        out = end(image_data);
                        break;
                    }

                    if (info.bits_per_pixel == 4) {
                        out = fill_from_buffer_4(out, info.color_table, in, count);
                        advance(in, ((count + 3) / 4) * 2);
                    } else {
                        out = fill_from_buffer_8(out, info.color_table, in, count);
                        advance(in, ((count + 1) / 2) * 2);
                    }

                } break;
            }
        } else {
            const int32 count = *in++;

            if (next(out, count) > end(image_data)) {
                out = end(image_data);
                break;
            }

            if (info.bits_per_pixel == 4) {
                out = fill_with_color_4(out, info.color_table, in, count);
            } else {
                out = fill_with_color_8(out, info.color_table, in, count);
            }

            in++;
        }
    }

    return image_data;
}

std::vector<color_t> read_data(std::ifstream& in, const info_header_t& info)
{
    switch (info.compression) {
        case info_header_t::compression_t::bi_rle4:
        case info_header_t::compression_t::bi_rle8: return read_data_rle(in, info);
        case info_header_t::compression_t::bi_rgb:
        case info_header_t::compression_t::bi_bitfields:
        case info_header_t::compression_t::bi_alphabitfields: return read_data_raw(in, info);
        case info_header_t::compression_t::bi_jpeg:
        case info_header_t::compression_t::bi_png: return std::vector<color_t>();
    }
    return std::vector<color_t>();
}

std::vector<color_t> flip_vertically(const info_header_t& info, const std::vector<color_t>& data)
{
    std::vector<color_t> tmp(data.size());

    auto from = data.begin();
    auto to   = std::prev(tmp.end(), info.width);

    for (int32 y = 0; y < std::abs(info.height); ++y) {
        auto next_from = std::next(from, info.width);

        std::copy(from, next_from, to);

        from = next_from;
        to   = std::prev(to, info.width);
    }

    return tmp;
}

} // namespace

namespace framework::graphics::details::image::bmp
{
load_result_t load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return load_result_t();
    }

    file_header_t file_header = file_header_t::read(file);
    if (!file_header.valid()) {
        return load_result_t();
    }

    info_header_t info = info_header_t::read(file);
    if (!info.valid()) {
        return load_result_t();
    }

    file.seekg(file_header.pixel_array_offset, std::ios::beg);
    if (!file) {
        return load_result_t();
    }

    std::vector<color_t> data = read_data(file, info);
    if (data.empty()) {
        return load_result_t();
    }

    if (!info.bottom_up()) {
        data = flip_vertically(info, data);
    }

    return std::make_optional(std::make_tuple(make_image_info(info), std::move(data)));
}

bool is_bmp(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return false;
    }

    file_header_t header = file_header_t::read(file);
    return header.valid();
}

} // namespace framework::graphics::details::image::bmp
