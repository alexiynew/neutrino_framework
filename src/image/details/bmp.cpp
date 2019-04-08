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
#include <image/details/bmp.hpp>

namespace
{
using framework::int16;
using framework::int32;
using framework::uint16;
using framework::uint32;
using framework::uint8;

//  | signature | file size | reserved | reserved | pixel array offset |
//  |------------------------------------------------------------------|
//  | 2         | 4         | 2        | 2        | 4                  |
struct file_header
{
    uint16 signature          = 0;
    uint32 file_size          = 0;
    uint32 pixel_array_offset = 0;

    static file_header read(std::ifstream& in);

    static constexpr uint32 size = 14;
};

// correspond to BITMAPV3INFOHEADER
struct info_header
{
    enum class type_t
    {
        undefined          = 0,
        bitmapcoreheader   = 12,
        bitmapinfoheader   = 40,
        bitmapv2infoheader = 52,
        bitmapv3infoheader = 56,
        bitmapv4header     = 108,
        bitmapv5header     = 124
    };

    enum class compression_t
    {
        bi_rgb            = 0, // none
        bi_rle8           = 1, // RLE 8-bit/pixel
        bi_rle4           = 2, // RLE 4-bit/pixel
        bi_bitfields      = 3, // OS22XBITMAPHEADER: Huffman 1D
        bi_jpeg           = 4, //
        bi_png            = 5, //
        bi_alphabitfields = 6, // RGBA bit field masks
    };

    // BITMAPCOREHEADER
    uint32 size           = 0;
    int32 width           = 0;
    int32 height          = 0;
    uint16 planes         = 0;
    uint16 bits_per_pixel = 0;

    // BITMAPINFOHEADER
    compression_t compresion = compression_t::bi_rgb;
    uint32 image_size        = 0;
    int32 x_ppm              = 0;
    int32 y_ppm              = 0;
    uint32 colors_in_table   = 0;
    uint32 important_colors  = 0;

    // BITMAPV2INFOHEADER
    uint32 red_chanel_bitmask   = 0;
    uint32 green_chanel_bitmask = 0;
    uint32 blue_chanel_bitmask  = 0;

    // BITMAPV3INFOHEADER
    uint32 alpha_chanel_bitmask = 0;

    type_t type() const;

