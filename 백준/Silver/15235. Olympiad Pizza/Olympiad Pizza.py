n = int(input())
cnt = list(map(int, input().split()))
q = list(range(n))
# print(q)
answer = [0]*n
time = 0
while q!=[]:
    cur = q.pop(0)
    time+=1
    cnt[cur]-=1
    if cnt[cur]==0:
        answer[cur]=time
    else:
        q.append(cur)
print(' '.join(map(str, answer)))