import re
p = re.compile('(100+1+|01)+')
str = input()
m = p.fullmatch(str)
if m:
    print('SUBMARINE')
else:
    print('NOISE')