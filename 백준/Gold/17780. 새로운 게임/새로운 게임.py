import sys

xd = [0, 0, -1, 1]
yd = [1, -1, 0, 0]

def move(chess_num):
    x,y,dir = chess[chess_num]
    if chess_num!=chess_map[x][y][0]:
        return False

    nx=x+xd[dir]
    ny=y+yd[dir]

    if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
        if 0 <= dir <= 1:
            ndir = 1-dir
        else:
            ndir = 5-dir
        chess[chess_num][2]=ndir
        nx=x+xd[ndir]
        ny=y+yd[ndir]
        if not 0<=nx<n or not 0<=ny<n or board[nx][ny]==2:
            return False

    chess_set=[]
    chess_set.extend(chess_map[x][y])
    chess_map[x][y]=[]
    if board[nx][ny] == 1:
        chess_set = chess_set[-1::-1]
        
    for i in chess_set:
        chess_map[nx][ny].append(i)
        chess[i][:2] = [nx, ny]

    if len(chess_map[nx][ny]) >= 4:
        return True
    return False

n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
chess_map = [[[] for _ in range(n)] for _ in range(n)]
chess = [0]*k

for i in range(k):
    x,y,dir = map(int, input().split())
    chess_map[x-1][y-1].append(i)
    chess[i]=[x-1,y-1,dir-1]
    
# print(chess)
cnt = 1
while cnt <= 1000:
    for i in range(k):
        is_end = move(i)
        if is_end:
            print(cnt)
            sys.exit()
    cnt+=1
print(-1)