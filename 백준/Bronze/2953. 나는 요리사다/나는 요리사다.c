#include <stdio.h>
int main()
{
	int a[5][4],i,j,max=5,k,sum=0;
	for(i=0;i<5;i++)
	{
		sum=0;
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
		if(max<=sum)
		{
			max=sum;
			k=i+1;
		}
	}
	printf("%d %d",k,max);
}