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

#include <graphics/image.hpp>

#include <graphics/src/image/bmp.hpp>
#include <graphics/src/image/image_info.hpp>
#include <graphics/src/image/png.hpp>

namespace framework::graphics
{
Image::Image() = default;

Image::Image(const DataType& data, int width, int height)
    : m_data(data)
    , m_width(width)
    , m_height(height)
{}

Image::Image(const Image&) = default;
Image& Image::operator=(const Image&) = default;

Image::Image(Image&&) = default;
Image& Image::operator=(Image&&) = default;

bool Image::load(const std::string& filename, FileType type)
{
    auto load_function = [type](const std::string& f) {
        switch (type) {
            case FileType::bmp: return details::image::bmp::load(f);
            case FileType::png: return details::image::png::load(f);
        }
        return details::image::LoadResult();
    };

    if (auto result = load_function(filename); result.has_value()) {
        auto& [info, data] = *result;

        m_width  = info.width;
        m_height = info.height;
        m_gamma  = info.gamma;

        m_data = std::move(data);
        return true;
    }

    return false;
}

bool Image::load(const std::string& filename)
{
    if (details::image::bmp::is_bmp(filename)) {
        return load(filename, FileType::bmp);
    } else if (details::image::png::is_png(filename)) {
        return load(filename, FileType::png);
    }

    return false;
}

int Image::width() const
{
    return m_width;
}

int Image::height() const
{
    return m_height;
}

float Image::gamma() const
{
    return m_gamma;
}

const Color* Image::data() const
{
    return m_data.data();
}

void swap(Image& lhs, Image& rhs) noexcept
{
    using std::swap;

    swap(lhs.m_data, rhs.m_data);
    swap(lhs.m_width, rhs.m_width);
    swap(lhs.m_height, rhs.m_height);
    swap(lhs.m_gamma, rhs.m_gamma);
}

} // namespace framework::graphics
