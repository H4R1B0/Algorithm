n = int(input())
for _ in range(n):
    sum = 0
    num = 1
    arr = list(input())
    # print(arr)
    for i in arr:
        if i=='O':
            sum+=num
            num+=1
        else:
            num=1
    print(sum)