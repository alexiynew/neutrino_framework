#! /usr/bin/python3

import subprocess
import os

script_path = os.getcwd()

pathes = [
    os.path.join(script_path, "neutrino"),
    os.path.join(script_path, "tests"),
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

def convert_line_endings(filename):
    # replacement strings
    WINDOWS_LINE_ENDING = b'\r\n'
    UNIX_LINE_ENDING = b'\n'

    with open(filename, 'rb') as open_file:
        content = open_file.read()

    content = content.replace(WINDOWS_LINE_ENDING, UNIX_LINE_ENDING)

    with open(filename, 'wb') as open_file:
        open_file.write(content)


def fix_encoding(filename):
    with open(filename, 'r', encoding='utf-8') as open_file:
        content = open_file.read()

    with open(filename, 'w', encoding='utf-8') as open_file:
        open_file.write(content)


files = list(filter(has_extension_filter(code_extensions), get_files(pathes)))

for f in files:
    print(f)
    fix_encoding(f)
    subprocess.call(["clang-format", "-style=file", "-i", f])
    convert_line_endings(f)
