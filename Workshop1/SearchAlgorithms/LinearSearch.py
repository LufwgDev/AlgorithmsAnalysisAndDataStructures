def linear_search(arr,target):
    for i in range(len(arr)):
        if arr[i]==target:
            return i
    return -1

def linear_search2(arr, key):
    for i, value in enumerate(arr):
        if value == key:
            return i
    return -1
