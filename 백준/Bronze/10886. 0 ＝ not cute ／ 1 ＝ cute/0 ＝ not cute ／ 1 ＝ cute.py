n = int(input())
dic = {}
dic[0]=0
dic[1]=0
for _ in range(n):
    num = int(input())
    dic[num]+=1
if dic[0] > dic[1]:
    print('Junhee is not cute!')
else:
    print('Junhee is cute!')