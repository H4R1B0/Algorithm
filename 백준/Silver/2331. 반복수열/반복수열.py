A,P=map(int,input().split())
arr=[A]

for i in arr:
    sum=0
    for j in list(str(i)):
        j=int(j)
        sum+=int(pow(j,P))
    if sum in arr:
        arr=arr[:arr.index(sum)]
        break
    arr.append(sum)
print(len(arr))
