N,K = map(int,input().split())
dp = [0]*(N+1)
arr = []
for _ in range(K):
    I,T = map(int,input().split())
    arr.append((I,T))
# print(arr)
for I,T in arr:
    for i in range(N,T-1,-1):
        dp[i] = max(dp[i], dp[i-T]+I)

print(dp[-1])