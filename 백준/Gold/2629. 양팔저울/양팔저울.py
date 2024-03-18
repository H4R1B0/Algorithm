n = int(input())
arr = list(map(int,input().split()))
total = sum(arr)
dp = [0]*40001
dp[0] = 1
for i in range(n):
    for j in range(total,-1,-1):
        if dp[j]:
            dp[j+arr[i]]=1
    for j in range(total+1):
        if dp[j]:
            dp[abs(j-arr[i])]=1

input()
m = list(map(int,input().split()))
for i in m:
    if dp[i]:
        print('Y',end=' ')
    else:
        print('N',end=' ')