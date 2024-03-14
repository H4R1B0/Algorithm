import sys, heapq
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
    a,b = map(int,input().split())
    arr.append((a,b))

arr.sort(key=lambda x:(x[1]))
# print(arr)
dp = [0]*n
answer = [sys.maxsize]*n
dp[-1]=arr[-1][0]
for i in range(n-2,-1,-1):
    dp[i]=min(dp[i+1],arr[i][0])
# print('dp',dp)
total = 0
for i in range(n):
    answer[i] = min(answer[i],total+dp[i])
    total += arr[i][1]
# print('answer',answer)
q = []
total = 0
for i in range(n):
    # print(answer)
    total += arr[i][1]
    heapq.heappush(q,arr[i][0]-arr[i][1])
    answer[i] = min(answer[i],total+q[0])
    # print(answer)
    # print('---')
    
for i in answer:
    print(i)