#!/usr/bin/python3
"""Generates extension wrapper for wgl functions."""

import generator

SOURCE = "./dependencies/GL/wglext.h"

DESTHPP = "./src/opengl/extensions/windows/wglext.hpp"
DESTCPP = "./src/opengl/extensions/windows/wglext.cpp"

GROUP_REGEX = r'#ifndef\s([\w\d_]+)\s#define\s\1\s1\s(.*?)#endif\s/\*\s\1\s\*/'
TYPE_REGEX = r'typedef.*\(WINAPI\s?\*\s?(PFN[\w\d_]*PROC)\).*;'
NAME_REGEX = r'.*WINAPI\s([\w\d_]+)\s\(.*\);'

EXCLUDE = []

HEADER_FILE = "opengl/extensions/windows/wglext.hpp"

BRIEF = "WGL extension functions wrapper."
DATE = "17.09.2018"

INCLUDE_GUARD = "FRAMEWORK_OPENGL_EXTENSIONS_WINDOWS_WGLEXT_HPP"

INCLUDE_FILES = ["GL/glcorearb.h", "GL/wglext.h"]

INIT_FUNCTION_DESCRIPTION = "/// Initialize WGL functions"
INIT_FUNCTION_NAME = "init_wgl"

INIT_EXTENSIONS_BEGIN = "    HDC hdc = GetDC(nullptr);\n"\
                        "\n"\
                        "    if (hdc == nullptr) {\n"\
                        "        return;\n"\
                        "    }\n"\
                        "\n"\
                        "    PIXELFORMATDESCRIPTOR pfd{0};\n"\
                        "    pfd.nSize    = sizeof(PIXELFORMATDESCRIPTOR);\n"\
                        "    pfd.nVersion = 1;\n"\
                        "    pfd.dwFlags  = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;\n"\
                        "\n"\
                        "    int pixelFormat = ChoosePixelFormat(hdc, &pfd);\n"\
                        "    if (pixelFormat == 0) {\n"\
                        "        ReleaseDC(nullptr, hdc);\n"\
                        "        return;\n"\
                        "    }\n"\
                        "\n"\
                        "    if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {\n"\
                        "        ReleaseDC(nullptr, hdc);\n"\
                        "        return;\n"\
                        "    }\n"\
                        "\n"\
                        "    HGLRC hglrc = wglCreateContext(hdc);\n"\
                        "    if (hglrc == nullptr) {\n"\
                        "        ReleaseDC(nullptr, hdc);\n"\
                        "        return;\n"\
                        "    }\n"\
                        "\n"\
                        "    wglMakeCurrent(hdc, hglrc);\n"\

INIT_EXTENSIONS_END = "    wglMakeCurrent(nullptr, nullptr);\n"\
                      "    wglDeleteContext(hglrc);\n"\
                      "    ReleaseDC(nullptr, hdc);\n"

LICENSE = "// =============================================================================\n" \
          "// MIT License\n" \
          "//\n" \
          "// Copyright (c) 2017-2018 Fedorov Alexey\n" \
          "//\n" \
          "// Permission is hereby granted, free of charge, to any person obtaining a copy\n" \
          "// of this software and associated documentation files (the \"Software\"), to deal\n" \
          "// in the Software without restriction, including without limitation the rights\n" \
          "// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n" \
          "// copies of the Software, and to permit persons to whom the Software is\n" \
          "// furnished to do so, subject to the following conditions:\n" \
          "//\n" \
          "// The above copyright notice and this permission notice shall be included in all\n" \
          "// copies or substantial portions of the Software.\n" \
          "//\n" \
          "// THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n" \
          "// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n" \
          "// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n" \
          "// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n" \
          "// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n" \
          "// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n" \
          "// SOFTWARE.\n" \
          "// =============================================================================\n"


generator.generate(dict(source=SOURCE,
                        desthpp=DESTHPP,
                        destcpp=DESTCPP,
                        group_regex=GROUP_REGEX,
                        type_regex=TYPE_REGEX,
                        name_regex=NAME_REGEX,
                        exclude=EXCLUDE,
                        header_file=HEADER_FILE,
                        brief=BRIEF,
                        date=DATE,
                        include_guard=INCLUDE_GUARD,
                        include_files=INCLUDE_FILES,
                        init_function_description=INIT_FUNCTION_DESCRIPTION,
                        init_function_name=INIT_FUNCTION_NAME,
                        init_extensions_begin=INIT_EXTENSIONS_BEGIN,
                        init_extensions_end=INIT_EXTENSIONS_END,
                        license=LICENSE))
