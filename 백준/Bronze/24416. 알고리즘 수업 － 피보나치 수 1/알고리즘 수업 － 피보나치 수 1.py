def f1(n):
    global answer1
    if n==1 or n==2:
        answer1+=1
        return 1
    return f1(n-1)+f1(n-2)

def f2(n):
    global answer2
    arr = [0]*42
    arr[1] = 1
    arr[2] = 1
    for i in range(3,n+1):
        arr[i] = arr[i-1]+arr[i-2]
        answer2+=1
answer1,answer2 = 0,0
n = int(input())
f1(n)
f2(n)
print(answer1, answer2)