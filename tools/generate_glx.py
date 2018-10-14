#! /usr/bin/python3

import re
from string import Template

source = "/usr/include/GL/glxext.h"
desthpp = "./src/opengl/extensions/linux/glxext.hpp"
destcpp = "./src/opengl/extensions/linux/glxext.cpp"

group_regex = r'#ifndef\s([\w\d_]+)\s#define\s\1\s1\s(.*?)#endif\s/\*\s\1\s\*/'
type_regex = r'typedef.*\(\s?\*(PFN.*PROC)\).*;'
name_regex = r'.*(glX[\w\d_]+)\s?\(.*;'

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

exclude = ["PFNGLXGETPROCADDRESSARBPROC", "PFNGLXASSOCIATEDMPBUFFERSGIXPROC", "PFNGLXCREATEGLXVIDEOSOURCESGIXPROC", "PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC"]

class function:
    type = ''
    name = ''

    def __init__(self, t, n):
        self.type = t
        self.name = n


class section:
    name = ''
    lower_name = ''
    functions = []

    def __init__(self, name, functions):
        self.name = name
        self.lower_name = name.lower()
        self.functions = functions


def get_sections():
    sections = []

    file = open(source, "r")

    groups = re.findall(group_regex, file.read(), re.S)
    groups = list(filter(lambda g: not(g[0] in exclude), groups))

    for g in groups:
        types = re.findall(type_regex, g[1])
        names = re.findall(name_regex, g[1])

        functions = (
            list(map(lambda f: function(f[0], f[1]), list(zip(types, names)))))
        functions = list(filter(lambda f: not(f.name in exclude) and not(f.type in exclude), functions))

        sections.append(section(g[0], functions))

    file.close()

    return sections


def generate_declarations(sections):
    t = Template("\n"
                 "#pragma region ${name}\n"
                 "\n"
                 "${functions}\n"
                 "\n"
                 "#pragma endregion\n")

    result = ""
    for s in sections:
        d = dict(name=s.name,
                 functions="\n".join("extern {f.type} {f.name};".format(f=f) for f in s.functions))

        result += t.substitute(d)

    return result


def generate_header(sections):
    t = "/// @file\n" \
        "/// @brief GLX extension functions wrapper.\n" \
        "/// @author Fedorov Alexey\n" \
        "/// @date 17.09.2018\n" \
        "\n" \
        "{license}" \
        "\n" \
        "#ifndef FRAMEWORK_OPENGL_EXTENSIONS_LINUX_GLXEXT_HPP\n" \
        "#define FRAMEWORK_OPENGL_EXTENSIONS_LINUX_GLXEXT_HPP\n" \
        "\n" \
        "#include <GL/glx.h>\n" \
        "\n" \
        "namespace framework::opengl\n" \
        "{{\n" \
        "{is_glx_extension_supported}" \
        "\n" \
        "{declarations}" \
        "\n" \
        "/// Initialize GLX functions\n" \
        "void init_glx();\n" \
        "\n" \
        "}} // namespace framework::opengl\n" \
        "\n" \
        "#endif\n"

    is_glx_extension_supported = "\n".join(
        "extern bool {s.lower_name}_supported;".format(s=s) for s in sections)

    hpp = open(desthpp, "w")
    hpp.write(t.format(license=license,
                       is_glx_extension_supported=is_glx_extension_supported,
                       declarations=generate_declarations(sections)))
    hpp.close()


def generate_init_declarations(sections):
    t = Template("#pragma region init_declarations\n"
                 "\n"
                 "${init_functions}"
                 "\n"
                 "void init_extensions();\n"
                 "\n"
                 "#pragma endregion\n")

    return t.substitute(init_functions="\n".join("bool init_{0}();".format(s.name.lower()) for s in sections) + "\n")


def generate_null_definitions(sections):
    t = Template("#pragma region ${name}\n"
                 "\n"
                 "${null_definition}"
                 "\n"
                 "#pragma endregion\n")

    result = ""

    return "\n".join(t.substitute(name=s.name,
                                  null_definition="\n".join("{0} {1} = nullptr;".format(
                                      f.type, f.name) for f in s.functions) + "\n") for s in sections)


def generate_init_definitions(sections):
    t = Template("bool init_${lower_name}()\n"
                 "{\n"
                 "    bool result = true;\n"
                 "\n"
                 "    // clang-format off\n"
                 "${assignment}"
                 "\n"
                 "    // clang-format on\n"
                 "\n"
                 "    return result;\n"
                 "}\n")

    impl_str = "    result = result && (framework::opengl::{0} = get_function<{1}>(\"{0}\")) != nullptr;"

    init_functions = "\n".join(t.substitute(name=s.name,
                                            lower_name=s.name.lower(),
                                            assignment="\n".join(impl_str.format(f.name, f.type) for f in s.functions)) for s in sections)

    e = Template("#pragma region init_definitions\n"
                 "\n"
                 "namespace\n"
                 "{\n"
                 "${init_functions}"
                 "\n"
                 "void init_extensions()\n"
                 "{\n"
                 "    // clang-format off\n"
                 "${assignment_glx_extensions}"
                 "    // clang-format on\n"
                 "\n"
                 "}\n"
                 "\n"
                 "} // namespace\n"
                 "\n"
                 "#pragma endregion\n")

    return e.substitute(init_functions=init_functions,
                        assignment_glx_extensions="\n".join("    framework::opengl::{0}_supported = init_{0}();".format(s.lower_name) for s in sections) + "\n")


def generate_source(sections):
    t = Template("/// @file\n"
                 "/// @brief GLX extension functions wrapper.\n"
                 "/// @author Fedorov Alexey\n"
                 "/// @date 16.09.2018\n"
                 "\n"
                 "${license}"
                 "\n"
                 "#include <array>\n"
                 "#include <mutex>\n"
                 "\n"
                 "#include <common/types.hpp>\n"
                 "#include <opengl/details/gl_details.hpp>\n"
                 "#include <opengl/extensions/linux/glxext.hpp>\n"
                 "\n"
                 "namespace\n"
                 "{\n"
                 "std::once_flag init_flag;\n"
                 "\n"
                 "template <typename F>\n"
                 "F get_function(const char* function_name)\n"
                 "{\n"
                 "    return reinterpret_cast<F>(framework::opengl::details::get_function(function_name));\n"
                 "}\n"
                 "\n"
                 "${init_declarations}"
                 "\n"
                 "} // namespace\n"
                 "\n"
                 "namespace framework::opengl\n"
                 "{\n"
                 "${is_glx_extension_supported}"
                 "\n"
                 "${null_definitions}"
                 "\n"
                 "void init_glx()\n"
                 "{\n"
                 "    std::call_once(init_flag, []() { ::init_extensions(); });\n"
                 "}\n"
                 "\n"
                 "} // namespace framework::opengl\n"
                 "\n"
                 "${init_definitions}")

    d = dict(license=license,
             is_glx_extension_supported="\n".join(
                 "bool {s.lower_name}_supported = false;".format(s=s) for s in sections) + "\n",
             init_declarations=generate_init_declarations(sections),
             null_definitions=generate_null_definitions(sections),
             init_definitions=generate_init_definitions(sections))

    cpp = open(destcpp, "w")
    cpp.write(t.substitute(d))
    cpp.close()


sections = list(filter(lambda s: len(s.functions) > 0, get_sections()))

generate_header(sections)
generate_source(sections)
