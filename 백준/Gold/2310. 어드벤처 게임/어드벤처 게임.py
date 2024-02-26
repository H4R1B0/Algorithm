def dfs(idx, money):
    global answer, visit
    
    if answer:
        return
    if rooms[idx][0]=='L':
        money = max(money, rooms[idx][1])
    elif rooms[idx][0]=='T':
        if rooms[idx][1] > money:
            return
        money -= rooms[idx][1]
    if idx==n-1:
        answer = True
        return
    visit[idx] = True
    for i in rooms[idx][2]:
        if not visit[int(i)-1]:
            dfs(int(i)-1,money)
    visit[idx] = False


while True:
    n = int(input())
    if n==0:
        break
    visit = [False]*n
    rooms = []
    answer = False
    for _ in range(n):
        tmp = input().split()
        rooms.append([ tmp[0], int(tmp[1]), tmp[2:-1] ])
    # print(rooms)
    dfs(0,0)
    if answer:
        print('Yes')
    else:
        print('No')