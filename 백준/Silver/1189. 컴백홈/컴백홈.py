xd = [0,0,1,-1]
yd = [1,-1,0,0]

def dfs(x,y,cnt):
    if x==0 and y==C-1:
        if cnt == K:
            global answer
            answer+=1
        return

    for i in range(4):
        nx = x+xd[i]
        ny = y+yd[i]
        if 0<=nx<R and 0<=ny<C and board[nx][ny]!='T':
            if not visit[nx][ny]:
                visit[nx][ny] = True
                dfs(nx,ny,cnt+1)
                visit[nx][ny] = False


R,C,K = map(int,input().split())
board = [list(input()) for _ in range(R)]
visit = [[False]* C for _ in range(R)]
# print(board)
answer = 0
visit[R-1][0] = True
dfs(R-1,0,1)
print(answer)