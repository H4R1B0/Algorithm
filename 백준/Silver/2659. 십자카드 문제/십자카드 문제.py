import sys

nums = list(map(int, input().split()))

def get_num(n):
    min_ = 10000
    for i in range(4):
        tmp = int(''.join(map(str, n[i:]+n[:i])))
        min_ = min(min_,tmp)
    return min_

num = get_num(nums)
cnt = 1
for i in range(1111, num):
    if '0' not in list(str(i)) and i == get_num(list(map(int, str(i)))):
        cnt += 1
print(cnt)