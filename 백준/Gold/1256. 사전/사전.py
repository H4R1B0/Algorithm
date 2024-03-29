n,m,k = map(int,input().split())
dp = [[0]*101 for _ in range(101)]

for i in range(1,101):
    dp[i][0] = dp[0][i] = 1

for i in range(1,n+1):
    for j in range(1,m+1):
        dp[i][j] = dp[i-1][j]+dp[i][j-1]
        if dp[i][j]>1000000000:
            dp[i][j] = 1000000000

answer = ''

if dp[n][m]<k:
    print(-1)
else:
    a_cnt = n;
    z_cnt = m;
    for i in range(n+m):
        num = dp[a_cnt-1][z_cnt]
        if a_cnt==0:
            answer+='z'
            z_cnt-=1
        elif z_cnt==0:
            answer+='a'
            a_cnt-=1
        elif k<=num:
            answer+='a'
            a_cnt-=1
        else:
            k-=num
            answer+='z'
            z_cnt-=1

print(answer)