dp = [0]*100001
MOD = 1000000009
dp[1] = 1
dp[2] = 2
dp[3] = 2
dp[4] = 3
dp[5] = 3
dp[6] = 6
dp[7] = 6

for i in range(8, 100001):
    dp[i] = dp[i - 2] + dp[i - 4] + dp[i - 6]

for _ in range(int(input())):
    print(dp[int(input())] % MOD)