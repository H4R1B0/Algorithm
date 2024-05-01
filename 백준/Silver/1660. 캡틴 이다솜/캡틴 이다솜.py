import sys

n = int(input())
balls = []
b = 0
i = 1
while b < n:
    b += (i*(i+1))//2
    balls.append(b)
    i+=1
# print(balls)
dp = [sys.maxsize]*(n+1)
for i in range(1, n+1):
    for b in balls:
        if b >= i:
            if b == i:
                dp[i] = 1
            break
        dp[i] = min(dp[i],dp[i-b]+1)
print(dp[n])