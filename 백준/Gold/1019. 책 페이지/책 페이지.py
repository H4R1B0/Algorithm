def cal(x,k):
    while x > 0:
        answer[x%10] += k
        x //= 10

answer = [0]*10
end = int(input())
start = 1
k = 1
while start<=end:
    while end%10!=9:
        cal(end,k)
        end-=1
    if end<start:
        break
    while start%10!=0:
        cal(start,k)
        start+=1
    start //= 10
    end //= 10
    for i in range(10):
        answer[i] += (end-start+1)*k
    k *= 10
print(' '.join(map(str,answer)))