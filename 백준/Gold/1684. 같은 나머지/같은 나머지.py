import math

n = int(input())
v = list(map(int, input().split()))
m = min(v)
t = [v[k]-m for k in range(n) if v[k]!=m]
# print(t)
answer = t[0]
for i in t[1:]:
    answer = math.gcd(answer,i)
print(answer)