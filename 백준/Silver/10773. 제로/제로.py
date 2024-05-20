stk = []

for i in range(int(input())): 
    num = int(input())
    if(num == 0):
        stk.pop()
    else:
        stk.append(num)
print(sum(stk))