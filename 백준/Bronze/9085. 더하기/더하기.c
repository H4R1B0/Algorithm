#include <stdio.h>
int main()
{
	int a,b,c,i,j,sum;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&b);
		sum=0;
		for(j=0;j<b;j++)
		{
			scanf("%d",&c);
			sum+=c;
		}
		printf("%d\n",sum);
	}
}