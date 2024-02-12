import math

while(True):
    n = int(input())
    arr = [1]
    if n==-1:
        break
    # sum=0
    for i in range(2, int(math.sqrt(n))+1):
        if n%i==0:
            arr.append(i)
            arr.append(n//i)
    if sum(arr)!=n:
        print('%d is NOT perfect.' % n)
    else:
        arr.sort()
        print('%d = %s' % (n, ' + '.join(map(str, arr))))
    # print(arr)