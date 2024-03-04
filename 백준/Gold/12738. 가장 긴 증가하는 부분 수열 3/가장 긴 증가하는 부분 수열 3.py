from bisect import bisect_left

n = int(input())
arr = list(map(int,input().split()))
res = []

for num in arr:
    idx = bisect_left(res,num)
    if len(res)==idx:
        res.append(num)
    else:
        res[idx]=num
print(len(res))