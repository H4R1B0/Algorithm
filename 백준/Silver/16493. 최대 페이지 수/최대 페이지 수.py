N,M = map(int,input().split())
arr = [[0,0]] + [list(map(int,input().split())) for _ in range(M)]
# print(arr)
dp = [[0]*(N+1) for _ in range(M+1)]
for i in range(1,M+1):
    for j in range(N+1):
        if j-arr[i][0]>=0:
            dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i][0]]+arr[i][1])
        dp[i][j] = max(dp[i][j], dp[i-1][j])

print(dp[-1][-1])