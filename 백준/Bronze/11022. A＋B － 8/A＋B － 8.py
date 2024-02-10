n = int(input())
for t in range(1, n+1):
    a, b = map(int, input().split())
    print("Case #%d: %d + %d = %d" %(t, a, b, (a+b)))