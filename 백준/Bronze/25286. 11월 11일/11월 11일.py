T = int(input())
for _ in range(T):
    y,m = map(int,input().split())
    if m==1:
        print(y-1,12,31)
    elif m in [2,4,6,8,9,11]:
        print(y,m-1,31)
    else:
        if m==3:
            if (y%100!=0 and y%4==0) or y%400==0:
                print(y,2,29)
            else:
                print(y,2,28)
        else:
            print(y,m-1,30)
        
