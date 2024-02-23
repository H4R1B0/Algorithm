def rotate(block):
    return list(zip(*block[::-1]))

def is_attachable(x, y, sticker):
    r, c = len(sticker), len(sticker[0])
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1 and notebook[x+i][y+j] == 1:
                return False
    return True

def attach(x, y, sticker):
    r, c = len(sticker), len(sticker[0])

    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1:
                notebook[x+i][y+j] = 1

n, m, k = map(int, input().split())
notebook = [[0] * m for _ in range(n)]
stickers = [{} for _ in range(k)]
for i in range(k):
    r, c = map(int, input().split())
    stickers[i]['r'], stickers[i]['c'] = r, c
    stickers[i]['sticker'] = [list(map(int, input().split())) for _ in range(r)]
for i in range(k):
    r,c = stickers[i]['r'],stickers[i]['c']
    current_sticker = stickers[i]['sticker']
    for _ in range(4):
        if r > n or c > m:
            r,c,current_sticker = c,r,rotate(current_sticker)
            continue
        is_attached = False
        for i in range(n - r + 1):
            for j in range(m - c + 1):
                if is_attachable(i, j, current_sticker):
                    attach(i, j, current_sticker)
                    is_attached = True
                    break
            if is_attached:
                    break                
        if is_attached:
            break
        else:
            r,c,current_sticker = c,r,rotate(current_sticker)
answer = 0
for i in range(n):
    for j in range(m):
        if notebook[i][j]==1:
            answer+=1
print(answer)