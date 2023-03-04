N,K=map(int,input().split())
arr=[]

idx=2
for i in range(N):
    for j in range(1,501):
        num=j*idx
        if num<=N and num not in arr:
            arr.append(num)
    idx+=1
#print(len(arr))
print(arr[K-1])
