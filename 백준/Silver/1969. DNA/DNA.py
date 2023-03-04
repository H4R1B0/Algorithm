from collections import Counter

def rotate(arr):
    return zip(*arr[::-1])
N,M = map(int,input().split())
DNAs = [input() for _ in range(N)]
DNAs = rotate(DNAs)
answer = N*M
answer_s = ''
for i in DNAs:
    x = Counter(i)
    x = sorted(x.items(), key=lambda k: (-k[1], k[0]))
    #print(x[0][0])
    #print(x)
    answer -= x[0][1]
    answer_s += x[0][0]
    #print(Counter(i).most_common(1)[0][0])
print(answer_s)
print(answer)
