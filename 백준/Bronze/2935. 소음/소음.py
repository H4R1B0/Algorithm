a = input()
c = input()
b = input()
if c=='+':
    answer = [1] + [0]*max(a.count('0'),b.count('0'))
    answer[max(a.count('0'),b.count('0')) - min(a.count('0'),b.count('0'))] += 1
    print(''.join(list(map(str, answer))))
else:
    answer = [1] + [0]*(a.count('0')+b.count('0'))
    print(''.join(list(map(str, answer))))