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

#include <stdexcept>

#include <system/src/osx/osx_context.hpp>

namespace framework::system::details
{
OsxContext::OsxContext(const ContextSettings& settings)
    : Context(settings)
{}

OsxContext::~OsxContext()
{}

bool OsxContext::valid() const
{
    return false;
}

bool OsxContext::is_current() const
{
    return false;
}

Context::Api OsxContext::api_type() const
{
    return Context::Api::opengl;
}

Context::VoidFunctionPtr OsxContext::get_function(const char* /*function_name*/) const
{
    return nullptr;
}

void OsxContext::make_current()
{}

void OsxContext::swap_buffers()
{}

} // namespace framework::system::details
