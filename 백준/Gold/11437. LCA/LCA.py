import sys
sys.setrecursionlimit(10**5)

def set_depth(cur, cnt):
    visit[cur] = True
    depth[cur] = cnt

    for next in graph[cur]:
        if not visit[next]:
            parent[next] = cur
            set_depth(next,cnt+1)

def lca(a,b):
    while depth[a]!=depth[b]:
        if depth[a]>depth[b]:
            a = parent[a]
        else:
            b = parent[b]
    while a!=b:
        a = parent[a]
        b = parent[b]
    return a

n = int(input())
graph = [[] for _ in range(n+1)]
for _ in range(n-1):
    x,y = map(int,input().split())
    graph[x].append(y)
    graph[y].append(x)
# print(graph)
parent = [0]*(n+1)
depth = [0]*(n+1)
visit = [False]*(n+1)
set_depth(1,0)
m = int(input())
for _ in range(m):
    a,b = map(int,input().split())
    print(lca(a,b))