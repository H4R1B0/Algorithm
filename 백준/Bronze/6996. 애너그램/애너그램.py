N=int(input())
for _ in range(N):
    a,b = input().split()
    if sorted(list(a))==sorted(list(b)):
        print(a+' & '+b +' are anagrams.')
    else:
        print(a+' & '+b +' are NOT anagrams.')
