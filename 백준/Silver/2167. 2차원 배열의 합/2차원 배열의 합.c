#include <stdio.h>
int main()
{
	int arr[300][300]={0};
	int i,j,x,y,a,b,c,h,sum;
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	scanf("%d",&c);
	for(h=0;h<c;h++)
	{
		scanf("%d %d %d %d",&i,&j,&x,&y);
		sum=0;
		for(a=i-1;a<x;a++)
		{
			for(b=j-1;b<y;b++)
			{
				sum+=arr[a][b];
			}
		}
		printf("%d\n",sum);
	}
}