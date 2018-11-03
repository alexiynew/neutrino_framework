#!/usr/bin/python3

import re
from string import Template


class Function:
    type = ''
    name = ''

    def __init__(self, t, n):
        self.type = t
        self.name = n


class Section:
    name = ''
    lower_name = ''
    functions = []

    def __init__(self, name, functions):
        self.name = name
        self.lower_name = name.lower()
        self.functions = functions


def get_sections(dictionary):
    sections = []

    src_file = open(dictionary['source'], "r")

    groups = re.findall(dictionary['group_regex'], src_file.read(), re.S)
    groups = [g for g in groups if not g[0] in dictionary['exclude']]

    for g in groups:
        types = re.findall(dictionary['type_regex'], g[1])
        names = re.findall(dictionary['name_regex'], g[1])

        functions = (list(map(lambda f: Function(f[0], f[1]), list(zip(types, names)))))
        functions = [f for f in functions if not(f.name in dictionary['exclude'])
                     and not f.type in dictionary['exclude']]

        sections.append(Section(g[0], functions))

    src_file.close()

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


def generate_header(sections, dictionary):
    t = "/// @file\n" \
        "/// @brief {brief}\n" \
        "/// @author Fedorov Alexey\n" \
        "/// @date {date}\n" \
        "\n" \
        "{license}" \
        "\n" \
        "#ifndef {include_guard}\n" \
        "#define {include_guard}\n" \
        "\n" \
        "{includes}\n" \
        "\n" \
        "namespace framework::opengl\n" \
        "{{\n" \
        "{is_extension_supported}" \
        "\n" \
        "{declarations}" \
        "\n" \
        "{init_function_description}\n" \
        "void {init_function_name}();\n" \
        "\n" \
        "}} // namespace framework::opengl\n" \
        "\n" \
        "#endif\n"

    is_extension_supported = "\n".join(
        "extern bool {s.lower_name}_supported;".format(s=s) for s in sections)

    includes = "\n".join("#include <{0}>".format(i)
                         for i in dictionary['include_files'])

    hpp = open(dictionary['desthpp'], "w")
    hpp.write(t.format(brief=dictionary['brief'],
                       date=dictionary['date'],
                       license=dictionary['license'],
                       include_guard=dictionary['include_guard'],
                       includes=includes,
                       is_extension_supported=is_extension_supported,
                       declarations=generate_declarations(sections),
                       init_function_description=dictionary['init_function_description'],
                       init_function_name=dictionary['init_function_name']))
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


def generate_init_definitions(sections, dictionary):
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
                 "${init_extensions_begin}\n"
                 "    // clang-format off\n"
                 "${assignment_extensions}\n"
                 "    // clang-format on\n"
                 "\n"
                 "${init_extensions_end}\n"
                 "}\n"
                 "\n"
                 "} // namespace\n"
                 "\n"
                 "#pragma endregion\n")

    assignment_extensions = "\n".join("    framework::opengl::{0}_supported = init_{0}();".format(
        s.lower_name) for s in sections)

    return e.substitute(init_functions=init_functions,
                        init_extensions_begin=dictionary['init_extensions_begin'],
                        assignment_extensions=assignment_extensions,
                        init_extensions_end=dictionary['init_extensions_end'])


def generate_source(sections, dictionary):
    t = Template("/// @file\n"
                 "/// @brief ${brief}\n"
                 "/// @author Fedorov Alexey\n"
                 "/// @date ${date}\n"
                 "\n"
                 "${license}"
                 "\n"
                 "#include <array>\n"
                 "#include <mutex>\n"
                 "\n"
                 "#include <common/types.hpp>\n"
                 "#include <opengl/details/gl_details.hpp>\n"
                 "#include <${header_file}>\n"
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
                 "${is_extension_supported}"
                 "\n"
                 "${null_definitions}"
                 "\n"
                 "void ${init_function_name}()\n"
                 "{\n"
                 "    std::call_once(init_flag, []() { ::init_extensions(); });\n"
                 "}\n"
                 "\n"
                 "} // namespace framework::opengl\n"
                 "\n"
                 "${init_definitions}")

    d = dict(brief=dictionary['brief'],
             date=dictionary['date'],
             license=dictionary['license'],
             header_file=dictionary['header_file'],
             is_extension_supported="\n".join(
                 "bool {s.lower_name}_supported = false;".format(s=s) for s in sections) + "\n",
             init_declarations=generate_init_declarations(sections),
             null_definitions=generate_null_definitions(sections),
             init_function_name=dictionary['init_function_name'],
             init_definitions=generate_init_definitions(sections, dictionary))

    cpp = open(dictionary['destcpp'], "w")
    cpp.write(t.substitute(d))
    cpp.close()


def generate(dictionary):
    sections = [s for s in get_sections(dictionary) if len(s.functions) > 0]

    generate_header(sections, dictionary)
    generate_source(sections, dictionary)
