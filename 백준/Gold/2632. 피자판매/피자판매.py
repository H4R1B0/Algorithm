from collections import defaultdict

def solve(pizza):
    dic = defaultdict(int)
    for i in range(len(pizza)):
        tmp = pizza[i:]+pizza[:i]
        res = 0
        for j in tmp:
            res+=j
            dic[res]+=1
    dic[sum(pizza)]=1
    return dic

k = int(input())
n,m = map(int, input().split())
A = [int(input()) for _ in range(n)]
B = [int(input()) for _ in range(m)]
# print(A)
# print(B)
dic1 = solve(A)
dic2 = solve(B)
# print(dic1)
# print(dic2)
answer = dic1.get(k,0)+dic2.get(k,0)
for i in dic1:
    if k-i in dic2:
        # print(dic1[i], dic2[k-i])
        answer += dic1[i]*dic2[k-i]
print(answer)