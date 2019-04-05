/// @file
/// @brief Image class.
/// @author Fedorov Alexey
/// @date 04.04.2019

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

#ifndef FRAMEWORK_IMAGE_IMAGE_HPP
#define FRAMEWORK_IMAGE_IMAGE_HPP

#include <image/details/bmp.hpp>
#include <image/details/format_converter.hpp>
#include <image/details/png.hpp>
#include <image/details/tga.hpp>
#include <string>
#include <vector>
#include <memory>

#include <common/types.hpp>

/// @details
///
///
/// @defgroup image_module Image
/// @{

/// @brief Contains image classes.
namespace framework::image
{
/// @addtogroup image_module
/// @{
enum class file_type
{
    bmp,
    tga,
    png
};

enum class pixel_format
{
    rgb,
    bgr,
    rgba,
    bgra,
};

template <pixel_format Format>
class image
{
public:
    bool load(const std::string& filename, file_type type);
    bool load(const std::string& filename);

    bool save(const std::string& filename, file_type type) const;

    std::vector<uint8> data() const;

private:
    std::vector<uint8> m_data;
};

template <pixel_format Format>
bool image<Format>::load(const std::string& filename, file_type type)
{
    auto converter = []() {
        if constexpr (Format == pixel_format::rgb) {
            return std::make_unique<details::format_converter_rgb>();
        } else if constexpr (Format == pixel_format::bgr) {
            return std::make_unique<details::format_converter_bgr>();
        } else if constexpr (Format == pixel_format::rgba) {
            return std::make_unique<details::format_converter_rgba>();
        } else if constexpr (Format == pixel_format::bgra) {
            return std::make_unique<details::format_converter_bgra>();
        } else {
            static_assert("Unknown pixel format.");
        }
    };

    switch (type) {
        case file_type::bmp: m_data = details::bmp::load(converter().get(), filename); break;
        case file_type::tga: m_data = details::tga::load(converter().get(), filename); break;
        case file_type::png: m_data = details::png::load(converter().get(), filename); break;
        default: break;
    }

    return !m_data.empty();
} 

template <pixel_format Format>
bool image<Format>::load(const std::string& filename)
{
    if (details::bmp::is_bmp(filename)) {
        return load(filename, file_type::bmp);
    } else if (details::tga::is_tga(filename)) {
        return load(filename, file_type::tga);
    } else if (details::png::is_png(filename)) {
        return load(filename, file_type::png);
    }

    return false;
}

template <pixel_format Format>
bool image<Format>::save(const std::string& filename, file_type type) const
{
    switch (type) {
        case file_type::bmp: return details::bmp::save(filename);
        case file_type::tga: return details::tga::save(filename);
        case file_type::png: return details::png::save(filename);
        default: break;
    }

    return false;
}

template <pixel_format Format>
std::vector<uint8> image<Format>::data() const
{
    return m_data;
}
/// @}

} // namespace framework::image

/// @}

#endif
