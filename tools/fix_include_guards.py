#! /usr/bin/python3

import re
import os

script_path = os.getcwd()

pathes = [
    os.path.join(script_path, "neutrino"),
    os.path.join(script_path, "examples"),
    os.path.join(script_path, "tests"),
]

code_extensions = [
    "h", "hh", "hpp", "hxx",
]


# TODO: Add lint for order of words in declaration of static constexpr, should be in this order 
# TODO: Add lint for enum class names, should be in CamelCase
# TODO: Add lint for classes and structs names, should be in CamelCase

def has_extension_filter(extensions):
    def check_extension(filename):
        _, ext = os.path.splitext(filename)
        return ext[1:] in extensions
    return check_extension


def get_files(pathes_list):
    files = []

    for p in pathes_list:
        for (dirpath, dirnames, filenames) in os.walk(p):
            for f in filenames:
                files.append(os.path.join(dirpath, f))

    return files


def include_gurad(filepath):
    t = os.path.relpath(filepath, script_path)
    t = os.path.join(*(t.split(os.path.sep)[1:]))
    t = t.replace('.', '_').replace('/', '_').replace('\\', '_').split('_')
    t = list(filter(lambda s: len(s) > 0, t))
    return '_'.join(s.upper() for s in t)


def replace_guard(data, guard):
    new_guard = "#ifndef {0}\n#define {0}\n".format(guard)

    data = re.sub(
        r'#ifndef\s(?P<g>[a-zA-Z_\\]*)\r?\n#define\s\1\r?\n', new_guard, data)
    return data


files = list(filter(has_extension_filter(code_extensions), get_files(pathes)))


for header in files:
    print(header)

    f = open(header, 'r')
    filedata = f.read()
    f.close()

    guard = include_gurad(header)

    newdata = replace_guard(filedata, guard)

    f = open(header, 'w')
    f.write(newdata)
    f.close()
