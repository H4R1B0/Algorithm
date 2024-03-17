n = int(input())
arr = [0]+list(map(int,input().split()))
# print(arr)
dp = [1e9]*(n+1)
dp[0] =0 
dp[1] = arr[1]
for i in range(2,n+1):
    for j in range(i+1):
        dp[i] = min(dp[i],dp[i-j]+arr[j])
print(dp[n])