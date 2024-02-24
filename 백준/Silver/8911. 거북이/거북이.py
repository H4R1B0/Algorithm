T = int(input())
for _ in range(T):
    x, y, dir = 0, 0, 0
    max_x, min_x = 0, 0
    max_y, min_y = 0, 0
    cmd = list(input())
    for i in cmd:
        if i == 'F':
            if dir == 0:
                y += 1
            elif dir == 1:
                x += 1
            elif dir == 2:
                y -= 1
            else:
                x -= 1
        elif i == 'B':
            if dir == 0:
                y -= 1
            elif dir == 1:
                x -= 1
            elif dir == 2:
                y += 1
            else:
                x += 1
        elif i == 'L':
            dir = (dir+3)%4
        elif i == 'R':
            dir = (dir+1)%4
    
        max_x, max_y = max(max_x, x), max(max_y, y)
        min_x, min_y = min(min_x, x), min(min_y, y)

    print((abs(max_y) + abs(min_y)) * (abs(max_x) + abs(min_x)))