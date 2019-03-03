/// @file
/// @brief WGL extension functions wrapper.
/// @author Fedorov Alexey
/// @date 17.09.2018

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

#include <mutex>

#include <opengl/details/windows/wglext.hpp>

namespace
{
std::once_flag init_flag;

void init_extensions()
{
    HDC hdc = GetDC(nullptr);

    if (hdc == nullptr) {
        return;
    }

    PIXELFORMATDESCRIPTOR pfd{};
    pfd.nSize    = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags  = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    if (pixelFormat == 0) {
        ReleaseDC(nullptr, hdc);
        return;
    }

    if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
        ReleaseDC(nullptr, hdc);
        return;
    }

    HGLRC hglrc = wglCreateContext(hdc);
    if (hglrc == nullptr) {
        ReleaseDC(nullptr, hdc);
        return;
    }

    wglMakeCurrent(hdc, hglrc);

    ::framework::opengl::opengl_details::init_wgl_functions();

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hglrc);
    ReleaseDC(nullptr, hdc);
}

} // namespace

namespace framework::opengl
{
void init_wgl()
{
    std::call_once(init_flag, init_extensions);
}

} // namespace framework::opengl
#pragma endregion
