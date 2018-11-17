#!/usr/bin/python3
"""Generates extension wrapper for gl functions."""

import generator

SOURCE = "./dependencies/GL/glcorearb.h"

DESTHPP = "./src/opengl/details/gl_wrapper.hpp"
DESTCPP = "./src/opengl/details/gl_wrapper.cpp"

GROUP_REGEX = r'#ifndef\s([\w\d_]+)\s#define\s\1\s1\s(.*?)#endif\s/\*\s\1\s\*/'
TYPE_REGEX = r'typedef.*\(APIENTRYP\s(PFN.*PROC)\).*;'
NAME_REGEX = r'.*\s(gl[\w\d_]+)\s?\(.*;'

EXCLUDE = []

HEADER_FILE = "opengl/details/gl_wrapper.hpp"

BRIEF = "OpneGL functions wrapper."
DATE = "17.09.2018"

INCLUDE_GUARD = "FRAMEWORK_OPENGL_GL_WRAPPER_HPP"

INCLUDE_FILES = ["GL/glcorearb.h"]

INIT_FUNCTION_NAME = "init_gl_functions"

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
                        init_function_name=INIT_FUNCTION_NAME,
                        license=LICENSE))
