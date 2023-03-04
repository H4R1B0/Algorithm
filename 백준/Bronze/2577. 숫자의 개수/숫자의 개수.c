#include <stdio.h>
int f(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
		b*=10;
	return b;
}
int main()
{
	int a,b,c,gob,i,arr[10],brr[10]={0,};
	scanf("%d %d %d",&a,&b,&c);
	gob=a*b*c;
	for(i=0;i<10;i++)
		arr[i]=(gob/f(i))%10;
	for(i=0;i<10;i++)
	{
		if(gob/f(i)==0)
			continue;
		if(arr[i]==0)
			brr[0]++;
		else if(arr[i]==1)
			brr[1]++;
		else if(arr[i]==2)
			brr[2]++;
		else if(arr[i]==3)
			brr[3]++;
		else if(arr[i]==4)
			brr[4]++;
		else if(arr[i]==5)
			brr[5]++;
		else if(arr[i]==6)
			brr[6]++;
		else if(arr[i]==7)
			brr[7]++;
		else if(arr[i]==8)
			brr[8]++;
		else if(arr[i]==9)
			brr[9]++;
	}
	for(i=0;i<10;i++)
		printf("%d\n",brr[i]);
}
