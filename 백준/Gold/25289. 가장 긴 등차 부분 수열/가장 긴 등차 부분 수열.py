N = int(input())
arr = list(map(int, input().split()))
#print(arr)
answer = 0
for diff in range(-99, 100):
    dp = [0]*101
    for i in range(0, N):
        if arr[i] - diff < 1  or arr[i] - diff > 100:
            dp[arr[i]] = 1
        else:
            dp[arr[i]] = dp[arr[i] - diff] + 1
        answer = max(answer, dp[arr[i]])
print(answer)
