args=input();
args_list=args.split(' ');
C=args_list[0];
K=args_list[1];
numC=int(C);
numK=int(K);
def sib(n):
    gob=1;
    for i in range(0,n):
        gob*=10;
    return gob;
print(int((numC+(sib(numK)/2))/sib(numK))*sib(numK));
