def dfs(cur):
    child = []
    for next in tree[cur]:
        dfs(next)
        child.append(dp[next])
    if not tree[cur]:
        child.append(0)
        
    child.sort(reverse=True)
    tmp = [child[i]+i+1 for i in range(len(child))]
    dp[cur] = max(tmp)

n = int(input())
arr = list(map(int, input().split()))
tree = [[] for _ in range(n)]
for i in range(1,n):
    tree[arr[i]].append(i)
dp = [0]*n
dfs(0)
print(dp[0]-1)