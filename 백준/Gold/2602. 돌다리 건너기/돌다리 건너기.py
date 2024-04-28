order = list(input())
board = [list(input()) for _ in range(2)]

order_len = len(order)
board_len = len(board[0])

dp = [[[0]*2 for _ in range(order_len)] for _ in range(board_len)]

for i in range(board_len):
    for j in range(order_len):
        for k in range(2):
            if board[k][i]==order[j]:
                if j==0:
                    dp[i][j][k] = 1
                else:
                    for l in range(i):
                        dp[i][j][k] += dp[l][j-1][1-k]

answer = 0
for i in range(board_len):
    answer += sum(dp[i][-1])

print(answer)