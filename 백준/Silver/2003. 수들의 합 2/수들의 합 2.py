N,M = map(int,input().split())
arr = list(map(int,input().split()))

# print(arr)
left = 0
right = 1
sum = arr[0]
cnt = 0
while True:
    if sum < M:
        if right<N:
            sum += arr[right]
            right+=1
        else:
            break
    elif sum > M:
        sum -= arr[left]
        left+=1
    else:
        cnt+=1
        sum -= arr[left]
        left+=1
print(cnt)