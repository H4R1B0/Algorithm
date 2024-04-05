dp = [1,1,2] + [0]*35
for i in range(3, 36):
    for j in range(i+1):
        dp[i] += dp[j]*dp[i-j-1]
# print(dp)
print(dp[int(input())])