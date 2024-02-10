n = int(input())
if n!=1:
    answer = []
    idx=2
    while n!=1:
        if n%idx==0:
            answer.append(idx)
            n/=idx
            idx=2
        else:
            idx+=1
    print('\n'.join(list(map(str, answer))))