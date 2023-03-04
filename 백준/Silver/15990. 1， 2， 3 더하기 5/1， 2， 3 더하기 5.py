dp = [[0]*4 for _ in range(100001)]
dp[1][1]=dp[2][2]=dp[3][1]=dp[3][2]=dp[3][3]=1
for i in range(4,100001):
    dp[i][1]=(dp[i-1][2]+dp[i-1][3])%1000000009
    dp[i][2]=(dp[i-2][1]+dp[i-2][3])%1000000009
    dp[i][3]=(dp[i-3][1]+dp[i-3][2])%1000000009

T = int(input())
for t in range(T):
    n = int(input())
    print((dp[n][1]+dp[n][2]+dp[n][3])%1000000009)
