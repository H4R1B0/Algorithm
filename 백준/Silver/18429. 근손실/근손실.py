import sys
input = sys.stdin.readline

def dfs(cur,cnt):
    global answer
    if cur < 500:
        return
    if cnt == n:
        answer += 1
        return
    cur -= k  
    for i in range(n):
        if not visit[i]:
            visit[i] = True
            dfs(cur + kit[i],cnt+1)
            visit[i] = False

n,k = map(int, input().split())
kit = list(map(int,input().split()))
answer = 0 
visit = [False]*n
dfs(500,0)
print(answer)