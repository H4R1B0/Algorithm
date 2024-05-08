N, M = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(N)]
visit = [[False]*M for _ in range(N)]
answer = 0

def is_in_range(x, y):
    return 0<=x<N and 0<=y<M

def dfs(x, y, sum):
    global answer
    if y == M:
        y = 0
        x += 1
    
    if x == N:
        answer = max(answer, sum)
        return
    
    if is_in_range(x, y - 1) and is_in_range(x + 1, y) and not visit[x][y] and not visit[x][y - 1] and not visit[x + 1][y]:
        visit[x][y] = visit[x][y - 1] = visit[x + 1][y] = True
        dfs(x, y + 1, sum + 2 * map[x][y] + map[x][y - 1] + map[x + 1][y])
        visit[x][y] = visit[x][y - 1] = visit[x + 1][y] = False
    
    if is_in_range(x, y - 1) and is_in_range(x - 1, y) and not visit[x][y] and not visit[x][y - 1] and not visit[x - 1][y]:
        visit[x][y] = visit[x][y - 1] = visit[x - 1][y] = True
        dfs(x, y + 1, sum + 2 * map[x][y] + map[x][y - 1] + map[x - 1][y])
        visit[x][y] = visit[x][y - 1] = visit[x - 1][y] = False
    
    if is_in_range(x - 1, y) and is_in_range(x, y + 1) and not visit[x][y] and not visit[x - 1][y] and not visit[x][y + 1]:
        visit[x][y] = visit[x - 1][y] = visit[x][y + 1] = True
        dfs(x, y + 1, sum + 2 * map[x][y] + map[x - 1][y] + map[x][y + 1])
        visit[x][y] = visit[x - 1][y] = visit[x][y + 1] = False
    
    if is_in_range(x + 1, y) and is_in_range(x, y + 1) and not visit[x][y] and not visit[x + 1][y] and not visit[x][y + 1]:
        visit[x][y] = visit[x + 1][y] = visit[x][y + 1] = True
        dfs(x, y + 1, sum + 2 * map[x][y] + map[x + 1][y] + map[x][y + 1])
        visit[x][y] = visit[x + 1][y] = visit[x][y + 1] = False
    
    dfs(x, y + 1, sum)

dfs(0, 0, 0)

print(answer)