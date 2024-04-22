import sys
input = sys.stdin.readline

tc = 1
while True:
    N = int(input())
    if not N:
        break
        
    dp=[list(map(int,input().split())) for _ in range(N)]

    dp[1][0] += dp[0][1]
    dp[1][1] += min(dp[0][1], dp[0][1] + dp[0][2], dp[1][0])
    dp[1][2] += min(dp[0][1], dp[0][1] + dp[0][2], dp[1][1])

    for i in range(2,N):
        dp[i][0] += min(dp[i-1][0], dp[i-1][1])
        dp[i][1] += min(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0])
        dp[i][2] += min(dp[i-1][1], dp[i-1][2], dp[i][1])

    print("%d. %d" %(tc, dp[N-1][1]))
	
    tc += 1