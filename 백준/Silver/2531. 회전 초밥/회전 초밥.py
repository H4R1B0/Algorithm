from collections import Counter

n,d,k,c = map(int,input().split())
arr = [int(input()) for _ in range(n)]
arr = arr+arr[:-1]
# print(arr)
answer = 0
for i in range(n):
    tmp = dict(Counter(arr[i:i+k]))
    # print(len(tmp))
    if c in tmp:
        answer = max(answer,len(tmp))
    else:
        answer = max(answer,len(tmp)+1)
print(answer)