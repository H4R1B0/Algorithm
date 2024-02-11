s = int(input())
i = 1
while(True):
    if i*(i+1)//2 <= s and s<(i+1)*(i+2)//2:
        print(i)
        break
    i+=1