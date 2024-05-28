n = int(input())
arr = [(1000, 1000)]
answer = 0
for _ in range(n):
    w, h = map(int, input().split())
    arr.append((max(w, h), min(w, h)))

arr.sort(reverse=True)
# print(arr)
dp = [[0, arr[i][1]] for i in range(n+1)]
for i in range(1, n+1):
    for j in range(i-1, -1, -1):
        if dp[j][1] >= arr[i][1] and dp[j][0] + 1 > dp[i][0]:
            dp[i][0] = dp[j][0] + 1
            dp[i][1] = arr[i][1]
            answer = max(answer, dp[i][0])

print(answer)