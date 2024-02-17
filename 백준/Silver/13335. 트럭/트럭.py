n,w,L = map(int, input().split())
arr = list(map(int, input().split()))

q = []
sum = 0
answer = 0
for i in range(n):
    while True:
        if len(q)==w:
            sum-=q.pop(0)
        if sum+arr[i]<=L:
            break
        q.append(0)
        answer+=1
    q.append(arr[i])
    sum+=arr[i]
    answer+=1
print(answer+w)