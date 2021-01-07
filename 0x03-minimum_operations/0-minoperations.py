#!/usr/bin/python3
"""
Minimun operations nedeed
"""


def minOperations(n):
    if (n < 2):
        return 0

    op = 0
    for i in range(2, n):
        while(n % i == 0):
            op += i
            n = n/i

    return op
