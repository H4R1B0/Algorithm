N,M = map(int,input().split())
arr = [int(input()) for _ in range(N)]

# print(arr)
left = 0
right = 0
arr.sort()
answer = 2e9
while right < N:
    diff = arr[right]-arr[left]
    if diff < M:
        right+=1
    elif diff > M:
        answer = min(answer,diff)
        left+=1
    else:
        answer = M
        break
print(answer)