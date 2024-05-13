for _ in range(3):
    n = int(input())
    arr = []
    total = 0
    for _ in range(n):
        money,cnt = map(int,input().split())
        arr.append((money,cnt))
        total += money*cnt
    if total%2==1:
        print(0)
        continue

    answer = 0
    total //= 2
    dp = [True]+[False]*total
    for money,cnt in arr:
        for i in range(total,money-1,-1):
            if dp[i-money]:
                for j in range(cnt):
                    if i+money*j <= total:
                        dp[i+money*j] = True
                    else:
                        break
        if dp[-1]:
            answer = 1
            break
    print(answer)