from collections import deque

T = int(input())
for _ in range(T):
    N,M = map(int,input().split())
    q = deque(list(map(int,input().split())))
    # print(arr)
    answer = 0
    while q:
        num = max(q)
        front = q.popleft()
        M-=1

        if num==front:
            answer+=1
            if M<0:
                print(answer)
                break
        else:
            q.append(front)
            if M<0:
                M = len(q)-1