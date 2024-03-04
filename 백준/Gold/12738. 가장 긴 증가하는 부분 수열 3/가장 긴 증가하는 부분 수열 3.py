def binary_search(left,right,target):
    while left<right:
        mid = (left+right)//2
        if res[mid]==target:
            return mid
        elif res[mid] < target:
            left = mid+1
        else:
            right = mid
    return left

n = int(input())
arr = list(map(int,input().split()))
res = [arr[0]]

for i in range(1,len(arr)):
    if res[-1]<arr[i]:
        res.append(arr[i])
    else:
        idx = binary_search(0,len(res)-1,arr[i])
        # print(idx)
        res[idx] = arr[i]
print(len(res))