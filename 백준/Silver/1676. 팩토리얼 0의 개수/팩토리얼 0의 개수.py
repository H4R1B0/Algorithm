num=input();
count=0;
gob=1;
for i in range(1,int(num)+1):
    gob*=i;
gob_rev=str(gob)[::-1];
for i in range(0,len(gob_rev)):
    if(gob_rev[i]=='0'):
        count+=1;
    else:
        break;
print(count);