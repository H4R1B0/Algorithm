import re

def is_slump(str):
    return re.fullmatch('((D|E)(F)+)+(G)',str) is not None

def is_slimp(str):
    if len(str) > 3:
        if re.fullmatch('(AB)\w+(C)', str):
            return is_slimp(str[2:-1])
        elif re.fullmatch('(A)\w+(C)', str):
            return is_slump(str[1:-1])
    return str=='AH'

def get_answer(s):
    res = False
    for i in range(2, len(s) - 2):
        s1 = s[:i]
        s2 = s[i:]
        if is_slimp(s1) and is_slump(s2):
            return 'YES'
    return 'NO'

print('SLURPYS OUTPUT')
for _ in range(int(input())):
    s = input()
    print(get_answer(s))
print('END OF OUTPUT')