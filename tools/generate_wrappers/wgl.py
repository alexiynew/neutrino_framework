#!/usr/bin/python3
"""Generates extension wrapper for wgl functions."""


class GeneratorData:
    def __init__(self):
        self.URL = "https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/master/xml"
        self.XML = "wgl.xml"

        self.DESTHPP = "./neutrino/system/src/windows/wglext.hpp"
        self.DESTCPP = "./neutrino/system/src/windows/wglext.cpp"

        self.API = ""
        self.SUPPORTED = "wgl"
        self.PROFILE = ""

        self.BRIEF = "WGL extension functions wrapper."
        self.DATE = "17.09.2018"

        self.NAMESPACE = "framework::system::details::wgl"

        self.TYPEDEFS = "" \
            "typedef void GLvoid;\n" \
            "typedef unsigned int GLenum;\n" \
            "typedef float GLfloat;\n" \
            "typedef int GLint;\n" \
            "typedef int GLsizei;\n" \
            "typedef unsigned int GLbitfield;\n" \
            "typedef double GLdouble;\n" \
            "typedef unsigned int GLuint;\n" \
            "typedef unsigned char GLboolean;\n" \
            "typedef unsigned char GLubyte;\n" \
            "typedef unsigned short GLushort;\n" \

        self.INCLUDE_GUARD = "FRAMEWORK_SYSTEM_SRC_WINDOWS_WGLEXT_HPP"

        self.HEADER_INCLUDE_FILES = ["windows.h", "functional"]
        self.CPP_INCLUDE_FILES = ["type_traits", "mutex",
                                  "system/src/windows/wglext.hpp"]

        self.INIT_FUNCTION_NAME = "init_wgl"

        self.LICENSE = "// =============================================================================\n" \
            "// MIT License\n" \
            "//\n" \
            "// Copyright (c) 2017-2021 Fedorov Alexey\n" \
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
