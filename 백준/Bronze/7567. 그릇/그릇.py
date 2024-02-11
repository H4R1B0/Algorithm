arr = input()
answer = 10
for i in range(len(arr)-1):
    if arr[i]==arr[i+1]:
        answer += 5
    else:
        answer += 10
print(answer)