n = int(input())
answer = 0
for _ in range(n):
    dic = {}
    arr = list(map(int, input().split()))
    for i in arr:
        if i in dic:
            dic[i]+=1
        else:
            dic[i]=1
    # print(dic)
    for key, value in dic.items():
        if value==3:
            answer = max(answer, 10000+key*1000)
            break
        elif value==2:
            answer = max(answer, 1000+key*100)
            break
        else:
            answer=max(answer, 100*key)
print(answer)