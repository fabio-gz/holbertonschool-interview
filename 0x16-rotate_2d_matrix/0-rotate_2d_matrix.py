#!/usr/bin/python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """rotate the matrix"""
    n = len(matrix)
    matrix.reverse()
    for i in range(n):
        for j in range(n-1, i-1, -1):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
