#!/usr/bin/python
import os
from subprocess import Popen, PIPE

test_dir = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'test')
folder_test_script = 'run.py'


class Test:
    name = ''
    executable = ''
    log = ''
    success = False

    def __init__(self, name, executable):
        self.name = name
        self.executable = executable


def run_test(test: Test) -> bool:
    if os.path.isfile(test.executable):
        process = Popen([test.executable], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        test.log = process.communicate()[0].decode("utf-8")
        test.success = process.returncode == 0
    else:
        test.success = False
        test.log = "File {} not exists.".format(test.executable)

    if test.success:
        print("{:<50} OK 0.0s".format(test.name))
    else:
        print("{:<50} FAIL".format(test.name))
        print(test.log)

    return test.success


def run_folder_test(test: Test) -> bool:
    test.executable = os.path.join(test.executable, folder_test_script)
    return run_test(test)


def run_tests(test_list):
    passed_count = 0
    for test_name in test_list:
        test_name = test_name.strip()
        executable = os.path.join(test_dir, test_name.strip())
        test = Test(test_name, executable)
        if os.path.isdir(test.executable):
            passed_count += run_folder_test(test)
        else:
            passed_count += run_test(test)

    print()
    print('-' * 50)
    print("    Passed {}/{}".format(passed_count, len(test_list)))


def get_tests(path):
    files = os.listdir(path)
    files.sort()
    return files


run_tests(get_tests(test_dir))
