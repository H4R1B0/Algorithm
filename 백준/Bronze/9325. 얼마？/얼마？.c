#include <stdio.h> 
int main()
{
	int a,i,j,sum,b,c,d,e;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		sum=0;
		scanf("%d",&b);
		sum+=b;
		scanf("%d",&c);
		for(j=0;j<c;j++)
		{
			scanf("%d %d",&d,&e);
			sum+=d*e;
		}
		printf("%d\n",sum);
	}
} 