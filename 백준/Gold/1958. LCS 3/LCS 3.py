str1 = '.'+input()
str2 = '.'+input()
str3 = '.'+input()

dp = [[[0]*len(str3) for _ in range(len(str2))] for _ in range(len(str1))]
# print(dp)
for i in range(1,len(str1)):
    for j in range(1,len(str2)):
        for k in range(1,len(str3)):
            if str1[i]==str2[j] and str2[j]==str3[k]:
                dp[i][j][k] = dp[i-1][j-1][k-1]+1
            else:
                dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1])
print(dp[-1][-1][-1])