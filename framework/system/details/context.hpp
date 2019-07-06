/// @file
/// @brief Graphic context.
/// @author Fedorov Alexey
/// @date 11.09.2018

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

#ifndef FRAMEWORK_GRAPHICS_CONTEXT_HPP
#define FRAMEWORK_GRAPHICS_CONTEXT_HPP

#include <memory>

#include <common/types.hpp>
#include <system/context_settings.hpp>

namespace framework::system::details
{
class context
{
public:
    explicit context(context_settings settings) noexcept;

    context(const context&) = default;
    context(context&&)      = default;

    context& operator=(const context&) = default;
    context& operator=(context&&) = default;

    virtual ~context();

    virtual bool valid() const        = 0;
    virtual bool is_current() const   = 0;
    virtual void make_current() const = 0;
    virtual void swap_buffers() const = 0;

    const context_settings& settings() const;

private:
    context_settings m_settings;
};

} // namespace framework::system::details

#endif
