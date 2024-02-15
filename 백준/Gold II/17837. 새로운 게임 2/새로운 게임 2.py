import sys

xd = [0,0,-1,1]
yd = [1,-1,0,0]

def move(chess_num):
    x,y,d = horse[chess_num]
    nx = x+xd[d]
    ny = y+yd[d]

    if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
        if d in [0,1]:
            nd = 1-d
        else:
            nd = 5-d
        horse[chess_num][2]=nd
        nx = x+xd[nd]
        ny = y+yd[nd]
        if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
            return False

    horse_tmp = []
    idx = chess[x][y].index(chess_num)
    horse_tmp.extend(chess[x][y][idx:])
    chess[x][y] = chess[x][y][:idx]

    if board[nx][ny]==1:
        horse_tmp = horse_tmp[-1::-1]
        
    for i in horse_tmp:
        chess[nx][ny].append(i)
        horse[i][:2] = [nx,ny]
        
    return len(chess[nx][ny])>=4
        

n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
chess = [[[] for _ in range(n)] for _ in range(n)]
horse = [0]*k
for i in range(k):
    x,y,d = map(int, input().split())
    horse[i] = [x-1,y-1,d-1]
    chess[x-1][y-1].append(i)

cnt = 1
while cnt<=1000:
    for i in range(k):
        is_end = move(i)
        if is_end:
            print(cnt)
            sys.exit()
    cnt+=1
print(-1)