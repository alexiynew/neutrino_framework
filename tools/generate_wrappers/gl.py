#!/usr/bin/python3
"""Generates extension wrapper for gl functions."""


class GeneratorData:
    def __init__(self):
        self.URL = "https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/master/xml"
        self.XML = "gl.xml"

        self.DESTHPP = "./neutrino/graphics/src/opengl/opengl.hpp"
        self.DESTCPP = "./neutrino/graphics/src/opengl/opengl.cpp"

        self.API = "gl"
        self.SUPPORTED = "glcore"
        self.PROFILE = "core"

        self.BRIEF = "OpneGL functions wrapper."
        self.DATE = "17.09.2018"

        self.NAMESPACE = "framework::graphics::details::opengl"

        self.TYPEDEFS = ""

        self.INCLUDE_GUARD = "FRAMEWORK_GRAPHICS_SRC_OPENGL_OPENGL_HPP"

        self.HEADER_INCLUDE_FILES = ["functional", "KHR/khrplatform.h"]
        self.CPP_INCLUDE_FILES = ["mutex", "graphics/src/opengl/opengl.hpp"]

        self.INIT_FUNCTION_NAME = "init_opengl"

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
