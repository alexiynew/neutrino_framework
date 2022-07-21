#! /usr/bin/python3

import subprocess
import json
import os

script_path = os.getcwd()

# Load the database and extract all files.
database = json.load(open(os.path.join(script_path, "build/compile_commands.json")))
files = set([entry['file'] for entry in database])

has_errors = False
for f in files:
    print(f)
    # Checks to add: ,cppcoreguidelines-*,misc-*,performance-*,portability-*,readability-*
    output = subprocess.call(["clang-tidy", f, "-p", "build", "-checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus*,concurrency-*", "--warnings-as-errors=*"])
    has_errors == has_errors or (output != 0)

exit(has_errors)
