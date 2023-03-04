args=input();
list=args.split(' ');
num1=list[0];
num2=list[1];
print(int(str(int(num1[::-1])+int(num2[::-1]))[::-1]));