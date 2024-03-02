for _ in range(int(input())):
    a,b = input().split()
    a = list(a)
    a.sort()
    b = list(b)
    b.sort()
    if a==b:
        print("Possible")
    else:
        print("Impossible")