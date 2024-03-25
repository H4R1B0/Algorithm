n = int(input())
arr = [float(input()) for _ in range(n)]
# print(arr)
dp = [0]*n
dp[0] = arr[0]
for i in range(1,n):
    dp[i] = max(arr[i], dp[i-1]*arr[i])

print('%.3f' % max(dp))