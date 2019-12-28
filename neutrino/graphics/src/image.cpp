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

#include <graphics/image.hpp>
#include <graphics/src/image/bmp.hpp>
#include <graphics/src/image/image_info.hpp>
#include <graphics/src/image/png.hpp>
#include <graphics/src/image/tga.hpp>

namespace framework::graphics
{
image::image() = default;

image::image(const image&) = default;
image& image::operator=(const image&) = default;

image::image(image&&) = default;
image& image::operator=(image&&) = default;

bool image::load(const std::string& filename, file_type type)
{
    auto load_function = [type](const std::string& f) {
        switch (type) {
            case file_type::bmp: return details::image::bmp::load(f);
            case file_type::tga: return details::image::tga::load(f);
            case file_type::png: return details::image::png::load(f);
            default: break;
        }
        return details::image::load_result_t();
    };

    if (auto result = load_function(filename); result.has_value()) {
        auto& [info, data] = *result;

        m_width     = info.width;
        m_height    = info.height;
        m_bottom_up = info.bottom_up;
        m_gamma     = info.gamma;

        m_data = std::move(data);
        return true;
    }

    return false;
}

bool image::load(const std::string& filename)
{
    if (details::image::bmp::is_bmp(filename)) {
        return load(filename, file_type::bmp);
    } else if (details::image::tga::is_tga(filename)) {
        return load(filename, file_type::tga);
    } else if (details::image::png::is_png(filename)) {
        return load(filename, file_type::png);
    }

    return false;
}

void image::flip_vertically()
{
    data_t tmp(m_data.size());

    auto from = begin(m_data);
    auto to   = prev(end(tmp), width());

    for (int32 y = 0; y < height(); ++y) {
        auto next_from = next(from, width());

        copy(from, next_from, to);

        from = next_from;
        to   = prev(to, width());
    }

    m_data = std::move(tmp);

    m_bottom_up = !m_bottom_up;
}

int32 image::width() const
{
    return m_width;
}

int32 image::height() const
{
    return m_height;
}

bool image::is_bottom_up() const
{
    return m_bottom_up;
}

int32 image::pixel_size() const
{
    return 4;
}

float32 image::gamma() const
{
    return m_gamma;
}

const color_t* image::data() const
{
    return m_data.data();
}

} // namespace framework::graphics
