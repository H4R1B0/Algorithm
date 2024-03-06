from collections import Counter

n,d,k,c = map(int,input().split())
arr = [int(input()) for _ in range(n)]
cnt = {}
for num in arr[:k]:
    if num not in cnt:
        cnt[num]=0
    cnt[num]+=1
# print(len(cnt))
if c not in cnt:
    answer = len(cnt)+1
else:
    answer = len(cnt)
for i in range(1,n):
    e = (i+k-1)%n
    if arr[e] not in cnt:
        cnt[arr[e]]=0
    cnt[arr[e]]+=1
    cnt[arr[i-1]]-=1
    if cnt[arr[i-1]]==0:
        del cnt[arr[i-1]]
    if c not in cnt:
        answer = max(answer,len(cnt)+1)
    else:
        answer = max(answer,len(cnt))
    # print(cnt)
print(answer)