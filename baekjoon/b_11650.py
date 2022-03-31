import sys

def m_sort(arr, left, right):
    if(left == right): 
        return 

    mid = (left + right) // 2
    m_sort(arr,left, mid)
    m_sort(arr, mid+1, right)
    merge(arr, left, right, mid)



def merge(arr, left, right, mid):
    tmp = []
    L = left
    R = mid +1 
    while(L <= mid and R <= right):
        tmp.append(arr[L]) if arr[L][0] < arr[R][0] else tmp.append(arr[R])
        tmp.append(arr[L]) if (arr[L][0] == arr[R][0]) and (arr[L][1] <= arr[R][1]) else tmp.append(arr[R])
        R += 1
        L += 1
    if(L > mid):
        for i in range(R, right+1):
            tmp.append(arr[i])
    else:
        for i in range(L, mid+1):
            tmp.append(arr[i])
    for i in range(left, right+1):
        arr[i] = tmp[i]
    
    

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split())) for i in range(n)]


m_sort(data, 0, n-1)

for i in range(n):
    print("%d %d" % (data[i][0], data[i][1]))

