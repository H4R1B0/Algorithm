import sys

def dfs(start):
    if visit[start]:
        return
        
    visit[start] = True
    
    for next in v[start]:
        dfs(next)
        boss[start].add(next)
        for i in boss[next]:
            boss[start].add(i)

N,M,I = map(int, input().split())
age = [0]
age.extend(list(map(int, input().split())))
v = [[] for _ in range(N+1)]
boss = [set() for _ in range(N+1)]
parent = [0]*(N+1)
pos = [0]*(N+1)

for i in range(1,N+1):
    parent[i] = i
    pos[i] = i
    
for _ in range(M):
    a,b = map(int ,input().split())
    v[b].append(a)
# print(v)
answer = 1e9
visit = [False] * (N+1)

for i in range(1, N+1):
    dfs(i)
# print(boss)

for _ in range(I):
    arr = list(input().split())
    # print(arr)
    if arr[0]=='T':
        a = int(arr[1])
        b = int(arr[2])
        pos[a],pos[b] = pos[b],pos[a]
        parent[pos[a]]=a
        parent[pos[b]]=b
    else:
        a = int(arr[1])
        a = pos[a]
        answer = 1e9
        for b in boss[a]:
            answer = min(answer, age[parent[b]])
        print('*' if answer==1e9 else answer)