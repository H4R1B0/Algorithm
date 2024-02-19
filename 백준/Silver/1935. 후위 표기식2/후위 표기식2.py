n = int(input())
arr = input()
num = [0]*n
for i in range(n):
    num[i] = int(input())
stack = []
for i in arr:
    if 'A'<=i<='Z':
        stack.append(num[ord(i)-ord('A')])
    else:
        b = stack.pop()
        a = stack.pop()
        stack.append(eval(''.join(str(a)+i+str(b))))
print('%.2f' %stack[0])