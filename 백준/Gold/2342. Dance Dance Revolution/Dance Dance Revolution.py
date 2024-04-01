import sys
sys.setrecursionlimit(10**8)

def dfs(cnt, left, right):
    if cnt==len(step):
        return 0
    if left==right and left!=0 and right!=0:
        return 1e9
    if dp[cnt][left][right]!=-1:
        return dp[cnt][left][right]
    dp[cnt][left][right] = min(dfs(cnt+1,step[cnt],right)+score[left][step[cnt]], dfs(cnt+1,left,step[cnt])+score[right][step[cnt]])
    return dp[cnt][left][right]

score = [[1,2,2,2,2],[0,1,3,4,3],[0,3,1,3,4],[0,4,3,1,3],[0,3,4,3,1]]
step = list(map(int,input().split()))[:-1]
dp = [[[-1]*5 for _ in range(5)] for _ in range(len(step))]
print(dfs(0,0,0))