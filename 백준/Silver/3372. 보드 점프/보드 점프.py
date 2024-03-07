xd = [1,0]
yd = [0,1]
n = int(input())
board = [list(map(int,input().split())) for _ in range(n)]
dp = [[0]*n for _ in range(n)]
dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if board[i][j]==0:
            continue
        for dir in range(2):
            nx = i+board[i][j]*xd[dir]
            ny = j+board[i][j]*yd[dir]
            if 0<=nx<n and 0<=ny<n:
                dp[nx][ny] += dp[i][j]
 
print(dp[-1][-1])