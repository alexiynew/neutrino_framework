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
    output = subprocess.call(["clang-tidy", f, "-p", "build"])

    has_errors = (int(output) != 0)

    if has_errors:
        break

exit(has_errors)
