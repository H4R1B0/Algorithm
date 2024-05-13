N,M = map(int,input().split())
dp = [0]*(M+1)
arr = []
for _ in range(N):
    W,V = map(int,input().split())
    arr.append((W,V))

for W,V in arr:
    for i in range(M,W-1,-1):
        dp[i] = max(dp[i],dp[i-W]+V)

print(dp[-1])