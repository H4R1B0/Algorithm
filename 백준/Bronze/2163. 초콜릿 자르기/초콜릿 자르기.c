#include <stdio.h>
int main()
{
	int a,b,max,min;
	scanf("%d %d",&a,&b);
	if(a>b)
	{
		max=a;
		min=b;
	}
	else 
	{
		max=b;
		min=a;
	}
	printf("%d",max-1+(min-1)*max);
}