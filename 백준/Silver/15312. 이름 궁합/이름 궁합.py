alp = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]
A = list(input())
B = list(input())
arr = []
for i in range(len(A)):
    arr.append(alp[ord(A[i])-65])
    arr.append(alp[ord(B[i])-65])

while len(arr)!=2:
    for i in range(len(arr)-1):
        arr[i] = (arr[i]+arr[i+1])%10
    arr = arr[:-1]
print("%d%d" % (arr[0],arr[1]))