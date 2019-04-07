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

#include <fstream>
#include <memory>
#include <vector>

#include <common/types.hpp>
#include <image/details/bmp.hpp>

namespace
{
using framework::uint16;
using framework::uint32;

//  | signature | file size | reserved | reserved | pixel array offset |
//  |------------------------------------------------------------------|
//  | 2         | 4         | 2        | 2        | 4                  |
struct header
{
    uint16 signature          = 0;
    uint32 file_size          = 0;
    uint32 pixel_array_offset = 0;

    static header read(std::ifstream& in);

    static constexpr uint32 size = 14;
};

// correspond to BITMAPINFOHEADER
struct dib_header
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

    uint32 size             = 0;
    uint32 width            = 0;
    uint32 height           = 0;
    uint16 planes           = 0;
    uint16 bits_per_pixel   = 0;
    uint32 compresion       = 0;
    uint32 image_size       = 0;
    uint32 x_ppm            = 0;
    uint32 y_ppm            = 0;
    uint32 colors_in_table  = 0;
    uint32 important_colors = 0;

    type_t type();

    static dib_header read(std::ifstream& in);
};

struct extra_bit_masks
{};

struct color_table
{};

header header::read(std::ifstream& in)
{
    char buffer[header::size];

    in.read(buffer, header::size);

    header h;
    h.signature          = (buffer[0] << 8) + buffer[1];
    h.file_size          = *(reinterpret_cast<uint32*>(buffer + 2));
    h.pixel_array_offset = *(reinterpret_cast<uint32*>(buffer + 2 + 4 + 4));

    return h;
}

dib_header::type_t dib_header::type()
{
    return static_cast<type_t>(size);
}

dib_header dib_header::read(std::ifstream& in)
{
    char size_buffer[4];
    in.read(size_buffer, sizeof(size_buffer));

    dib_header h;
    h.size = *(reinterpret_cast<uint32*>(size_buffer));

    std::unique_ptr<char[]> buffer(new char[h.size]);
    in.read(buffer.get(), h.size);

    if (h.type() == type_t::bitmapcoreheader) {
        h.width          = *(reinterpret_cast<uint16*>(buffer.get()));
        h.height         = *(reinterpret_cast<uint16*>(buffer.get() + 2));
        h.planes         = *(reinterpret_cast<uint16*>(buffer.get() + 4));
        h.bits_per_pixel = *(reinterpret_cast<uint16*>(buffer.get() + 6));
    } else {
        h.width          = *(reinterpret_cast<uint32*>(buffer.get()));
        h.height         = *(reinterpret_cast<uint32*>(buffer.get() + 4));
        h.planes         = *(reinterpret_cast<uint16*>(buffer.get() + 8));
        h.bits_per_pixel = *(reinterpret_cast<uint16*>(buffer.get() + 10));
    }

    if (h.size >= static_cast<uint32>(dib_header::type_t::bitmapinfoheader)) {
        h.compresion       = *(reinterpret_cast<uint32*>(buffer.get() + 12));
        h.image_size       = *(reinterpret_cast<uint32*>(buffer.get() + 16));
        h.x_ppm            = *(reinterpret_cast<uint32*>(buffer.get() + 20));
        h.y_ppm            = *(reinterpret_cast<uint32*>(buffer.get() + 24));
        h.colors_in_table  = *(reinterpret_cast<uint32*>(buffer.get() + 28));
        h.important_colors = *(reinterpret_cast<uint32*>(buffer.get() + 32));
    }

    return h;
}

bool check_signature(const header& h)
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

} // namespace

namespace framework::image::details::bmp
{
std::vector<uint8> load(const format_converter*, const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return std::vector<uint8>();
    }

    header h = header::read(file);

    if (!check_signature(h)) {
        return std::vector<uint8>();
    }

    dib_header dib = dib_header::read(file);

    if (dib.type() == dib_header::type_t::undefined) {
        return std::vector<uint8>();
    }

    return std::vector<uint8>();
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

    header h = header::read(file);

    return check_signature(h);
}

} // namespace framework::image::details::bmp