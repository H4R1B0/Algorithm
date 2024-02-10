n = int(input())
for _ in range(n):
    arr = list(input().split())
    # print(arr)
    num = float(arr[0])
    for i in range(1, len(arr)):
        if arr[i]=='@':
            num *= 3
        elif arr[i]=='%':
            num += 5
        elif arr[i]=='#':
            num -= 7
    print(f'{num:.2f}')