n = int(input())
if n%10!=0:
    print(-1)
else:
    arr = [0]*3
    arr[0]+=n//300
    n%=300
    arr[1]+=n//60
    n%=60
    arr[2]+=n//10
    print(arr[0],arr[1],arr[2])