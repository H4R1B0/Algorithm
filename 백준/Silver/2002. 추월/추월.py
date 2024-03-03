from collections import deque

n = int(input())
q = deque()
for _ in range(n):
    q.append(input())
answer = 0
for i in range(n):
    out = input()
    if out != q[0]:
        q.remove(out)
        answer += 1
    else:
        q.popleft()
print(answer)