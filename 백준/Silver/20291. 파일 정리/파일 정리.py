t = int(input())
dic = {}
for _ in range(t):
    str = input().split('.')[1]
    # print(str)
    if str not in dic:
        dic[str]=1
    else:
        dic[str]+=1
sorted_dic = sorted(dic.items())
# print(len(sorted_dic))
for x in sorted_dic:
    print('%s %d' % (x[0],x[1]))