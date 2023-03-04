import math
N=int(input())
100000000
arr=[1,9,90,900,9000]
answer=0
num=int(math.log10(N))
#print(num)
for i in range(0,num):
    answer+=(i+1)*(9*int(math.pow(10,i)))
answer+=(N-int(math.pow(10,num))+1)*(num+1)
print(answer)
