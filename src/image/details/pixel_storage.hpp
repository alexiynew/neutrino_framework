/// @file
/// @brief Image pixel storage.
/// @author Fedorov Alexey
/// @date 07.04.2019

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

#ifndef FRAMEWORK_IMAGE_DETAILS_PIXEL_STORAGE_HPP
#define FRAMEWORK_IMAGE_DETAILS_PIXEL_STORAGE_HPP

#include <vector>

#include <common/types.hpp>
#include <common/pixel_type.hpp>

namespace framework::image::details
{
class pixel_storage_interface
{
public:
    virtual ~pixel_storage_interface() = default;

    virtual void set_pixel(uint32 index, uint8 red, uint8 green, uint8 blue, uint8 alpha = 0) = 0;
    virtual void resize(uint32 size)                                                          = 0;
};

template <pixel_format Format>
class pixel_storage : public pixel_storage_interface
{
public:
    using pixel_data_t = std::vector<pixel_t<Format>>;

    pixel_storage(pixel_data_t& data) : m_data(data)
    {}

    virtual void set_pixel(uint32 index, uint8 red, uint8 green, uint8 blue, uint8 alpha = 0) override
    {
        m_data[index] = make_pixel<Format>(red, green, blue, alpha);
    }

    virtual void resize(uint32 size) override
    {
        m_data.resize(size);
    }

    const pixel_data_t& data() const
    {
        return m_data;
    }

private:
    pixel_data_t& m_data;
};

} // namespace framework::image::details

#endif
