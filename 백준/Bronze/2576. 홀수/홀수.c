#include <stdio.h>
int main()
{
	int i,a[7],min,sum=0;
	for(i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<7;i++)
	{
		if(a[i]%2!=0)
		{
			min=a[i];
			break;
		}
	}
	for(i=0;i<7;i++)
	{
		if(min>a[i] && a[i]%2!=0)
		{	
			min=a[i];
		}
		if(a[i]%2!=0)
			sum+=a[i];
	}
	if(min%2==0)
		printf("-1");
	else 
		printf("%d\n%d",sum,min);
}