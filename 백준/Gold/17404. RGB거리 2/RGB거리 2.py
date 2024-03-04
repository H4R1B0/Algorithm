n = int(input())
rgb = [list(map(int,input().split())) for _ in range(n)]
answer = INF = 1e9
for i in range(3):
    dp = [[INF]*3 for _ in range(n)]
    dp[0][i] = rgb[0][i]
    for j in range(1,n):
        dp[j][0] = rgb[j][0] + min(dp[j-1][1],dp[j-1][2])
        dp[j][1] = rgb[j][1] + min(dp[j-1][0],dp[j-1][2])
        dp[j][2] = rgb[j][2] + min(dp[j-1][0],dp[j-1][1])
    # print(dp[-1])
    for j in range(3):
        if i!=j:
            answer = min(answer,dp[-1][j])
print(answer)