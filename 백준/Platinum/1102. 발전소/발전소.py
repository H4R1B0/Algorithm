N = int(input())
cost = [list(map(int,input().split())) for _ in range(N)]
status = 0
tmp = input()
count = 0
for i in range(N):
    if tmp[i]=='Y':
        status |= 1<<i
        count += 1
P = int(input())
if count>=P:
    print(0)
elif count==0:
    print(-1)
else:
    dp = [[-1]*(2**N) for _ in range(P-count+1)]
    dp[0][status] = 0
    for bit in range(status, 2**N):
        for p in range(1,P-count+1):
            if dp[p-1][bit]!=-1:
                for i in range(N):
                    if bit&1<<i==1<<i:
                        for next in range(N):
                            if next!=i and bit&1<<next!=1<<next:
                                next_bit = bit | 1<<next
                                if dp[p][next_bit]==-1:
                                    dp[p][next_bit] = dp[p-1][bit]+cost[i][next]
                                else:
                                    dp[p][next_bit] = min(dp[p][next_bit], dp[p-1][bit]+cost[i][next])

    answer = 1e9
    for i in range(2**N):
        if dp[P-count][i] != -1:
            answer=min(dp[P-count][i] , answer)
    print(answer)