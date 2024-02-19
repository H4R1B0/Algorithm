n = int(input())
arr = input()
num = [0]*n
for i in range(n):
    num[i] = int(input())
stack = []
for i in arr:
    # print(stack)
    if 'A'<=i<='Z':
        stack.append(num[ord(i)-ord('A')])
    else:
        b = stack.pop()
        a = stack.pop()

        if i =='+' :
            stack.append(a+b)
        elif i == '-' :
            stack.append(a-b)
        elif i == '*' :
            stack.append(a*b)
        elif i == '/' :
            stack.append(a/b)
print('%.2f' %stack[0])