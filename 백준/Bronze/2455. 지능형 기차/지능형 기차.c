#include <stdio.h>
int main()
{
	int a,b,sum=0,i,max;
	max=sum;
	for(i=1;i<=4;i++)
	{
		scanf("%d %d",&a,&b);
		sum=sum+b-a;
		if(max<sum)
			max=sum;
	}
	printf("%d",max);
}