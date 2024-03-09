def dfs(n,k):
    if n==0:
        return 0
    if k==0:
        return 1e9
    if dp[n][k]!=-1:
        return dp[n][k]
    dp[n][k]=1e9
    for i in range(1,n+1):
        dp[n][k] = min(dp[n][k], max(dfs(i-1, k-1), dfs(n-i, k))+1)
    return dp[n][k]

n,k = map(int,input().split())

dp = [[-1]*(k+1) for _ in range(n+1)]

print(dfs(n,k))