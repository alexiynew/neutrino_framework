/// @file
/// @brief Tga image implementation.
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
#include <string>
#include <vector>

#include <common/types.hpp>
#include <common/utils.hpp>
#include <graphics/src/image/tga.hpp>

namespace
{
using namespace framework;

constexpr uint8 tga_signature[] = "TRUEVISION-XFILE";

enum class image_type_t : uint8
{
    no_image_data       = 0,
    colormapped         = 1,
    truecolor           = 2,
    monochrome          = 3,
    colormapped_encoded = 9,
    truecolor_encoded   = 10,
    monochrome_encoded  = 11,
};

struct file_header_t
{
    static constexpr usize size = 18;

    uint8 id_length;         /* 00h  Size of Image ID field */
    uint8 colormap_type;     /* 01h  Color map type 0, 1, up to 128 reserved*/
    image_type_t image_type; /* 02h  Image type code up to 128 reserved*/
    uint16 colormap_start;   /* 03h  Color map origin 0 if colormap_type 0*/
    uint16 colormap_length;  /* 05h  Color map length 0 if colormap_type 0*/
    uint8 colormap_depth;    /* 07h  Depth of color map entries 15, 16, 24, 32, 0 if colorap_type 0 */
    uint16 x_offset;         /* 08h  X origin of image */
    uint16 y_offset;         /* 0Ah  Y origin of image */
    uint16 width;            /* 0Ch  Width of image max 512*/
    uint16 height;           /* 0Eh  Height of image max 482*/
    uint8 pixel_depth;       /* 10h  Image pixel size */
    uint8 image_descriptor;  /* 11h  Image descriptor byte */

    static file_header_t read(std::ifstream& in);

    bool valid() const;
};

file_header_t file_header_t::read(std::ifstream& in)
{
    char buffer[file_header_t::size] = {};

    in.read(buffer, file_header_t::size);

    file_header_t header;
    header.id_length        = static_cast<uint8>(buffer[0]);
    header.colormap_type    = static_cast<uint8>(buffer[1]);
    header.image_type       = static_cast<image_type_t>(buffer[2]);
    header.colormap_start   = utils::little_endian_value<uint16>(&buffer[3]);
    header.colormap_length  = utils::little_endian_value<uint16>(&buffer[5]);
    header.colormap_depth   = static_cast<uint8>(buffer[7]);
    header.x_offset         = utils::little_endian_value<uint16>(&buffer[8]);
    header.y_offset         = utils::little_endian_value<uint16>(&buffer[10]);
    header.width            = utils::little_endian_value<uint16>(&buffer[12]);
    header.height           = utils::little_endian_value<uint16>(&buffer[14]);
    header.pixel_depth      = static_cast<uint8>(buffer[16]);
    header.image_descriptor = static_cast<uint8>(buffer[17]);

    return header;
}

bool file_header_t::valid() const
{
    auto check_image_type = [](image_type_t img_type) {
        switch (img_type) {
            case image_type_t::no_image_data:
            case image_type_t::colormapped:
            case image_type_t::truecolor:
            case image_type_t::monochrome:
            case image_type_t::colormapped_encoded:
            case image_type_t::truecolor_encoded:
            case image_type_t::monochrome_encoded: return true;
        }
        return false;
    };

    const bool colormap_zero = colormap_type == 0 && colormap_start == 0 && colormap_length == 0 && colormap_depth == 0;

    const bool colormap_valid       = colormap_zero || colormap_type == 1;
    const bool image_type_valid     = check_image_type(image_type);
    const bool colormap_depth_valid = colormap_depth == 0 || colormap_depth == 15 || colormap_depth == 16 ||
                                      colormap_depth == 24 || colormap_depth == 32;
    const bool pixel_depth_valid      = pixel_depth == 8 || pixel_depth == 16 || pixel_depth == 24 || pixel_depth == 32;
    const bool image_descriptor_valid = (image_descriptor & 0xC0) == 0;

    return colormap_valid && image_type_valid && colormap_depth_valid && pixel_depth_valid && image_descriptor_valid;
}

struct file_footer_t
{
    static constexpr usize size           = 26;
    static constexpr usize signature_size = 16;

    uint32 extension_area_offset;
    uint32 developer_directory_offset;
    uint8 signature[signature_size];
    uint8 dot;
    uint8 zero_byte;

    static file_footer_t read(std::ifstream& in);

    bool valid() const;
};

file_footer_t file_footer_t::read(std::ifstream& in)
{
    char buffer[file_footer_t::size] = {};
    in.read(buffer, file_footer_t::size);

    file_footer_t footer;
    footer.extension_area_offset      = utils::little_endian_value<uint32>(&buffer[0]);
    footer.developer_directory_offset = utils::little_endian_value<uint32>(&buffer[4]);

    std::copy(&buffer[8], &buffer[24], footer.signature);

    footer.dot       = static_cast<uint8>(buffer[24]);
    footer.zero_byte = static_cast<uint8>(buffer[25]);

    return footer;
}

bool file_footer_t::valid() const
{
    const bool signature_valid = std::equal(signature, signature + signature_size, tga_signature);

    return signature_valid && dot == 0x2E && zero_byte == 0;
}

bool check_image_footer(std::ifstream& in)
{
    in.seekg(-file_footer_t::size, std::ios::end);
    file_footer_t footer = file_footer_t::read(in);
    in.seekg(0);

    if (in && footer.valid()) {
        return true;
    }

    return false;
}

} // namespace

namespace framework::graphics::details::image::tga
{
load_result_t load(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        return load_result_t();
    }

    if (!check_image_footer(file)) {
        return load_result_t();
    }

    file_header_t header = file_header_t::read(file);
    if (!header.valid()) {
        return load_result_t();
    }

    return load_result_t();
}

bool is_tga(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);

    if (check_image_footer(file)) {
        return true;
    }

    file_header_t header = file_header_t::read(file);
    return file && header.valid();
}

} // namespace framework::graphics::details::image::tga
