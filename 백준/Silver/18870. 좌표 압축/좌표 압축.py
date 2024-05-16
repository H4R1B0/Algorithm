n = int(input())
arr = list(map(int,input().split()))
tmp = arr[:]
tmp.sort()
idx = 0
dic = dict()
for num in tmp:
    if num not in dic:
        dic[num] = idx
        idx += 1
for num in arr:
    print(dic[num], end=' ')