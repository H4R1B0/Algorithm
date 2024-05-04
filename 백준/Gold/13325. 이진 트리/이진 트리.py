import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
a = deque(list(map(int, input().split())))
tree = {i: {} for i in range(1, 2**(n+1))}
# print(tree)
dp = [[0, 0] for _ in range(2**(n+1))]
# print(dp)
for i in range(1, 2**n):
    tree[i][i*2] = a.popleft()
    tree[i][i*2+1] = a.popleft()

def dfs(cnt, idx):
    if cnt==n-1:
        maxx = max(tree[idx][idx*2], tree[idx][idx*2+1])
        dp[idx] = [maxx, maxx*2]
        # print(dp[idx])
        return dp[idx]
    else:
        dp[idx][0] = max(tree[idx][idx*2] + dfs(cnt+1, idx*2)[0], tree[idx][idx*2+1] + dfs(cnt+1, idx*2+1)[0])
        dp[idx][1] = dp[idx*2][1] + dp[idx*2+1][1] + dp[idx][0] - dp[idx*2][0] + dp[idx][0] - dp[idx*2+1][0]
        return dp[idx]

print(dfs(0, 1)[1])
# print(dp)