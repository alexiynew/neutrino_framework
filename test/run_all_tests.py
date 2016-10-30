#!/usr/bin/python3
import getopt
import os
import sys
import time
from subprocess import Popen, PIPE


test_dir = os.path.dirname(os.path.realpath(__file__))
folder_test_script = 'run.py'

verbose = False


class Test:
    name = ''
    executable = ''
    log = ''
    success = False

    def __init__(self, name, executable):
        self.name = name
        self.executable = executable


class Colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def run_test(test: Test) -> bool:
    elapsed = 0
    if os.path.isfile(test.executable):
        start = time.time()
        process = Popen([test.executable], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        test.log = process.communicate()[0].decode("utf-8")
        end = time.time()
        elapsed = end - start
        test.success = process.returncode == 0
    else:
        test.success = False
        test.log = "File {} not exists.".format(test.executable)

    if test.success:
        print("{:<50} ".format(test.name) + Colors.OKGREEN + "OK" + Colors.ENDC + " {:.2f}s".format(elapsed))
    else:
        print("{:<50} ".format(test.name) + Colors.FAIL + "FAIL" + Colors.ENDC)

    if not test.success or verbose:
        print(test.log)

    return test.success


def run_folder_test(test: Test) -> bool:
    test.executable = os.path.join(test.executable, folder_test_script)
    return run_test(test)


def run_tests(test_list):
    start = time.time()
    passed_count = 0
    for test_name in test_list:
        test_name = test_name.strip()
        executable = os.path.join(test_dir, test_name.strip())
        test = Test(test_name, executable)
        if os.path.isdir(test.executable):
            passed_count += run_folder_test(test)
        else:
            passed_count += run_test(test)

    end = time.time()
    elapsed = end - start
    print()
    print('-' * 60)
    passed_string = "    Passed {}/{}".format(passed_count, len(test_list))
    print("{:<50} {:.2f}s".format(passed_string, elapsed))


def get_tests(path):
    files = os.listdir(path)
    files.sort()
    this_file = os.path.basename(__file__)
    files = [elem for elem in files if elem != this_file]
    return files


def show_help():
    print("-v Verbose output")


def parse_args(argv):
    try:
        opts, args = getopt.getopt(argv, "hv")
    except getopt.GetoptError:
        sys.exit(2)

    for opt, arg in opts:
        if opt == '-h':
            show_help()
            sys.exit(0)
        elif opt == '-v':
            global verbose
            verbose = True


parse_args(sys.argv[1:])

run_tests(get_tests(test_dir))
