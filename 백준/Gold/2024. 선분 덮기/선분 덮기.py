import sys, heapq
input = sys.stdin.readline

m = int(input())
arr = []
while True:
    l,r = map(int,input().split())
    if l==0 and r==0:
        break
    if l>r:
        l,r = r,l
    if r<=0 or l>m or l==r:
        continue
    arr.append((l,r))

arr.sort()
# print(arr)

cur = 0
idx = 0
answer = 0
while True:
    num = -1
    while idx<len(arr):
        if arr[idx][0]<=cur:
            if arr[idx][1]>num:
                num = arr[idx][1]
            idx+=1
        else:
            break

    if num==-1:
        print(0)
        break

    answer+=1
    if num>=m:
        print(answer)
        break

    cur = num