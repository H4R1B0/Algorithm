D,P = map(int,input().split())
dp = [1e9]+[0]*(D)
arr = []
for _ in range(P):
    L,C = map(int,input().split())
    for i in range(D,L-1,-1):
        dp[i] = max(dp[i],min(C,dp[i-L]))

print(dp[-1])