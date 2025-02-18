import random
import time
import math

#Bubblue
def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


#insertion
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


#quick
def quick_sort(arr):
    if len(arr) <=1:
        return arr
    else:
        pivot = arr[len(arr)//2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

#Linear
def linear_search(arr, key):
    for i, value in enumerate(arr):
        if value == key:
            return i
    return -1

#Binary
def binary_search(arr, key):
    left, right = 0, len(arr) -1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            left = mid + 1
        else:
            right = mid - 1
    return -1


#Jump
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

def main():
    SIZE = 1000

    arr = [random.randint(0,10000) for _ in range(SIZE)]
    copy_arr = arr[:]

    #Bubble
    bubble_arr = arr[:]
    start=time.perf_counter()
    bubble_sort(bubble_arr)
    end = time.perf_counter()
    print(f"Bubble Sort:        {end - start:.6f} seconds")

    #insertion
    insertion_arr = arr[:]
    start = time.perf_counter()
    insertion_sort(insertion_arr)
    end = time.perf_counter()
    print(f"Insertion Sort:        {end - start:.6f} seconds")

    #Quick
    start = time.perf_counter()
    quick_arr = quick_sort(arr)
    end = time.perf_counter()
    print(f"Quick Sort:        {end - start:.6f} seconds")


    key = copy_arr[SIZE//2]

    #Linear
    start = time.perf_counter()
    index = linear_search(copy_arr, key)
    end = time.perf_counter()
    print(f"Linear Search: key {key} found at index {index} in {end-start:.6f} seconds")

    #Binary
    start = time.perf_counter()
    index = binary_search(quick_arr, key)
    end = time.perf_counter()
    print(f"Binary Search: key {key} found at index {index} in {end-start:.6f} seconds")

    #Jump
    start = time.perf_counter()
    index = jump_search(quick_arr, key)
    end = time.perf_counter()
    print(f"Jump Search: key {key} found at index {index} in {end-start:.6f} seconds")

if __name__=="__main__":
    main()
