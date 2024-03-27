s = input()
n = len(s)
s = '.' + s
p = [[0] * (n + 1) for _ in range(n + 1)]
dp = [2500] * (n + 1)

for i in range(1, n + 1):
    p[i][i] = True
for i in range(1, n):
    p[i][i + 1] = (s[i] == s[i + 1])
for j in range(2, n):
    for i in range(1, n - j + 1):
        if s[i] == s[i + j] and p[i + 1][i + j - 1]:
            p[i][i + j] = True

dp[0] = 0
for i in range(1, n + 1):
    for j in range(1, i + 1):
        if p[j][i]:
            dp[i] = min(dp[i], dp[j - 1] + 1)

# print(dp)
print(dp[n])