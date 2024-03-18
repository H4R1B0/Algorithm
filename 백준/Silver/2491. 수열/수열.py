n = int(input())
arr = list(map(int,input().split()))

len1,len2 = 1,1
answer = 1
for i in range(n-1):
    if arr[i]<=arr[i+1]:
        len1 += 1
    else:
        len1 = 1
    if arr[i]>=arr[i+1]:
        len2 += 1
    else:
        len2 = 1
    answer = max(answer,len1,len2)

print(answer)