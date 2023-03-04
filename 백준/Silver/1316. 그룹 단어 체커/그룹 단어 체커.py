T=int(input())
cnt=0
for _ in range(T):
    word=input()
    arr=[word[0]]
    dic={}
    prev=word[0]
    for i in range(1,len(word)):
        if prev!=word[i]:
            arr.append(word[i])         
            prev=word[i]
        else:
            pass
    for i in arr:
        if i not in dic:
            dic[i]=1
        else:
            break
    else:
        cnt+=1
print(cnt)
