c=[0 for col in range(27)]
center=-1
s=input()
flag=0
for i in range(len(s)):
    c[ord(s[i])-ord('A')]=s.count(s[i])
for i in range(ord('Z')-ord('A')+1):
    if(c[i]%2):
        if(center==-1):
            center=i
        else:
            print('I\'m Sorry Hansoo')
            flag=1
            break
if(flag==0):
    for i in range(ord('Z')-ord('A')+1):
        if(c[i]):
            for j in range(int(c[i]/2)):
                print(chr(i+ord('A')),end="")
    if(center!=-1):
        print(chr(center+ord('A')),end="")
    for i in reversed(range(0,ord('Z')-ord('A')+1)):
        if(c[i]):
            for j in range(int(c[i]/2)):
                print(chr(i+ord('A')),end="")
