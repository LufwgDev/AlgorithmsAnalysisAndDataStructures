import math

def jump_search(arr, key):
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0
    while arr[min(step, n) -1] < key:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1
    for i in range(prev, min(step, n)):
        if arr[i] == key:
            return i
    return -1

