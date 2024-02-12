T = int(input())
for _ in range(T):
    answer=['',0]
    n = int(input())
    for _ in range(n):
        a,b=input().split()
        if answer[1]<int(b):
            answer[0]=a
            answer[1]=int(b)
    print(answer[0])