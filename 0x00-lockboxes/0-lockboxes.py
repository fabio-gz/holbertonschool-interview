#!/usr/bin/python3
"""unlocked boxes problem """


def canUnlockAll(boxes):
    """checks if all boxes can be opened."""

    stack = [0]
    unlocked = set(stack)

    while stack:
        i = stack.pop()
        for j in boxes[i]:
            if j not in unlocked:
                stack.append(j)
                unlocked.add(j)
            if len(unlocked) == len(boxes):
                return True
    return False
