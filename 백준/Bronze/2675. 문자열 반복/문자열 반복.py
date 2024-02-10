n = int(input())
for _ in range(n):
    a, b = input().split()
    a = int(a)
    answer = ''
    for j in range(len(b)):
        answer += b[j]*a
    print(answer)