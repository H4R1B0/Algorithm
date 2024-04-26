n=int(input())
dp=[0]*(n+2)
dp[0]=1
dp[1]=2
dp[2]=7
MOD = 1000000007
for i in range(3, n+1):
    dp[i]=(dp[i-1]*3+dp[i-2]-dp[i-3])%MOD
print(dp[n]%MOD)