
import subprocess
from string import Template


def enum_declaration(enum):
    type_map = {"": "int", "u": "unsigned int", "ull": "unsigned long long"}

    value_type = type_map[enum.type]

    value = enum.value
    if enum.value == "0xFFFFFFFF" and value_type == "int":
        value = "int({})".format(enum.value)

    result = "constexpr {} {} = {};".format(value_type, enum.name, value)

    return result


def command_declaration(command):
    params_str = ", ".join(p.string for p in command.params)
    return "{} {}({});".format(command.prototype.type, command.prototype.name, params_str)


def command_definition(command):

    params = ", ".join(p.string for p in command.params)
    args = ", ".join(p.name for p in command.params)

    void_types = ["void", "GLvoid", "VOID"]
    ret = "return" if command.prototype.type.strip() not in void_types else ""

    result = \
        "{type} {name} ({params})\n" \
        "{{\n" \
        "    {ret} {name}_ptr({args});\n" \
        "}}\n".format(type=command.prototype.type,
                      name=command.prototype.name, params=params, ret=ret, args=args)

    return result


def command_pointer_declaration(command):
    return "using {name}Ptr = std::add_pointer_t<decltype({name})>;".format(name=command.prototype.name)


def command_pointer_definition(command):
    return "{name}Ptr {name}_ptr = nullptr;".format(name=command.prototype.name)


def group_declaration(group):
    t = Template("\n"
                 "#pragma region ${name}\n"
                 "\n"
                 "${types}\n"
                 "\n"
                 "${enums}\n"
                 "\n"
                 "${commands}\n"
                 "\n"
                 "#pragma endregion\n")

    types = "\n".join(t.type_string for t in group.types)
    enums = "\n".join(enum_declaration(e) for e in group.enums)
    commands = "\n".join(command_declaration(c) for c in group.commands)

    return t.substitute(name=group.name, types=types, enums=enums, commands=commands)


def group_init_function(group):
    t = Template("bool init_${name}([[maybe_unused]] const GetFunction& get_function)\n"
                 "{\n"
                 "    bool result = false;\n"
                 "${func_body}"
                 "    return !result;\n"
                 "}\n"
                 )

    assignment = "\n".join("    result = ({name}_ptr = reinterpret_cast<{name}Ptr>(get_function(\"{name}\"))) == nullptr || result;".format(
        name=c.prototype.name) for c in group.commands)

    func_body = \
        "\n"\
        "    // clang-format off\n"\
        "{}\n"\
        "    // clang-format on\n"\
        "\n".format(assignment) if assignment else ""

    return t.substitute(name=group.name.lower(), func_body=func_body)


def group_pointers_declaration(group):
    t = Template("\n"
                 "#pragma region ${name}\n"
                 "\n"
                 "${types}\n"
                 "\n"
                 "${definition}\n"
                 "\n"
                 "${function}\n"
                 "\n"
                 "#pragma endregion\n")

    types = "\n".join(command_pointer_declaration(c) for c in group.commands)
    definition = "\n".join(command_pointer_definition(c)
                           for c in group.commands)

    return t.substitute(dict(name=group.name,
                             types=types,
                             definition=definition,
                             function=group_init_function(group)))


def group_definition(group):
    t = Template("\n"
                 "#pragma region ${name}\n"
                 "\n"
                 "${commands}\n"
                 "\n"
                 "#pragma endregion\n")

    commands = "\n".join(command_definition(c) for c in group.commands)

    return t.substitute(name=group.name, commands=commands)


class Used:
    def __init__(self):
        self.types = []
        self.enums = []
        self.commands = []


class Remove:
    def __init__(self):
        self.enums = []
        self.commands = []


