n = int(input())
arr = list(map(int,input().split()))
dp = [[0]*2 for _ in range(n+1)]
answer = arr[0]
for i in range(n):
    dp[i][0]=dp[i][1]=arr[i]
    if i==0:
        continue
    dp[i][0] = max(dp[i-1][0]+arr[i],arr[i])
    dp[i][1] = max(dp[i-1][0],dp[i-1][1]+arr[i])
    answer = max(answer, max(dp[i]))

print(answer)