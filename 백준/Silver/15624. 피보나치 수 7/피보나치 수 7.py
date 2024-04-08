MOD = 1000000007

a,b,c = 0,1,1
n = int(input())
for i in range(n):
    c = b+a
    a,b = b,c
    a %= MOD
    b %= MOD
    c %= MOD
    
print(a)