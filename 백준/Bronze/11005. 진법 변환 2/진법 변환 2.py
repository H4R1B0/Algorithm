def cal(num,N):
    ret=[]
    while(num):
        ret.append(arr[num%N])
        num//=N
    return ret[::-1]
N,B=map(int,input().split())
arr=['0','1','2','3','4','5','6','7','8','9']
for i in range(26):
    arr.append(chr(ord('A')+i))
#print(arr)
print(''.join(cal(N,B)))
