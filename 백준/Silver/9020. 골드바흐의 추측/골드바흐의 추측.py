import math 
 
def getPrime(number): 
    if number == 2: 
        return 1;
    for x in range(2,number): 
        if number % x == 0: 
            return 0;
        elif (x > math.sqrt(number)):
            return 1;
N=input();
for i in range(int(N)):
    num=input();
    for i in range(int(int(num)/2),int(num)):
        if(getPrime(i)==1 and getPrime(int(num)-i)==1):
            print(str(int(num)-i)+' '+str(i));
            break;
