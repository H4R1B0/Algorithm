def sum(num):
    cnt = [0]*10
    start = 1
    k = 1
    end = num
    while start<=end:
        while end%10!=9:
            for i in str(end):
                cnt[int(i)]+=k
            end-=1
        if end<start:
            break
        while start%10!=0:
            for i in str(start):
                cnt[int(i)]+=k
            start+=1
        start //= 10
        end //= 10
        for i in range(10):
            cnt[i] += (end-start+1)*k
        k *= 10
    # print(cnt)
    answer = 0
    for i in range(10):
        answer += i*cnt[i]
    return answer
        

a,b = map(int,input().split())
print(sum(b)-sum(a-1))