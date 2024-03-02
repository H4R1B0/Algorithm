def gcd(a,b):
    if a%b==0:
        return b
    return gcd(b,a%b)

a,b = map(int,input().split(':'))
c = gcd(a,b)
print('%d:%d' % (a//c,b//c))