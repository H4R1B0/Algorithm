dp = [1,1,1] + [0]*120
for i in range(3,120):
    dp[i] = dp[i-1]+dp[i-3]
print(dp[int(input())-1])