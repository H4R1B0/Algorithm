import sys
input = sys.stdin.readline

n = int(input())
train = list(map(int,input().split()))
m = int(input())

sum_ = [0]
for i in range(n):
    sum_.append(sum_[i]+train[i])

# print(sum_)
dp = [[0]*(n+1) for _ in range(4)]
for i in range(1,4):
    for j in range(i*m, n+1):
        if i==1:
            dp[i][j] = max(dp[i][j-1], sum_[j]-sum_[j-m])
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-m]+sum_[j]-sum_[j-m])

print(dp[3][n])