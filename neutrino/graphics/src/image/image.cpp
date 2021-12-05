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

namespace
{

inline framework::graphics::Image::LoadResult load_result_error(const std::string& error)
{
    return std::make_tuple(false, error);
}

inline framework::graphics::Image::LoadResult load_result_success()
{
    return std::make_tuple(true, "");
}

} // namespace

namespace framework::graphics
{
Image::Image() = default;

Image::Image(const DataType& data, int width, int height)
    : m_data(data)
    , m_width(width)
    , m_height(height)
{}

Image::LoadResult Image::load(const std::filesystem::path& file, FileType type)
{
    using namespace details::image;

    auto load_function = [type](const std::filesystem::path& f) {
        switch (type) {
            case FileType::bmp: return bmp::load(f);
            case FileType::png: return png::load(f);
        }
        return details::image::LoadResult(error::invalid_file_type);
    };

    try {
        const auto& result = load_function(file);

        if (std::holds_alternative<ImageInfo>(result)) {
            const ImageInfo info = std::get<ImageInfo>(result);

            m_width  = info.width;
            m_height = info.height;
            m_gamma  = info.gamma;
            m_data   = std::move(info.data);

            return load_result_success();
        } else {
            return load_result_error(std::get<ErrorDescription>(result));
        }
    } catch (const std::bad_variant_access& acces_exception) {
        return load_result_error(acces_exception.what());
    } catch (const std::exception& exception) {
        return load_result_error(exception.what());
    } catch (...) {
        return load_result_error(error::unknown_error);
    }
}

Image::LoadResult Image::load(const std::filesystem::path& file)
{
    using namespace details::image;

    if (!std::filesystem::exists(file)) {
        return load_result_error(error::open_file_error);
    }

    if (bmp::is_bmp(file)) {
        return load(file, FileType::bmp);
    } else if (png::is_png(file)) {
        return load(file, FileType::png);
    }

    return load_result_error(error::invalid_file_type);
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
