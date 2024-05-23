n,m= map(int,input().split())
 
arr = [0]*m
 
def dfs(cnt):
    if cnt==m:
        print(*arr)
        return
    
    for i in range(1,n+1):
        arr[cnt] = i
        dfs(cnt+1)
dfs(0)