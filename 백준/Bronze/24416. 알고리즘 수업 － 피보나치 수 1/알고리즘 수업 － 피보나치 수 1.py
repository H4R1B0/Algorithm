def f1(n):
    a,b = 1,1
    for _ in range(3,n+1):
        a,b = b,a+b
    return b

n = int(input())
print(f1(n), n-2)