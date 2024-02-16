def bfs(cow):
    q = []
    q.append(cow)
    visit[cow[0]][cow[1]] = True
    while q!=[]:
        cur = q.pop(0)
        for i in range(4):
            if linked[cur[0]][cur[1]][i]:
                continue
                
            nx = cur[0]+xd[i]
            ny = cur[1]+yd[i]
            if 1<=nx<=n and 1<=ny<=n and not visit[nx][ny]:
                visit[nx][ny] = True
                q.append([nx,ny])

xd = [1,0,-1,0]
yd = [0,1,0,-1]

n,k,r = map(int, input().split())
linked = [[[False]*4 for _ in range(n+1)] for _ in range(n+1)]
cows = []
for _ in range(r):
    x1,y1,x2,y2 = map(int, input().split())
    for i in range(4):
        nx = x1+xd[i]
        ny = y1+yd[i]
        if [nx,ny]==[x2,y2]:
            linked[x1][y1][i] = True
            linked[x2][y2][(i+2)%4] = True
for _ in range(k):
    x,y = map(int, input().split())
    cows.append([x,y])
# print(linked)
# print(cows)

answer = 0
visit = [[False]*(n+1) for _ in range(n+1)]
for i in range(k):
    visit = [[False]*(n+1) for _ in range(n+1)]
    bfs(cows[i])
    for j in range(i+1,k):
        if not visit[cows[j][0]][cows[j][1]]:
            answer+=1
print(answer)