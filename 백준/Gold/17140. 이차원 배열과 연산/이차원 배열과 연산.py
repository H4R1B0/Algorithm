from collections import Counter
def rc():
    max_len=0
    len_A=len(A)
    for j in range(len_A):
        a=[i for i in A[j] if i!=0]
        a=Counter(a).most_common()
        a.sort(key=lambda x:(x[1],x[0]))
        A[j]=[]
        for fi,se in a:
            A[j].append(fi)
            A[j].append(se)
        len_a=len(a)
        if max_len<len_a*2:
            max_len=len_a*2
    for j in range(len_A):
        for k in range(max_len-len(A[j])):
            A[j].append(0)
        A[j]=A[j][:100]
            

r,c,k=map(int,input().split())
A=[list(map(int,input().split())) for i in range(3)]
#print(A)
for i in range(101):
    try:
        if A[r-1][c-1]==k:
            print(i)
            break
    except:
        pass
            
    if len(A)<len(A[0]):
        A=list(zip(*A))
        rc()
        A=list(zip(*A))
    else:
        rc()
else:
    print(-1)
