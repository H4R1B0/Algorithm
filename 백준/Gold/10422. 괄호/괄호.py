dp = [0]*5001
dp[0] = 1
MOD = 1000000007

for n in range(2, 5001, 2):
    for i in range(2, n + 1, 2):
        dp[n] += dp[i - 2] * dp[n - i]
    dp[n] %= MOD

for _ in range(int(input())):
    print(dp[int(input())])