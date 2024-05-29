n = int(input())
cnt = 0
for i in range(1, n+1):
    for j in range(i, n+1):
        k = n - i - j
        if k >= i + j:
            continue
        else:
            if j > k:
                break
            cnt += 1
print(cnt)