from bisect import bisect_left

n = int(input())
arr = list(map(int,input().split()))
res = []
idx_arr = []

for num in arr:
    idx = bisect_left(res,num)
    if len(res)==idx:
        res.append(num)
    else:
        res[idx]=num
    idx_arr.append(idx)
print(len(res))
# print(idx_arr)
answer = []
find_idx = len(res)-1
for i in range(n-1,-1,-1):
    # print(i)
    if find_idx==idx_arr[i]:
        answer.append(arr[i])
        find_idx-=1
print(' '.join(map(str,answer[::-1])))