for _ in range(int(input())):
    n = int(input())
    coins = list(map(int,input().split()))
    x = int(input())

    dp = [0]*(x+1)
    dp[0] = 1
    for i in range(n):
        for j in range(coins[i], x+1):
            dp[j] += dp[j-coins[i]]
    print(dp[x])