#!/usr/bin/python
from numpy import linalg as LA
from subprocess import Popen, PIPE, STDOUT
import numpy as NP
import sys
import os

test_dir = os.path.dirname(os.path.realpath(__file__))
test_name = test_dir.split('/')[-1]
test_path = '{}/{}'.format(test_dir, test_name)

def run_test(data):
    if os.path.isfile(test_path):
        test = Popen([test_path], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        return test.communicate(input=data)[0]
    else:
        print "file {} not exists".format(test_path)
        sys.exit(1)

def as_string(m):
    return ('\n'.join([''.join(['{:20}'.format(item) for item in row]) for row in m]))

for r in range(2, 5):
    for c in range(2, 5):
        for k in range(2, 5):
            a = NP.random.uniform(0, 100, (r, c))
            b = NP.random.uniform(0, 100, (c, k))
            res = NP.matrix(a) * NP.matrix(b)

            data = '{} {}\n{}\n'.format(r, c, as_string(a)) + '{} {}\n{}'.format(c, k, as_string(b))

            out = run_test(data)

            out_m = NP.matrix(out)


            if not NP.allclose(res, out_m) :
                print data
                print "------------------"
                print res
                print "------------------"
                print out
                sys.exit(1)

for r in range(2, 5):
    for c in range(2, 5):
        m = NP.random.uniform(0, 100, (r, c))
        v1 = NP.random.uniform(0, 100, (c, 1))
        v2 = NP.random.uniform(0, 100, (1, r))
        res1 = NP.matrix(m) * NP.matrix(v1)
        res2 = NP.matrix(v2) * NP.matrix(m)

        data1 = '{} {}\n{}\n'.format(r, c, as_string(m)) + '{} {}\n{}'.format(c, 1, as_string(v1))
        data2 = '{} {}\n{}\n'.format(1, r, as_string(v2)) + '{} {}\n{}'.format(r, c, as_string(m))

        out1 = run_test(data1)
        out_m1 = NP.matrix(out1)

        if not NP.allclose(res1, out_m1.transpose()) :
                print data1
                print "------------------"
                print res1
                print "------------------"
                print out_m1
                sys.exit(1)

        out2 = run_test(data2)
        out_m2 = NP.matrix(out2)

        if not NP.allclose(res2, out_m2) :
                print data2
                print "------------------"
                print res2
                print "------------------"
                print out_m2
                sys.exit(1)

