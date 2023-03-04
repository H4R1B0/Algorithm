from collections import deque
N,M,T=map(int,input().split())
board=[deque(int(x) for x in input().split()) for _ in range(N)]
info=[[int(x) for x in input().split()] for _ in range(T)]
#print(board)
#print(info)

for t in range(T):
    x,d,k=info[t]
    result=0
    for i in range(N):
        result+=sum(board[i])
        if (i+1)%x==0:
            if d==0:
                board[i].rotate(k)
            else:
                board[i].rotate(-k)
    if result!=0:
        removed=[]
        for i in range(N):
            for j in range(M-1):
                if board[i][j]!=0 and board[i][j+1]!=0 and board[i][j]==board[i][j+1]:
                    removed.append((i,j))
                    removed.append((i,j+1))
            if board[i][0]!=0 and board[i][-1]!=0 and board[i][0]==board[i][-1]:
                    removed.append((i,0))
                    removed.append((i,M-1))

        for j in range(M):
            for i in range(N-1):
                if board[i][j]!=0 and board[i+1][j]!=0 and board[i][j]==board[i+1][j]:
                    removed.append((i,j))
                    removed.append((i+1,j))
        removed=list(set(removed))

        for x,y in removed:
            board[x][y]=0

        if len(removed)==0:
            avg_sum=0
            zero_cnt=0
            for i in range(N):
                avg_sum+=sum(board[i])
                zero_cnt+=board[i].count(0)
            avg=avg_sum/(N*M-zero_cnt)

            for i in range(N):
                for j in range(M):
                    if board[i][j]!=0 and board[i][j]>avg:
                        board[i][j]-=1
                    elif board[i][j]!=0 and board[i][j]<avg:
                        board[i][j]+=1
    else:
        break
answer=0
for i in range(N):
    answer+=sum(board[i])
print(answer)
