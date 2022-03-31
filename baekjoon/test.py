import sys

def binarySearch(arr, target, start, end, cnt):
    if(start > end):
        return cnt
    mid = (start + end) // 2

    if arr[mid] == target:
        cnt += 1
        # return mid
    elif arr[mid] > target:
        print('present mid is', mid)
        return binarySearch(arr, target, start, mid -1, cnt)
    else:
        print('present mid is///', mid)
        return binarySearch(arr, target, mid+1, end, cnt)



n = int(sys.stdin.readline())
base = list(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline())
search = list(map(int, sys.stdin.readline().split()))

base.sort()
print(base)
for v in search:
    cnt = 0
    cnt = binarySearch(base, v, 0, n-1, cnt)
    print(v, ' is ', cnt)

