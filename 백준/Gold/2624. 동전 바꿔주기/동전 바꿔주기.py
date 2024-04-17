t = int(input())
k = int(input())
coins = []
for _ in range(k):
    a,b = map(int,input().split())
    coins.append((a,b))

dp = [1] + [0]*(t)
for coin,cnt in coins:
    for money in range(t,0,-1):
        for i in range(1,cnt+1):
            if money>=i*coin:
                dp[money] += dp[money-i*coin]

print(dp[t])