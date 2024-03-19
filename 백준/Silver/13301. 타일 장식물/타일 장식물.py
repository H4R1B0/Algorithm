# 4,6,10,16,26
dp = [0]*81
dp[0] = 4
dp[1] = 6
for i in range(2,81):
    dp[i] = dp[i-1]+dp[i-2]

n = int(input())
print(dp[n-1])