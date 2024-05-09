xd = [0, 0, -1, 1]
yd = [-1, 1, 0, 0]
dd = [1, 0, 3, 2]

def move(d):
    if d==0:
        visit[0][1], visit[1][1], visit[2][1], visit[3][1] = visit[3][1], visit[0][1], visit[1][1], visit[2][1]
    elif d==1:
        visit[3][1], visit[0][1], visit[1][1], visit[2][1] = visit[0][1], visit[1][1], visit[2][1], visit[3][1]
    elif d==2:
        visit[1][0], visit[1][1], visit[1][2], visit[3][1] = visit[3][1], visit[1][0], visit[1][1], visit[1][2]
    else:
        visit[3][1], visit[1][0], visit[1][1], visit[1][2] = visit[1][0], visit[1][1], visit[1][2], visit[3][1]

def dfs(x, y):
    cnt = 1
    for d in range(4):
        nx, ny = x+xd[d], y+yd[d]
        if 0<=nx<6 and 0<=ny<6 and board[nx][ny]==1:
            move(d)
            if not visit[1][1]:
                visit[1][1] = True
                cnt += dfs(nx, ny)
            move(dd[d])
    return cnt

def get_answer():    
    for i in range(6):
        for j in range(6):
            if board[i][j]==1:
                visit[1][1] = True
                cnt = dfs(i, j)
                return 'yes' if cnt==6 else 'no'
                
for _ in range(3):
    board = [list(map(int, input().split())) for _ in range(6)]
    visit = [[False]*3 for _ in range(4)]
    print(get_answer())