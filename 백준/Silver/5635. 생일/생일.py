N=int(input())
people=[]
for i in range(N):
    name,d,m,y=input().split()
    d,m,y=int(d),int(m),int(y)
    people.append([name,d,m,y])
#people=[input().split() for _ in range(N)]
#print(people)

people.sort(key=lambda x:(x[-1],x[-2],x[-3]))
print(people[-1][0])
print(people[0][0])
