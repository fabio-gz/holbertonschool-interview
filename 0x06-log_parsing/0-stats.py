#!/usr/bin/python3
'a script that reads stdin line by line and computes metrics size'
import sys
import traceback


def info(size, dicti):
    print("File size: {}".format(size))
    for k in sorted(codes.keys()):
        if codes[k] != 0:
            print("{}: {}".format(k, codes[k]))

size = 0
c = 1
codes = {'200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0}

try:
    for l in (sys.stdin):
        try:
            c += 1
            size += int(l.split()[-1])
            if c % 10 == 0:
                info(size, codes)
        except:
            pass
        try:
            if str(l.split()[-2]) in codes.keys():
                codes[str(l.split()[-2])] += 1
        except:
            pass
    info(size, codes)

except KeyboardInterrupt:
    info(size, codes)
    traceback.print_exc()
