#!/usr/bin/python3
'a script that reads stdin line by line and computes metrics'
import sys


def info(size, dicti):
    print("File size: {}".format(size))
    for k in sorted(codes.keys()):
        if codes[k] != 0:
            print("{}: {}".format(k, codes[k]))

size = 0
codes = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}

try:
    for c, l in enumerate(sys.stdin, start=1):
        try:
            size += int(l.split()[-1])
        except:
            pass
        try:
            if str(l.split()[-2]) in codes.keys():
                codes[str(l.split()[-2])] += 1
        except:
            pass
        if c % 10 == 0:
            info(size, codes)
    info(size, codes)

except KeyboardInterrupt:
    info(size, codes)
    raise