    static info_header read(std::ifstream& in);
};

using color_table = std::vector<uint32>;
using pixel_data  = std::vector<uint8>;

file_header file_header::read(std::ifstream& in)
{
    char buffer[file_header::size];

    in.read(buffer, file_header::size);

    file_header h;
    h.signature          = (buffer[0] << 8) + buffer[1];
    h.file_size          = *(reinterpret_cast<uint32*>(buffer + 2));
    h.pixel_array_offset = *(reinterpret_cast<uint32*>(buffer + 2 + 4 + 4));

    return h;
}

info_header::type_t info_header::type() const
{
    return static_cast<type_t>(size);
}

info_header info_header::read(std::ifstream& in)
{
    char size_buffer[4];
    in.read(size_buffer, sizeof(size_buffer));

    info_header h;
    h.size = *(reinterpret_cast<uint32*>(size_buffer));

    std::unique_ptr<char[]> buffer(new char[h.size]);
    in.read(buffer.get(), h.size);

    if (h.type() == type_t::bitmapcoreheader) {
        h.width          = *(reinterpret_cast<uint16*>(buffer.get()));
        h.height         = *(reinterpret_cast<uint16*>(buffer.get() + 2));
        h.planes         = *(reinterpret_cast<uint16*>(buffer.get() + 4));
        h.bits_per_pixel = *(reinterpret_cast<uint16*>(buffer.get() + 6));
    } else {
        h.width          = *(reinterpret_cast<int32*>(buffer.get()));
        h.height         = *(reinterpret_cast<int32*>(buffer.get() + 4));
        h.planes         = *(reinterpret_cast<uint16*>(buffer.get() + 8));
        h.bits_per_pixel = *(reinterpret_cast<uint16*>(buffer.get() + 10));
    }

    if (h.size >= static_cast<uint32>(info_header::type_t::bitmapinfoheader)) {
        h.compresion       = static_cast<compression_t>(*(reinterpret_cast<uint32*>(buffer.get() + 12)));
        h.image_size       = *(reinterpret_cast<uint32*>(buffer.get() + 16));
        h.x_ppm            = *(reinterpret_cast<int32*>(buffer.get() + 20));
        h.y_ppm            = *(reinterpret_cast<int32*>(buffer.get() + 24));
        h.colors_in_table  = *(reinterpret_cast<uint32*>(buffer.get() + 28));
        h.important_colors = *(reinterpret_cast<uint32*>(buffer.get() + 32));
    }

    if (h.size >= static_cast<uint32>(info_header::type_t::bitmapv2infoheader)) {
        h.red_chanel_bitmask   = *(reinterpret_cast<uint32*>(buffer.get() + 36));
        h.green_chanel_bitmask = *(reinterpret_cast<uint32*>(buffer.get() + 40));
        h.blue_chanel_bitmask  = *(reinterpret_cast<uint32*>(buffer.get() + 44));
    }

    if (h.size >= static_cast<uint32>(info_header::type_t::bitmapv3infoheader)) {
        h.alpha_chanel_bitmask = *(reinterpret_cast<uint32*>(buffer.get() + 48));
    }

    return h;
}

bool check_signature(const file_header& h)
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

color_table read_color_table(std::ifstream& in, const info_header& info)
{
    color_table t;
    for (uint32 i = 0; i < info.colors_in_table; ++i) {
        uint8 red   = 0;
        uint8 green = 0;
        uint8 blue  = 0;
        uint8 alpha = 0;

        in.read(reinterpret_cast<char*>(blue), 1);
        in.read(reinterpret_cast<char*>(green), 1);
        in.read(reinterpret_cast<char*>(red), 1);

        if (info.type() != info_header::type_t::bitmapcoreheader) {
            in.read(reinterpret_cast<char*>(alpha), 1);
        }

        uint32 color = (red << 24) + (green << 16) + (blue << 8) + alpha;
        t.push_back(color);
    }

    return t;
}

bool read_data(std::ifstream& in,
               const info_header& info,
               const color_table& palette,
               framework::image::details::pixel_storage_interface* storage)
{
    storage->reserve(info.width * info.height);

    const bool bottom_up = info.type() == info_header::type_t::bitmapcoreheader ? true : info.height > 0;
    // const uint32 padding_count = ((info.bits_per_pixel * info.width + 31) / 32) % 4;

    for (int32 y = 0; y < info.height; ++y) {
        for (int32 x = 0; x < info.width;) {
            uint32 index = bottom_up ? ((info.height - y - 1) * info.width + x) : (y * info.width + x);

            switch (info.bits_per_pixel) {
                case 1:
                    if (palette.size() == 0) {
                        return false;
                    }
                    break;
                case 2: break;
                case 4: break;
                case 8: break;
                case 16: break;
                case 24: {
                    char buffer[3] = {0};
                    in.read(buffer, sizeof(buffer));

                    storage->set_pixel(index, buffer[2], buffer[1], buffer[0]);
                    ++x;
                } break;
                case 32: {
                    char buffer[4] = {0};
                    in.read(buffer, sizeof(buffer));

                    storage->set_pixel(index, buffer[2], buffer[1], buffer[0], buffer[3]);
                    ++x;
                } break;
                default: break;
            }
        }
    }

    return true;
}

} // namespace

namespace framework::image::details::bmp
{
bool load(const std::string& filename, pixel_storage_interface* storage)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return false;
    }

    file_header h = file_header::read(file);

    if (!check_signature(h)) {
        return false;
    }

    info_header info = info_header::read(file);

    if (info.type() == info_header::type_t::undefined) {
        return false;
    }

    const uint32 row_size        = ((info.bits_per_pixel * info.width + 31) / 32) * 4;
    const uint32 image_data_size = row_size * std::abs(info.height);

    if (image_data_size != info.image_size) {
        return false;
    }

    color_table palette;
    if (info.bits_per_pixel <= 8) {
        palette = read_color_table(file, info);
    }

    file.seekg(h.pixel_array_offset);

    if (!file) {
        return false;
    }

    return read_data(file, info, palette, storage);
}

bool save(const std::string& filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::binary);

    return false;
}

bool is_bmp(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return false;
    }

    file_header h = file_header::read(file);

    return check_signature(h);
}

} // namespace framework::image::details::bmp