#! /usr/bin/python3

source = "/usr/include/GL/glcorearb.h"
desthpp = "src/graphic/opengl/gl.hpp"
destcpp = "src/graphic/opengl/gl.cpp"



class func:
    f_type = ''
    f_name = ''

    def __init__(self, t, n):
        self.f_type = t
        self.f_name = n

    def definition(self):
        return "GLAPI %s %s;" % (self.f_type, self.f_name)

    def definition_null(self):
        return "%s %s = nullptr;" % (self.f_type, self.f_name)

    def assignment(self):
        return "    result = result && ({0} = get_function<{1}>(\"{0}\")) != nullptr;".format(self.f_name, self.f_type)


class section:
    name = ''
    functions = []

    def __init__(self, name, functions):
        self.name = name
        self.functions = functions

    def start(self):
        return "#pragma region {0}\n\n#ifdef {0}\n\n".format(self.name)

    def end(self):
        return "\n\n#endif // {0}\n\n#pragma endregion\n\n".format(self.name)


def get_type(s):
    b = s.find("PFN");
    e = s.find("PROC)", b) + 4;
    return s[b:e]


def get_name(s):
    b = s.find("gl");
    e = s.find(" (");
    return s[b:e]


sections = []

file = open(source, "r")

s = section("",[])
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
            s.functions[f_counter].f_name = get_name(l)
            f_counter += 1

        elif l.startswith("#endif"):
            if (s.name == "GL_VERSION_3_2") and (len(s.functions) <= 0):
                continue
            else:
                in_section = False
                sections.append(s)

file.close()


hppheader = "/// @file\n" \
"/// @brief OpneGL functions wrapper.\n" \
"/// @author Fedorov Alexey\n" \
"/// @date 21.06.2018\n" \
"\n" \
"#ifndef FRAMEWORK_GRAPHIC_OPENGL_GL_HPP\n" \
"#define FRAMEWORK_GRAPHIC_OPENGL_GL_HPP\n" \
"\n" \
"#include <GL/glcorearb.h>\n" \
"\n" \
"namespace framework::graphic::gl\n" \
"{\n" \
"/// Initialize all GL functions\n" \
"bool init();\n\n"

hppfooter = "} // namespace framework::graphic::gl\n" \
"\n" \
"#endif\n"

hpp = open(desthpp, "w")

hpp.write(hppheader)

for s in sections:
    if len(s.functions) > 0:
        hpp.write(s.start())
        hpp.write("\n".join(x.definition() for x in s.functions))
        hpp.write(s.end())

hpp.write(hppfooter)

hpp.close()


cppheader = "/// @file\n" \
"/// @brief OpneGL functions wrapper.\n" \
"/// @author Fedorov Alexey\n" \
"/// @date 21.06.2018\n" \
"\n" \
"#include <graphic/opengl/gl.hpp>\n" \
"#include <graphic/opengl/gl_details.hpp>\n" \
"\n" \
"namespace\n" \
"{\n" \
"template <typename F>\n" \
"F get_function(const char* function_name)\n" \
"{\n" \
"    return reinterpret_cast<F>(framework::graphic::gl::details::get_function(function_name));\n" \
"}\n" \
"\n" \
"} // namespace\n" \
"\n" \
"namespace framework::graphic::gl\n" \
"{\n"

cppfooter = "} // namespace framework::graphic::gl\n"


cpp = open(destcpp, "w")

cpp.write(cppheader)

for s in sections:
    if len(s.functions) > 0:
        cpp.write(s.start())
        cpp.write("\n".join(x.definition_null() for x in s.functions))
        cpp.write("\n")
        cpp.write("\n")
        cpp.write("bool init_{0}()\n".format(s.name.lower()))
        cpp.write("{\n")
        cpp.write("    bool result = true;\n")
        cpp.write("\n")
        cpp.write("    // clang-format off\n")
        cpp.write("\n".join(x.assignment() for x in s.functions))
        cpp.write("\n")
        cpp.write("    // clang-format on\n")
        cpp.write("\n")
        cpp.write("    return result;\n")
        cpp.write("}")

        cpp.write(s.end())


cpp.write("#pragma region init\n")
cpp.write("\n")
cpp.write("bool init()\n")
cpp.write("{\n")
cpp.write("    bool result = true;\n")
cpp.write("\n")

for s in sections:
    if len(s.functions) > 0:
        cpp.write("#ifdef {0}\n".format(s.name))
        cpp.write("    result = result && init_{0}();\n".format(s.name.lower()))
        cpp.write("#endif\n")

cpp.write("    return result;\n")
cpp.write("}\n\n")
cpp.write("#pragma endregion\n\n")

cpp.write(cppfooter)

cpp.close()

