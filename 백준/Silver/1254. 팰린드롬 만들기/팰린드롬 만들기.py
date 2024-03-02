str = input()
for i in range(len(str),0,-1):
    tmp = str+str[:-i][::-1]
    # print(tmp)
    if tmp==tmp[::-1]:
        print(len(tmp))
        break