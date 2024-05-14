N,K = map(int,input().split())
arr = list(map(int,input().split()))

end = 0
count = 0
answer = 0
tmp = 0
for start in range(N):
    while count<=K and end<N:
        if arr[end]%2:
            count+=1
        else:
            tmp+=1
        end+=1

        if start==0 and end==N:
            answer = tmp
            break

    if count==K+1:
        answer = max(answer,tmp)
    if arr[start]%2:
        count-=1
    else:
        tmp-=1

print(answer)