#! /usr/bin/python3

import re
import generator

source = "/usr/include/GL/glxext.h"

desthpp = "./src/opengl/extensions/linux/glxext.hpp"
destcpp = "./src/opengl/extensions/linux/glxext.cpp"

group_regex = r'#ifndef\s([\w\d_]+)\s#define\s\1\s1\s(.*?)#endif\s/\*\s\1\s\*/'
type_regex = r'typedef.*\(\s?\*(PFN.*PROC)\).*;'
name_regex = r'.*(glX[\w\d_]+)\s?\(.*;'

exclude = ["PFNGLXGETPROCADDRESSARBPROC", "PFNGLXASSOCIATEDMPBUFFERSGIXPROC",
           "PFNGLXCREATEGLXVIDEOSOURCESGIXPROC", "PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC"]

header_file = "opengl/extensions/linux/glxext.hpp"

brief = "GLX extension functions wrapper."
date = "17.09.2018"

include_guard = "FRAMEWORK_OPENGL_EXTENSIONS_LINUX_GLXEXT_HPP"

include_files = ["GL/glx.h"]

init_function_description = "/// Initialize GLX functions"
init_function_name = "init_glx"

init_extensions_begin = ""

init_extensions_end = ""

license = "// =============================================================================\n" \
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

generator.generate(dict(source=source,
                        desthpp=desthpp,
                        destcpp=destcpp,
                        group_regex=group_regex,
                        type_regex=type_regex,
                        name_regex=name_regex,
                        exclude=exclude,
                        header_file=header_file,
                        brief=brief,
                        date=date,
                        include_guard=include_guard,
                        include_files=include_files,
                        init_function_description=init_function_description,
                        init_function_name=init_function_name,
                        init_extensions_begin=init_extensions_begin,
                        init_extensions_end=init_extensions_end,
                        license=license))
