def get_dist(A, B):
    return abs(A[0]-B[0])+abs(A[1]-B[1])

def dfs(idx, cnt):
    if idx==0:
        return 0
    if dp[idx][cnt]!=-1:
        return dp[idx][cnt]

    result = 1e9
    for i in range(cnt+1):
        if idx-i-1<0:
            continue
        result = min(result, dfs(idx-i-1, cnt-i)+dist[idx-i-1][idx])
    dp[idx][cnt]=result
    return dp[idx][cnt]
    
n,k = map(int, input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
dist = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        dist[i][j] = get_dist(arr[i], arr[j])
dp = [[-1]*(k+1) for _ in range(n)]
# dp[0][0] = 0
answer = dfs(n-1,k)
# print(dp)
print(answer)