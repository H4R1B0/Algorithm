#include <stdio.h>
int main()
{
	int a,b,i,max=1;
	scanf("%d %d",&a,&b);
	for(i=1;i<=a;i++)
	{
		if(a%i==0 && b%i==0)
			if(max<i)
				max=i;
	}

	printf("%d %d",max,a*b/max);
}