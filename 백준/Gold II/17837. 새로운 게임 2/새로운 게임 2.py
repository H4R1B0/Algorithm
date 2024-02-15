import sys

xd = [0, 0, -1, 1]
yd = [1, -1, 0, 0]

def move(chess_num):
    x, y, dir = horse[chess_num]
    nx = x+xd[dir]
    ny = y+yd[dir]

    if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
        if dir in [0,1]:
            ndir = 1-dir
        else:
            ndir = 5-dir
        horse[chess_num][2] = ndir
        nx = x+xd[ndir]
        ny = y+yd[ndir]
        if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
            return False

    horse_tmp = []
    idx = chess_map[x][y].index(chess_num)
    horse_tmp.extend(chess_map[x][y][idx:])
    chess_map[x][y] = chess_map[x][y][:idx]

    if board[nx][ny]==1:
        horse_tmp = horse_tmp[-1::-1]

    for i in horse_tmp:
        chess_map[nx][ny].append(i)
        horse[i][:2] = [nx,ny]
    if len(chess_map[nx][ny])>=4:
        return True
    return False

n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
# print(board)
chess_map = [[[] for _ in range(n)] for _ in range(n)]
horse = [0]*k

for i in range(k):
    x, y, dir = map(int, input().split())
    chess_map[x-1][y-1].append(i)
    horse[i] = [x-1, y-1, dir-1]

cnt = 1
while cnt<=1000:
    for i in range(k):
        is_end = move(i)
        if is_end:
            print(cnt)
            sys.exit()
    cnt+=1
print(-1)