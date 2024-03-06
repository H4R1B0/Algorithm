import heapq
import sys

def dijkstra():
    q = []
    # cost,cur
    heapq.heappush(q,(0,1))
    dist = [sys.maxsize]*(n+1)
    dist[1] = 0
    while q:
        cost,cur = heapq.heappop(q)
        if cur==n:
            return cost
        if dist[cur] < cost:
            continue
        for next,i in arr[cur]:
            next_cost = ((cost-i+m-1)//m)*m+i+1
            if dist[next]>next_cost:
                dist[next] = next_cost
                heapq.heappush(q,(next_cost,next))

n,m = map(int,input().split())
arr = [[] for _ in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    arr[a].append((b,i))
    arr[b].append((a,i))

answer = dijkstra()
print(answer)