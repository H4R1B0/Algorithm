import sys
from collections import defaultdict
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def dfs(cur,prev):
    global answer
    ret = 1
    for next in graph[cur]:
        if next!=prev:
            cnt = dfs(next,cur)
            answer += cnt*(n-cnt)+cnt*(cnt-1)//2
            ret += cnt

    return ret

n = int(input())

graph = defaultdict(list)

for _ in range(n-1):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

# print(graph)
answer = 0
dfs(1,1)
print(answer)