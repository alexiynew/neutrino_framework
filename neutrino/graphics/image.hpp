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

#ifndef FRAMEWORK_GRAPHICS_IMAGE_HPP
#define FRAMEWORK_GRAPHICS_IMAGE_HPP

#include <string>
#include <vector>

#include <common/types.hpp>
#include <graphics/color_type.hpp>

/// @brief Contains Image classes.
namespace framework::graphics
{
/// @addtogroup graphics_module
/// @{

class Image
{
public:
    enum class FileType
    {
        bmp,
        png
    };

    using data_t = std::vector<Color>;

    Image();

    Image(const data_t& data, int32 width, int32 height);

    Image(const Image&);
    Image& operator=(const Image&);

    Image(Image&&);
    Image& operator=(Image&&);

    bool load(const std::string& filename);
    bool load(const std::string& filename, FileType type);

    int32 width() const;
    int32 height() const;

    float32 gamma() const;

    const Color* data() const;

private:
    data_t m_data;

    int32 m_width  = 0;
    int32 m_height = 0;

    float32 m_gamma = 2.2f;
};

/// @}

} // namespace framework::graphics

#endif
