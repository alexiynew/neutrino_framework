#! /usr/bin/python3

import re
from string import Template

source = "./dependencies/GL/glcorearb.h"
desthpp = "./src/opengl/gl.hpp"
destcpp = "./src/opengl/gl.cpp"


class func:
    type = ''
    name = ''

    def __init__(self, t, n):
        self.type = t
        self.name = n


class section:
    name = ''
    functions = []

    def __init__(self, name, functions):
        self.name = name
        self.functions = functions


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


def get_type(s):
    b = s.find("PFN")
    e = s.find("PROC)", b) + 4
    return s[b:e]


def get_name(s):
    b = s.find("gl")
    e = s.find(" (")
    return s[b:e]


def get_sections():
    sections = []

    file = open(source, "r")

    s = section("", [])
    in_section = False
    f_counter = 0

    for l in file.readlines():
        if l.startswith("#ifndef"):
            name = l.split()[-1]

            if name != "__glcorearb_h_" and name != "GLEXT_64_TYPES_DEFINED":
                in_section = True
                s = section(name, [])
                f_counter = 0
                continue
            else:
                continue

        if in_section:
            if l.startswith("typedef") and ("APIENTRYP" in l):
                s.functions.append(func(get_type(l), ""))

            elif l.startswith("GLAPI"):
                s.functions[f_counter].name = get_name(l)
                f_counter += 1

            elif l.startswith("#endif"):
                if (s.name == "GL_VERSION_3_2") and (len(s.functions) <= 0):
                    continue
                else:
                    in_section = False
                    sections.append(s)

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
                 functions="\n".join("extern {0} {1};".format(f.type, f.name) for f in s.functions))

        result += t.substitute(d)

    return result


def generate_header(sections):
    t = Template("/// @file\n"
                 "/// @brief OpneGL functions wrapper.\n"
                 "/// @author Fedorov Alexey\n"
                 "/// @date 21.06.2018\n"
                 "\n"
                 "${license}"
                 "\n"
                 "#ifndef FRAMEWORK_OPENGL_GL_HPP\n"
                 "#define FRAMEWORK_OPENGL_GL_HPP\n"
                 "\n"
                 "#include <GL/glcorearb.h>\n"
                 "\n"
                 "namespace framework::opengl\n"
                 "{\n"
                 "${enum_version}"
                 "\n"
                 "${enum_extension}"
                 "\n"
                 "/// Initialize GL functions\n"
                 "void init();\n"
                 "\n"
                 "/// Checks if functions is supported\n"
                 "bool is_supported(version name);\n"
                 "\n"
                 "/// Checks if functions is supported\n"
                 "bool is_supported(extension name);\n"
                 "${declarations}"
                 "\n"
                 "} // namespace framework::opengl\n"
                 "\n"
                 "#endif\n")

    d = dict(license=license,
             enum_version="enum class version \n{\n" + ",\n".join(
                 "    {0}".format(s.name.lower()) for s in list(filter(lambda s: "GL_VERSION" in s.name, sections))) + "\n};\n",
             enum_extension="enum class extension \n{\n" + ",\n".join(
                 "    {0}".format(s.name.lower()) for s in list(filter(lambda s: not ("GL_VERSION" in s.name), sections))) + "\n};\n",
             declarations=generate_declarations(sections))

    hpp = open(desthpp, "w")
    hpp.write(t.substitute(d))
    hpp.close()


def generate_is_suported_versions_flags(sections):
    versions_count = len(
        list(filter(lambda s: "GL_VERSION" in s.name, sections)))

    return "std::array<bool, {0}> is_supported_version = {{false}};\n".format(versions_count)


def generate_is_suported_extensions_flags(sections):
    extensions_count = len(
        list(filter(lambda s: not ("GL_VERSION" in s.name), sections)))

    return "std::array<bool, {0}> is_supported_extension = {{false}};\n".format(extensions_count)


def generate_init_declarations(sections):
    result = "#pragma region init_declarations\n\n"

    result += "\n".join("bool init_{0}();".format(s.name.lower())
                        for s in sections)

    result += "\n"
    result += "\n"
    result += "void init_versions();\n"
    result += "void init_extensions();\n"
    result += "\n"
    result += "#pragma endregion\n"

    return result


