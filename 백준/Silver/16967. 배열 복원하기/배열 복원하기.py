h,w,x,y = map(int, input().split())
arr = [list(map(int,input().split())) for _ in range(h+x)]
# print(arr)
for i in range(x,h):
    for j in range(y,w):
        arr[i][j] -= arr[i-x][j-y]
        if arr[i][j]<0:
            arr[i][j]=0
for i in range(h):
    print(' '.join(map(str, arr[i][:w])))