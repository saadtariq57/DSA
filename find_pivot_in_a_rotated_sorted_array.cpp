low = 0
high = n - 1

while (low < high):
    mid = (low + high) / 2

    if arr[mid] > arr[high]:
        low = mid + 1
    else:
        high = mid

return low
