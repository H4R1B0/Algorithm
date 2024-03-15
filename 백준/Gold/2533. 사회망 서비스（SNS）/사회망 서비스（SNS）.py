import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def dfs(x):
    visit[x] = True
    dp[x][0]=1
    for next in arr[x]:
        if visit[next]:
            continue
        dfs(next)
        dp[x][1] += dp[next][0]
        dp[x][0] += min(dp[next][1],dp[next][0])
    

n = int(input())
arr = [[] for _ in range(n+1)]
for _ in range(n-1):
    a,b = map(int,input().split())
    arr[a].append(b)
    arr[b].append(a)

# print(arr)
dp = [[0]*2 for _ in range(n+1)]
visit = [False]*(n+1)
dfs(1)
print(min(dp[1][0],dp[1][1]))