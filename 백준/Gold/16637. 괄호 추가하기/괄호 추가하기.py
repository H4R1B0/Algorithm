def dfs(idx, sum):
    if idx>n-1:
        global answer
        answer = max(answer, sum)
        return
    op = '+' if idx==0 else arr[idx-1]
    dfs(idx+2, get_num(sum, int(arr[idx]), op))
    if idx+2<n:
        num = get_num(int(arr[idx]), int(arr[idx+2]), arr[idx+1])
        dfs(idx+4, get_num(sum, num, op))
    
def get_num(a,b,op):
    if op=='+':
        return a+b
    elif op=='-':
        return a-b
    elif op=='*':
        return a*b
    return -1

n = int(input())
arr = list(input())
# print(arr)
answer = -1e9
dfs(0,0)
print(answer)