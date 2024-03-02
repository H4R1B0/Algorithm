import re

t = int(input())
p = re.compile('(100+1+|01)+')
for _ in range(t):
    str = input()
    m = p.fullmatch(str)
    if m:
        print("YES")
    else:
        print("NO")