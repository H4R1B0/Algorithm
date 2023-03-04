def cal(arr):
    tmp=arr[:]
    for i in range(len(tmp)):
        tmp[i]+=1
        tmp[i]%=4
    #print(tmp)
    return tmp[::-1]
#print(cal([3,2]))
MAP=[[0]*101 for _ in range(101)]
xd=[0,-1,0,1]
yd=[1,0,-1,0]
N=int(input())
for _ in range(N):
    y,x,d,g=map(int,input().split())
    MAP[x][y]=1
    arr=[d]
    for _ in range(g):
        arr+=cal(arr)
    arr=arr[::-1]
    #print(arr)
    while(True):
        #print(arr)
        if not arr:
            break
        dir=arr.pop()
        x=x+xd[dir]
        y=y+yd[dir]
        MAP[x][y]=1
answer=0
for i in range(100):
    for j in range(100):
        if MAP[i][j]==1 and MAP[i][j+1]==1 and MAP[i+1][j]==1 and MAP[i+1][j+1]==1:
            answer+=1
print(answer)
