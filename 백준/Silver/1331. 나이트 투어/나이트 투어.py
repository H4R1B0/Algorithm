import sys

dic = {'A':0,'B':1,'C':2,'D':3,'E':4,'F':5,'6':0,'5':1,'4':2,'3':3,'2':4,'1':5}

visit = set()
x,y = input()
x,y = dic[y],dic[x]
s_x,s_y = x,y
visit.add((x,y))
for _ in range(35):
    a,b = input()
    a,b = dic[b],dic[a]
    # print(x,y,a,b)
    if (abs(a-x),abs(b-y)) not in [(1,2),(2,1)] or (a,b) in visit:
        print('Invalid')
        sys.exit()
    x,y = a,b
    visit.add((x,y))
if (abs(s_x-x),abs(s_y-y)) not in [(1,2),(2,1)]:
    print('Invalid')
else:
    print('Valid')