def make_pi(pattern):
    M = len(pattern)
    pi = [0] * M
    j = 0
    for i in range(1, M):
        while j > 0 and pattern[i] != pattern[j]:
            j = pi[j-1]
        if pattern[i] == pattern[j]:
            j += 1
            pi[i] = j
    return pi

def kmp(text, pattern):
    N = len(text)
    M = len(pattern)
    pi = make_pi(pattern)
    answer = []
    j = 0
    for i in range(N):
        while j > 0 and text[i] != pattern[j]:
            j = pi[j-1]
        if text[i] == pattern[j]:
            if j == M-1:
                answer.append(i - M + 2) # 자바와 다르게 파이썬은 0이 아닌 1부터 시작하는 인덱스를 사용합니다.
                j = pi[j]
            else:
                j += 1
    return answer

text = input()
pattern = input()
answer = kmp(text, pattern)
print(len(answer))
for ans in answer:
    print(ans, end=' ')