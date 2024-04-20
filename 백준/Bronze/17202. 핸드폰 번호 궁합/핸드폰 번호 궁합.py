A = list(map(int, input()))
B = list(map(int, input()))
arr = []
for i in range(8):
    arr.append(A[i])
    arr.append(B[i])

# print(arr)

while len(arr) != 2:
    temp = []
    for i in range(len(arr)-1):
        num = (arr[i]+arr[i+1]) % 10
        temp.append(num)
    arr = temp

print(*arr, sep="")