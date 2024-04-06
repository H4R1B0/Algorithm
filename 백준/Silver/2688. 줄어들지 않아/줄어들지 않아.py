dp = [[0]*10 for _ in range(65)]

for i in range(10):
    dp[1][i] = 1

for i in range(2,65):
    for j in range(0,10):
        for k in range(j,10):
            dp[i][j] += dp[i-1][k]
for _ in range(int(input())):
    n = int(input())
    print(sum(dp[n]))