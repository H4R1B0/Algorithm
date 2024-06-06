import sys
input = sys.stdin.readline

k, l = map(int, input().split())

dict = {}
for i in range(l):
    dict[input().rstrip()] = i

result = sorted(dict.items(), key = lambda x:x[1])

if (k > len(result)):
    k = len(result)

for i in range(k):
    print(result[i][0])