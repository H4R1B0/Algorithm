def add(dic, arr):
    if len(arr)==0:
        return
    if arr[0] not in dic:
        dic[arr[0]] = {}
    add(dic[arr[0]],arr[1:])

def dfs(dic, cnt):
    # print(sorted(dic.keys()))
    for i in sorted(dic.keys()):
        print('--'*cnt + i)
        dfs(dic[i],cnt+1)

n = int(input())
arr = [list(input().split()) for _ in range(n)]
# print(arr)
dic = {}
for i in arr:
    # print(i)
    add(dic,i[1:])
# print(dic)
dfs(dic, 0)