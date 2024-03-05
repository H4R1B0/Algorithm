import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def set_depth(cur, cnt):
    visit[cur] = True
    depth[cur] = cnt

    for next in graph[cur]:
        if not visit[next]:
            parent[next][0] = cur
            set_depth(next,cnt+1)

def lca(a,b):
    if depth[a] > depth[b]:
        a,b = b,a
        
    for i in range(LOG - 1, -1, -1):
        if depth[b] - depth[a] >= (1 << i):
            b = parent[b][i]

    if a == b:
        return a

    for i in range(LOG-1, -1, -1):
        if parent[a][i] != parent[b][i]:
            a = parent[a][i]
            b = parent[b][i]

    return parent[a][0]

n = int(input())
graph = [[] for _ in range(n+1)]
for _ in range(n-1):
    x,y = map(int,input().split())
    graph[x].append(y)
    graph[y].append(x)
# print(graph)
LOG = 21
parent = [[0]*LOG for _ in range(n+1)]
depth = [0]*(n+1)
visit = [False]*(n+1)
set_depth(1,0)
for i in range(1, LOG):
    for j in range(1, n+1):
        parent[j][i] = parent[parent[j][i-1]][i-1]

m = int(input())
for _ in range(m):
    a,b = map(int,input().split())
    print(lca(a,b))