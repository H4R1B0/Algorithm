def func(l):
    dic = {'1':'3','2':'4','3':'1','4':'2'}
    for i in range(n):
        l[i] = dic[l[i]]
    return l

n = int(input())
arr = list(input().split())
s = set()
for i in range(n):
    tmp = arr[i:]+arr[:i]
    s.add(''.join(tmp))
    s.add(''.join(func(tmp[:][::-1])))
# print(s)
answer = []
for _ in range(int(input())):
    tmp = list(input().split())
    if ''.join(tmp) in s:
        answer.append(tmp)

print(len(answer))
for i in range(len(answer)):
    print(*answer[i])