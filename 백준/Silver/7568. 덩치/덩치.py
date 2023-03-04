T=int(input())
arr=[]
for _ in range(T):
    x,y=map(int,input().split())
    arr.append([x,y])

answer=[]
for i in arr:
    cnt=1
    for j in arr:
        if i[0]<j[0] and i[1]<j[1]:
            cnt+=1
    answer.append(cnt)

print(' '.join(map(str,answer)))
