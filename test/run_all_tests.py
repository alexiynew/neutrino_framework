#!/usr/bin/python
import getopt
import os
import sys
import time
from subprocess import Popen, PIPE


test_dir = os.path.dirname(os.path.realpath(__file__))
folder_test_script = 'run.py'

verbose = False


class Colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


class Test:
    name = ''
    executable = ''
    log = ''
    success = False
    elapsed = 0

    def __init__(self, name, executable):
        self.name = name
        self.executable = executable

    def __str__(self):
        return "Test\n name: {}, executable: {}".format(self.name, self.executable)

    def __repr__(self):
        return "Test()"

    def run(self):
        elapsed = 0
        if os.path.isfile(self.executable):
            start = time.time()
            process = Popen([self.executable], stdout=PIPE, stdin=PIPE, stderr=PIPE)
            self.log = process.communicate()[0].decode("utf-8")
            end = time.time()
            self.elapsed = end - start
            self.success = process.returncode == 0
        else:
            self.success = False
            self.log = "File {} not exists.".format(self.executable)


def run_tests(test_list):

    start = time.time()
    tests_count = 0;
    passed_count = 0;
    for pack in test_list:
        print(pack)
        print('-' * 60)
        for test in test_list[pack]:

            tests_count += 1

            test.run()

            if test.success:
                print("    {:.<50} ".format(test.name + " ") + Colors.OKGREEN + "OK" + Colors.ENDC + " {:.2f}s".format(test.elapsed))
            else:
                print("    {:.<50} ".format(test.name + " ") + Colors.FAIL + "FAIL" + Colors.ENDC)

            if not test.success or verbose:
                log = "        ".join(test.log.splitlines(True))
                log = "        " + log
                if log.strip():
                    print(log)

            passed_count += test.success

    end = time.time()
    elapsed = end - start
    print('-' * 60)
    passed_string = "Passed {}/{}".format(passed_count, tests_count)
    print("{:<54} {:.2f}s".format(passed_string, elapsed))

    return tests_count - passed_count


def get_tests(path):
    packs = os.listdir(path)
    this_file = os.path.basename(__file__)
    packs = [elem for elem in packs if elem != this_file]
    packs.sort()

    test_list = {}
    for pack in packs:
        pack_dir = os.path.join(path, pack)
        if (os.path.isdir(pack_dir)):
            test_files = os.listdir(pack_dir)
            test_files.sort()

            test_list[pack] = []

            for test_name in test_files:
                test_name = test_name.strip()
                executable = os.path.join(test_dir, pack_dir, test_name)

                if os.path.isdir(executable):
                    executable = os.path.join(executable, folder_test_script)

                test_list[pack].append(Test(test_name, executable))

    return test_list


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

exit(run_tests(get_tests(test_dir)))
