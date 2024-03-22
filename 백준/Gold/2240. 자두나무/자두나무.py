T,W = map(int,input().split())
arr = [0] + [int(input()) for _ in range(T)]
# print(arr)
dp = [[0] * (W + 1) for _ in range(T + 1)]

if arr[1]==1:
    dp[1][0]=1
else:
    dp[1][1]=1
for t in range(2, T + 1):
    for w in range(W + 1):
        cnt=0
        if w%2==0 and arr[t]==1:
            cnt=1
        elif w%2==1 and arr[t]==2:
            cnt=1
        dp[t][w] = max(dp[t-1][:w+1]) + cnt

print(max(dp[-1]))