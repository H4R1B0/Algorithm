n,k,q = map(int,input().split())
for _ in range(q):
    a,b = map(int,input().split())
    if k==1:
        print(abs(b-a))
    else:
        cnt = 0
        while a!=b:
            while a>b:
                cnt+=1
                a = (a+k-2)//k
            while a<b:
                cnt+=1
                b = (b+k-2)//k
        print(cnt)