d,k = map(int,input().split())

A = [0]*(d+1)
B = [0]*(d+1)
A[1] = 1
A[2] = 0
B[1] = 0
B[2] = 1
for i in range(3,d+1):
    A[i] = A[i-1]+A[i-2]
    B[i] = B[i-1]+B[i-2]

# print(A)
# print(B)

for i in range(1,k+1):
    num = k-A[d]*i
    if num%B[d]==0:
        print(i)
        print(num//B[d])
        break