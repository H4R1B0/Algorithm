import sys
input = sys.stdin.readline

N, C =  map(int, input().split())
M = int(input())
arr = []
for _ in range(M):
    s, e, box = map(int, input().split())
    arr.append((s, e, box))
arr.sort(key=lambda x :  x[1])
# print(arr)
capa = [C]*N
total = 0
for s, e, box in arr:
    # print(capa)
    _min = C
    for i in range(s, e):
        if _min > min(capa[i], box):
            _min = min(capa[i], box)
    # print(_min)
    for i in range(s, e):
        capa[i] -= _min
    total += _min
print(total)