class Group:
    def __init__(self, feature, reg, data, used, remove):
        self.name = feature.name
        self.types = []
        self.enums = []
        self.commands = []

        for require in feature.require:
            if require.profile == "" or require.profile == data.PROFILE:
                self.enums.extend(
                    (reg.enums[e] for e in require.enum_names if e not in remove.enums and e not in used.enums))

                self.commands.extend(
                    (reg.commands[c] for c in require.command_names if c not in remove.commands and c not in used.commands))

        self.enums = list(dict.fromkeys(self.enums).keys())

        self.commands = list(dict.fromkeys(self.commands).keys())

        types = []

        for require in feature.require:
            if require.profile == "" or require.profile == data.PROFILE:
                types.extend((reg.types[t] for t in require.type_names))

        for c in self.commands:
            if c.prototype.requires in reg.types:
                types.append(reg.types[c.prototype.requires])

            for param in c.params:
                if param.requires in reg.types:
                    types.append(reg.types[param.requires])

        to_add = []
        for t in types:
            if t.requires in reg.types:
                to_add.append(reg.types[t.requires])

        to_add.extend(types)
        types = to_add

        types = list(dict.fromkeys(types).keys())

        self.types.extend(
            (t for t in types if t not in used.types and t.type_string))


class Generator:
    def __init__(self, reg, data):
        self.data = data

        remove = Remove()
        for f in reg.features:
            if f.api == self.data.API:
                for r in f.remove:
                    if r.profile == "" or r.profile == self.data.PROFILE:
                        remove.enums.extend(r.enum_names)
                        remove.commands.extend(r.command_names)

        used = Used()

        self.features = []
        for f in reg.features:
            if f.api == self.data.API:
                group = Group(f, reg, data, used, remove)
                self.features.append(group)
                used.types.extend(group.types)
                used.enums.extend((e.name for e in group.enums))
                used.commands.extend(c.prototype.name for c in group.commands)

        self.extensions = []
        for e in reg.extensions:
            if self.data.SUPPORTED in e.supported:
                group = Group(e, reg, data, used, remove)
                self.extensions.append(group)
                used.types.extend(group.types)
                used.enums.extend((e.name for e in group.enums))
                used.commands.extend(c.prototype.name for c in group.commands)

    def generate_header(self):
        t = Template("/// @file\n"
                     "/// @brief ${brief}\n"
                     "/// @author Fedorov Alexey\n"
                     "/// @date ${date}\n"
                     "\n"
                     "${license}"
                     "\n"
                     "#ifndef ${include_guard}\n"
                     "#define ${include_guard}\n"
                     "\n"
                     "${includes}\n"
                     "\n"
                     "${typedefs}"
                     "\n"
                     "namespace ${namespace}\n"
                     "{\n"
                     "${features}\n"
                     "\n"
                     "${extensions}\n"
                     "\n"
                     "enum class Feature\n"
                     "{\n"
                     "${features_enum}\n"
                     "};\n"
                     "\n"
                     "enum class Extension\n"
                     "{\n"
                     "${extensions_enum}\n"
                     "};\n"
                     "\n"
                     "using VoidFunctionPtr = void (*)();\n"
                     "using GetFunction     = std::function<VoidFunctionPtr(const char*)>;\n"
                     "\n"
                     "void ${init_function_name}(const GetFunction& get_function);\n"
                     "\n"
                     "bool is_supported(Feature feature);\n"
                     "bool is_supported(Extension extension);\n"
                     "\n"
                     "} // namespace ${namespace}\n"
                     "\n"
                     "#endif\n"
                     )

        includes = "\n".join("#include <{0}>".format(i)
                             for i in self.data.HEADER_INCLUDE_FILES)

        features = "\n".join(group_declaration(f) for f in self.features)
        features_enum = "\n".join("{},".format(f.name) for f in self.features)

        extensions = "\n".join(group_declaration(f) for f in self.extensions)
        extensions_enum = "\n".join("{},".format(f.name)
                                    for f in self.extensions)

        hpp = open(self.data.DESTHPP, "w")
        hpp.write(t.substitute(brief=self.data.BRIEF,
                               date=self.data.DATE,
                               license=self.data.LICENSE,
                               include_guard=self.data.INCLUDE_GUARD,
                               namespace=self.data.NAMESPACE,
                               init_function_name=self.data.INIT_FUNCTION_NAME,
                               includes=includes,
                               typedefs=self.data.TYPEDEFS,
                               features=features,
                               features_enum=features_enum,
                               extensions=extensions,
                               extensions_enum=extensions_enum))
        hpp.close()

    def generate_source(self):
        t = Template("/// @file\n"
                     "/// @brief ${brief}\n"
                     "/// @author Fedorov Alexey\n"
                     "/// @date ${date}\n"
                     "\n"
                     "${license}"
                     "\n"
                     "${cpp_includes}\n"
                     "\n"
                     "namespace\n"
                     "{\n"
                     "\n"
                     "using namespace ${namespace};"
                     "\n"
                     "${feture_declarations}"
                     "\n"
                     "${extension_declarations}"
                     "\n"
                     "std::once_flag init_flag;\n"
                     "\n"
                     "${feature_cache}\n"
                     "\n"
                     "${extension_cache}\n"
                     "\n"
                     "void init_features([[maybe_unused]] const GetFunction& get_function)\n"
                     "{\n"
                     "    // clang-format off\n"
                     "${init_features}\n"
                     "    // clang-format on\n"
                     "}\n"
                     "\n"
                     "void init_extensions([[maybe_unused]] const GetFunction& get_function)\n"
                     "{\n"
                     "    // clang-format off\n"
                     "${init_extensions}\n"
                     "    // clang-format on\n"
                     "}\n"
                     "\n"
                     "} // namespace\n"
                     "\n"
                     "namespace ${namespace}\n"
                     "{\n"
                     "\n"
                     "${feature_definitions}\n"
                     "\n"
                     "${extension_definitions}\n"
                     "\n"
                     "void ${init_function_name}(const GetFunction& get_function)\n"
                     "{\n"
                     "    std::call_once(init_flag, [&get_function]() {\n"
                     "        init_features(get_function);\n"
                     "        init_extensions(get_function);\n"
                     "    });\n"
                     "}\n"
                     "\n"
                     "${is_supported_feature}\n"
                     "\n"
                     "${is_supported_extension}\n"
                     "\n"
                     "} // ${namespace}\n"
                     )

        cpp_includes = "\n".join("#include <{}>".format(inc)
                                 for inc in self.data.CPP_INCLUDE_FILES)

        feture_declarations = "\n".join(
            group_pointers_declaration(g) for g in self.features)

        extension_declarations = "\n".join(
            group_pointers_declaration(g) for g in self.extensions)

        features_count = sum(1 for e in self.features)
        feature_cache = "bool feature_cache[{}] = {{}};\n".format(
            features_count) if features_count else ""

        is_supported_feature = \
            "bool is_supported(Feature feature)\n"\
            "{\n"\
            "    return feature_cache[static_cast<int>(feature)];\n"\
            "}\n" if features_count else ""

        extensions_count = sum(1 for e in self.extensions)
        extension_cache = "bool extension_cache[{}] = {{}};\n".format(
            extensions_count) if extensions_count else ""

        is_supported_extension = \
            "bool is_supported(Extension extension)\n"\
            "{\n"\
            "    return extension_cache[static_cast<int>(extension)];\n"\
            "}\n" if extensions_count else ""

        init_features = "\n".join("    feature_cache[static_cast<int>(Feature::{})] = init_{}(get_function);".format(
            g.name, g.name.lower()) for g in self.features)

        init_extensions = "\n".join("    extension_cache[static_cast<int>(Extension::{})] = init_{}(get_function);".format(
            g.name, g.name.lower()) for g in self.extensions)

        feature_definitions = "\n".join(
            group_definition(g) for g in self.features)

        extension_definitions = "\n".join(
            group_definition(g) for g in self.extensions)

        d = dict(brief=self.data.BRIEF,
                 date=self.data.DATE,
                 license=self.data.LICENSE,
                 namespace=self.data.NAMESPACE,
                 init_function_name=self.data.INIT_FUNCTION_NAME,
                 cpp_includes=cpp_includes,
                 feture_declarations=feture_declarations,
                 extension_declarations=extension_declarations,
                 feature_cache=feature_cache,
                 extension_cache=extension_cache,
                 init_features=init_features,
                 init_extensions=init_extensions,
                 feature_definitions=feature_definitions,
                 extension_definitions=extension_definitions,
                 is_supported_feature=is_supported_feature,
                 is_supported_extension=is_supported_extension)

        cpp = open(self.data.DESTCPP, "w")
        cpp.write(t.substitute(d))
        cpp.close()


def generate(reg, data):
    gen = Generator(reg, data)

    gen.generate_header()
    gen.generate_source()

    subprocess.call(["clang-format", "-style=file", "-i", data.DESTHPP])
    subprocess.call(["clang-format", "-style=file", "-i", data.DESTCPP])
