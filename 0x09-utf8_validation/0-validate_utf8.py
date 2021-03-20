#!/usr/bin/python3
"""check if it is valid UTF-8"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    bytes_num = 0

    for i in data:
        binary = format(i, '#010b')[-8:]

        if bytes_num == 0:
            for bit in binary:
                if bit == '0':
                    break
                bytes_num += 1

            if bytes_num == 0:
                continue

            if bytes_num == 1 or bytes_num > 4:
                return False
        else:
            if not (binary[0] == '1' and binary[1] == '0'):
                return False

        bytes_num -= 1

    return bytes_num == 0