def generate_definitions(sections):
    t = Template("#pragma region ${name}\n"
                 "\n"
                 "${null_definition}"
                 "\n"
                 "\n"
                 "bool init_${lower_name}()\n"
                 "{\n"
                 "    bool result = true;\n"
                 "\n"
                 "    // clang-format off\n"
                 "${assignment}"
                 "\n"
                 "    // clang-format on\n"
                 "\n"
                 "    return result;\n"
                 "}\n"
                 "\n"
                 "#pragma endregion\n")

    result = ""
    for s in sections:
        d = dict(name=s.name,
                 lower_name=s.name.lower(),
                 null_definition="\n".join("{0} {1} = nullptr;".format(
                     f.type, f.name) for f in s.functions),
                 assignment="\n".join("    result = result && ({0} = get_function<{1}>(\"{0}\")) != nullptr;".format(f.name, f.type) for f in s.functions))

        result += t.substitute(d) + "\n"

    return result


def generate_init_implementation(sections):
    t = Template("void init()\n"
                 "{\n"
                 "    std::call_once(init_flag, []() {\n"
                 "        init_versions();\n"
                 "        init_extensions();\n"
                 "    });\n"
                 "}\n"
                 "\n"
                 "void init_versions()\n"
                 "{\n"
                 "${assignment_versions}\n"
                 "}\n"
                 "\n"
                 "void init_extensions()\n"
                 "{\n"
                 "    // clang-format off\n"
                 "${assignment_extensions}\n"
                 "    // clang-format on\n"
                 "}\n")

    assignment_versions = "\n".join("    is_supported_version[static_cast<int32>(version::{0})] = init_{0}();".format(
        s.name.lower()) for s in list(filter(lambda s: "GL_VERSION" in s.name, sections)))

    assignment_extensions = "\n".join("    is_supported_extension[static_cast<int32>(extension::{0})] = init_{0}();".format(
        s.name.lower()) for s in list(filter(lambda s: not ("GL_VERSION" in s.name), sections)))

    return t.substitute(assignment_versions=assignment_versions, assignment_extensions=assignment_extensions)


def generate_source(sections):
    t = Template("/// @file\n"
                 "/// @brief OpneGL functions wrapper.\n"
                 "/// @author Fedorov Alexey\n"
                 "/// @date 21.06.2018\n"
                 "\n"
                 "${license}"
                 "\n"
                 "#include <array>\n"
                 "#include <mutex>\n"
                 "\n"
                 "#include <common/types.hpp>\n"
                 "#include <opengl/details/gl_details.hpp>\n"
                 "#include <opengl/gl.hpp>\n"
                 "\n"
                 "namespace\n"
                 "{\n"
                 "std::once_flag init_flag;\n"
                 "\n"
                 "${is_supported_version_flags}"
                 "${is_supported_extensions_flags}"
                 "\n"
                 "template <typename F>\n"
                 "F get_function(const char* function_name)\n"
                 "{\n"
                 "    return reinterpret_cast<F>(framework::opengl::details::get_function(function_name));\n"
                 "}\n"
                 "\n"
                 "} // namespace\n"
                 "\n"
                 "namespace framework::opengl\n"
                 "{\n"
                 "${init_declarations}"
                 "\n"
                 "${definitions}"
                 "${init_implementation}"
                 "\n"
                 "bool is_supported(version name)\n"
                 "{\n"
                 "    return is_supported_version[static_cast<int32>(name)];\n"
                 "}\n"
                 "\n"
                 "bool is_supported(extension name)\n"
                 "{\n"
                 "    return is_supported_extension[static_cast<int32>(name)];\n"
                 "}\n"
                 "\n"
                 "} // namespace framework::opengl\n")

    d = dict(license=license,
             is_supported_version_flags=generate_is_suported_versions_flags(
                 sections),
             is_supported_extensions_flags=generate_is_suported_extensions_flags(
                 sections),
             init_declarations=generate_init_declarations(sections),
             definitions=generate_definitions(sections),
             init_implementation=generate_init_implementation(sections))

    cpp = open(destcpp, "w")
    cpp.write(t.substitute(d))
    cpp.close()


sections = list(filter(lambda s: len(s.functions) > 0, get_sections()))

generate_header(sections)
generate_source(sections)
