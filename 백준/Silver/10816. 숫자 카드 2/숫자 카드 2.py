from collections import defaultdict
dic = defaultdict(int)
N = int(input())
arr = list(map(int,input().split()))

for i in arr:
    dic[i] += 1

M = int(input())
ar = list(map(int,input().split()))
for i in ar:
    print(dic[i],end=' ')