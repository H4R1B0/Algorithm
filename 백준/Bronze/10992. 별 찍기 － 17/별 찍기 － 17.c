#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
		printf("*\n");
	else
	{
		for(int m=0;m<n-1;m++)
			printf(" ");
		printf("*\n");
		for(int i=1;i<n-1;i++)
		{
			for(int k=1;k<n-i;k++)
				printf(" ");
			printf("*");
			for(int j=0;j<i*2-1;j++)
			{
				printf(" ");
			}
			printf("*\n");
		}
		for(int i=0;i<n*2-1;i++)
		printf("*");
	}
}