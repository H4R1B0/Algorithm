xd = (-1,1,1,1,0,0,0,-1,-1,-1)
yd = (-1,-1,0,1,-1,0,1,-1,0,1)

R,C = map(int,input().split())
board = [list(input()) for _ in range(R)]
moves = list(map(int, input()))
# print(board)
# print(moves)
loc_js = [(i,j) for i in range(R) for j in range(C) if board[i][j]=='I'][0]
loc_ad = [(i,j) for i in range(R) for j in range(C) if board[i][j]=='R']
# print(loc_ad)

def get_dist(A, B):
    return abs(B[0]-A[0])+abs(B[1]-A[1])

def move_js(dir):
    global loc_js
    x,y = loc_js
    nx = x+xd[dir]
    ny = y+yd[dir]
    
    if board[nx][ny]=='R':
        return False
        
    loc_js = (nx,ny)
    board[x][y]='.'
    board[nx][ny]='I'
    return True

def move_ad():
    global loc_ad
    dic = {}
    new_ad = set()

    for x,y in loc_ad:
        board[x][y] = '.'
        min_dist = 1e9
        min_loc = (0,0)
        for d in range(1,10):
            if d==5:
                continue
            nx = x+xd[d]
            ny = y+yd[d]
            if 0<=nx<R and 0<=ny<C:
                dist = get_dist((nx,ny), loc_js)
                if min_dist > dist:
                    min_dist = dist
                    min_loc = (nx,ny)
        if min_loc==loc_js:
            return False
        new_ad.add(min_loc)
        if min_loc in dic:
            dic[min_loc]+=1
        else:
            dic[min_loc]=1
    tmp = []
    for loc in new_ad:
        if loc in tmp or dic[loc]>1:
            continue
        tmp.append(loc)
    loc_ad = tmp
    for x,y in loc_ad:
        board[x][y] = 'R'
    return True

for i, d in enumerate(moves):
    if not move_js(d):
        print("kraj %d" % (i+1))
        exit()
    if not move_ad():
        print("kraj %d" % (i+1))
        exit()
for b in board:
    print(''.join(b))