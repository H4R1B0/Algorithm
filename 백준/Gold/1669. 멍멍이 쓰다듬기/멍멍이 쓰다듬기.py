a,b = map(int,input().split())
if a==b:
    print(0)
else:
    d = int((b-a)**0.5)
    if b-a==d**2:
        print(2*d-1)
    else:
        if b-a>d*(d+1):
            print(2*d+1)
        else:
            print(2*d)