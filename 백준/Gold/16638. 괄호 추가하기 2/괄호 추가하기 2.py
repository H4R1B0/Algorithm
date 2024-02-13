import sys

n = int(input())//2
arr = list(input())
# print(arr)
answer = -sys.maxsize
for bit in range(1<<n):
    if bit&(bit<<1):
        continue
    # print(bit, bit<<1, bit&(bit<<1))
    tmp = arr[:]
    for i in reversed(range(n)):
        if bit&(1<<i):
            tmp.insert(i*2+3, ')')
            tmp.insert(i*2, '(')
    # print(bit)
    # print(''.join(tmp))
    answer = max(answer, eval(''.join(tmp)))
print(answer)