import sys
input = sys.stdin.readline

def gcd(a,b):
    if a%b==0:
        return True
    elif a<2*b:
        return not gcd(b,a-b)
    return True    

while True:
    a,b = map(int,input().split())
    if a==0 and b==0:
        break
    if a<b:
        a,b = b,a
    if gcd(a,b):
        print('A wins')
    else:
        print('B wins')