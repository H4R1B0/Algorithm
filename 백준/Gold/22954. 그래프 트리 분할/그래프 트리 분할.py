from collections import defaultdict
import sys
input = sys.stdin.readline

def bfs(start):
    visit[start] = True
    node = [start]
    edge = []
    q = [start]
    while q:
        start = q.pop()
        # print(edge_dict[start])
        for idx,next in edge_dict[start]:
            if not visit[next]:
                visit[next] = True
                edge.append(idx)
                node.append(next)
                q.append(next)
    return edge,node,start
        
        
n,m = map(int,input().split())
edge_list = [[i] + list(map(int,input().split())) for i in range(1,m+1)]
# print(edge_list)

if n<=2 or m<n-2:
    print(-1)
    exit()

edge_dict = defaultdict(list)
visit = [False]*(n+1)
for i,a,b in edge_list:
    edge_dict[a].append((i,b))
    edge_dict[b].append((i,a))
# print(edge_dict)

edges, nodes, last_nodes = list(), list(), list()
for i in range(1, n+1) :
    if not visit[i] :
        edge, node, last_node = bfs(i)
        edges.append(edge)
        nodes.append(node)
        last_nodes.append(last_node)

# print(edges)
# print(nodes)
# print(last_nodes)
if len(nodes)>2:
    print(-1)
    exit()

if len(nodes) == 2 :
    if len(nodes[0]) == len(nodes[1]) :
        print(-1)
        exit()
    print(len(nodes[0]), len(nodes[1]))
    for i in range(2) :
        print(*nodes[i])
        print(*edges[i])
    exit()

edges, nodes, last_node = edges[0], nodes[0], last_nodes[0]
first_edges = list()
for idx in edges:
    _, a, b = edge_list[idx-1]
    if a==last_node or b==last_node:
        continue
    first_edges.append(idx)

print(len(nodes)-1,1)
print(*[i for i in nodes if i!=last_node])
print(*first_edges)
print(last_node)
print()