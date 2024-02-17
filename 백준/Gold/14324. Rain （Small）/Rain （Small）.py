xd = [0,0,1,-1]
yd = [1,-1,0,0]

def bfs(high):
    q=[]
    q.append([0,0])
    while q!=[]:
        x,y = q.pop(0)
        for i in range(4):
            nx = x+xd[i]
            ny = y+yd[i]
            if 0<=nx<=n+1 and 0<=ny<=m+1 and board[nx][ny]<high:
                board[nx][ny] = high
                q.append([nx,ny])

T = int(input())
for t in range(1,T+1):
    answer = 0
    n,m = map(int, input().split())
    board = [[0]*(m+2) for _ in range(n+2)]
    # print(len(board), len(board[0]))
    high = 0
    for i in range(1,n+1):
        board[i][1:m+1] = list(map(int,input().split()))
        high = max(high, max(board[i]))
    # print(board)
    for k in range(1,high+1):
        bfs(k)
        for i in range(1,n+1):
            for j in range(1,m+1):
                if board[i][j]<k:
                    board[i][j]=k
                    answer+=1
    print("Case #%d: %d" % (t,answer))