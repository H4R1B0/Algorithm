#include <stdio.h>
int main()
{
	int a,b,sum=0,i,max;
	max=sum;
	for(i=1;i<=10;i++)
	{
		scanf("%d %d",&a,&b);
		sum=sum-a;
		if(max<sum)
			max=sum;
		sum=sum+b;
		if(max<sum)
			max=sum;
	}
	printf("%d",max);
}