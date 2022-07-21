#! /usr/bin/python3

import subprocess
import os

script_path = os.getcwd()

pathes = [
    os.path.join(script_path, "neutrino/common"),
    os.path.join(script_path, "neutrino/game_core"),
    #os.path.join(script_path, "neutrino/graphics"),
    os.path.join(script_path, "neutrino/log"),
    os.path.join(script_path, "neutrino/math"),
    os.path.join(script_path, "neutrino/profiler"),
    #os.path.join(script_path, "neutrino/system"),
    os.path.join(script_path, "neutrino/unit_test"),
    #os.path.join(script_path, "example"),
    #os.path.join(script_path, "test"),
]

code_extensions = [
    "c", "cc", "cpp", "cxx",
    "h", "hh", "hpp", "hxx",
    "m", "mm",
]


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


files = list(filter(has_extension_filter(code_extensions), get_files(pathes)))


has_errors = False
for f in files:
    print(f)
    # Checks to add: ,cppcoreguidelines-*,misc-*,performance-*,portability-*,readability-*
    output = subprocess.call(["clang-tidy", f, "-p", "build", "-checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus*,concurrency-*", "--warnings-as-errors=*"])
    has_errors == has_errors or (output != 0)

exit(has_errors)
