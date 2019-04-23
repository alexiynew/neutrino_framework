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

#include <string>
#include <vector>

#include <common/types.hpp>
#include <image/details/image_info.hpp>

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

class image
{
public:
    using pixel_t      = uint8;
    using pixel_data_t = std::vector<pixel_t>;

    bool load(const std::string& filename);
    bool load(const std::string& filename, file_type type);

    bool save(const std::string& filename, file_type type) const;

    void flip_vertically();

    int32 width() const;
    int32 height() const;

    bool is_bottom_up() const;
    int32 pixel_size() const;

    const pixel_t* data() const;

private:
    details::image_info m_info;
    pixel_data_t m_data;
};

/// @}

} // namespace framework::image

/// @}

#endif
