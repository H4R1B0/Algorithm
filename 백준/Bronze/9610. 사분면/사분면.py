n = int(input())
arr = [0]*5
for i in range(1, n+1):
    a,b = map(int, input().split())
    if a==0 or b==0:
        arr[4]+=1
    elif a>0 and b>0:
        arr[0]+=1
    elif a<0 and b>0:
        arr[1]+=1
    elif a<0 and b<0:
        arr[2]+=1
    elif a>0 and b<0:
        arr[3]+=1
# print(arr)
print('Q1: %d' % arr[0])
print('Q2: %d' % arr[1])
print('Q3: %d' % arr[2])
print('Q4: %d' % arr[3])
print('AXIS: %d' % arr[4])