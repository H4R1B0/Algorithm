#include <stdio.h>
int main()
{
	int n,i,j,min;
	scanf("%d",&n);
	min=n;
	for(i=0;i<=n/3;i++)
	{
		for(j=0;j<=n/5;j++)
		{
			if(n==i*3+j*5)
				if(min>(i+j))
					min=i+j;
		}
	}
	if(min==n)
		printf("-1");
	else
		printf("%d",min);
}
