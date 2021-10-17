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

#ifndef FRAMEWORK_SYSTEM_SRC_OSX_OSX_CONTEXT_HPP
#define FRAMEWORK_SYSTEM_SRC_OSX_OSX_CONTEXT_HPP

#include <system/context.hpp>

#import <AppKit/AppKit.h>

namespace framework::system::details
{
class OSXContext : public Context
{
public:
    OSXContext(NSView* view, const ContextSettings& settings);
    ~OSXContext() override;

    OSXContext(const OSXContext&) = default;
    OSXContext(OSXContext&&)      = default;

    OSXContext& operator=(const OSXContext&) noexcept = default;
    OSXContext& operator=(OSXContext&&) noexcept = default;

    bool valid() const override;
    bool is_current() const override;
    Api api_type() const override;

    VoidFunctionPtr get_function(const char* function_name) const override;

    void make_current() override;
    void swap_buffers() override;

    void update();

private:
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    NSView* m_view             = nullptr;
    NSOpenGLContext* m_context = nullptr;
#pragma clang diagnostic pop
};

} // namespace framework::system::details

#endif
