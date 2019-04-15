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

#include <memory>
#include <string>
#include <vector>

#include <common/types.hpp>
#include <image/details/bmp.hpp>
#include <image/details/format_converter.hpp>
#include <image/details/pixel_type.hpp>
#include <image/details/png.hpp>
#include <image/details/tga.hpp>

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

using pixel_format = details::pixel_format;

template <pixel_format Format>
class image
{
public:
    using pixel_t      = details::pixel_t<Format>;
    using pixel_data_t = details::pixel_data_t<Format>;

    bool load(const std::string& filename, file_type type);
    bool load(const std::string& filename);

    bool save(const std::string& filename, file_type type) const;

    const pixel_t* data() const;

private:
    pixel_data_t m_data;
};

template <pixel_format Format>
bool image<Format>::load(const std::string& filename, file_type type)
{
    details::pixel_storage<Format> storage(m_data);

    switch (type) {
        case file_type::bmp: return details::bmp::load(filename, &storage);
        case file_type::tga: return details::tga::load(filename, &storage);
        case file_type::png: return details::png::load(filename, &storage);
        default: break;
    }

    return false;
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
const typename image<Format>::pixel_t* image<Format>::data() const
{
    return &m_data[0];
}
/// @}

} // namespace framework::image

/// @}

#endif
