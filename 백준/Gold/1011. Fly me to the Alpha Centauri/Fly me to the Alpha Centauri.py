import sys
import math
input = sys.stdin.readline

def get_answer(a,b):
    diff = b-a
    d = int(math.sqrt(diff))
    # print(d)
    if d**2==diff:
        cnt = d*2-1
    else:
        cnt = d*2
    if diff>d*(d+1):
        cnt+=1
    return cnt

for _ in range(int(input())):
    a,b = map(int,input().split())
    print(get_answer(a,b))