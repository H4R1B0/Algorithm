def get_answer(str):
    left = 0
    right = len(str)-1
    while left<right:
        if str[left] == str[right]:
            left += 1
            right -= 1
        else:
            tmp1 = str[:right]+str[right+1:]
            tmp2 = str[:left]+str[left+1:]
            if tmp1[:] == tmp1[::-1] or tmp2[:] == tmp2[::-1]:
                return 1
            return 2
    return 0

t = int(input())
for _ in range(t):
    str = input()
    print(get_answer(str))