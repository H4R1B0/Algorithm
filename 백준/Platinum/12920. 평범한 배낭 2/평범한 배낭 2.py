N,M = map(int,input().split())
dp = [0]*(M+1)
arr = []
for i in range(N):
    V,C,K = map(int,input().split())
    i=1
    while K>0:
        min_ = min(i,K)
        arr.append((V*min_,C*min_))
        K -= i
        i *= 2
# print(arr)
for V,C in arr:
    for i in range(M, V - 1, -1):
        dp[i] = max(dp[i], dp[i - V] + C)

print(dp[M])