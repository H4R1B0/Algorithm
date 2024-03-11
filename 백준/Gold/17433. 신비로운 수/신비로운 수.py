import sys
import math
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    v = list(map(int, input().split()))
    m = min(v)
    t = [v[k]-m for k in range(n) if v[k]!=m]
    if len(t)==0:
        print('INFINITY')
        continue
    answer = t[0]
    for i in t[1:]:
        answer = math.gcd(answer,i)
    print(answer)