H,W = map(int,input().split())
board = [list(input()) for _ in range(H)]
for i in range(H):
    idx = -1
    cnt = 0
    for j in range(W):
        if board[i][j]=='c':
            print(0, end=' ')
            idx = j
            cnt = 1
        elif idx == -1:
            print(-1, end=' ')
        else:
            print(cnt, end=' ')
            cnt+=1
    print()