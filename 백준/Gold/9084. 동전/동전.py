T = int(input())
for t in range(T):
    N = int(input())
    arr = [0]
    arr += list(map(int, input().split()))
    M = int(input())
    #print(arr)
    dp = [0]*(M+1)
    dp[0]=1
    for i in range(1,N+1):
        for j in range(arr[i],M+1):
            dp[j] = dp[j]+dp[j-arr[i]]
    print(dp[M])
