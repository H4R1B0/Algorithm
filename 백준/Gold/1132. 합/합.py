n = int(input())
a = [[0, False] for _ in range(10)]
ans = 0
for _ in range(n):
    s = input()
    m = 1
    a[ord(s[0])-65][1] = True
    for c in s[::-1]:
        a[ord(c)-65][0] += m
        m *= 10
a.sort(reverse=True)
if a[9][1]:
    for i in range(8, -1, -1):
        if not a[i][1]:
            del a[i]
            break

# print(a)
for i in range(9):
    ans += a[i][0] * (9-i)

print(ans)