#!/usr/bin/python3
"""calculate how much water will be retained after it rains"""


def rain(walls):
    """amount of water retained"""
    (left, right) = (0, len(walls) - 1)
    water = 0

    maxLeft = walls[left]
    maxRight = walls[right]

    while left < right:
        if walls[left] <= walls[right]:
            left += 1
            maxLeft = max(maxLeft, walls[left])
            water += (maxLeft - walls[left])
        else:
            right -= 1
            maxRight = max(maxRight, walls[right])
            water += (maxRight - walls[right])

    return water
