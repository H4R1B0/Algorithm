#include <stdio.h>
int swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int i,j,ar[5],sum=0,avg;
	for(i=0;i<5;i++)
	{
		scanf("%d",&ar[i]);
		sum+=ar[i];
	}
	avg=sum/5;
	for(i=0;i<5;i++)
	{
		for(j=0;j<=5;j++)
		{
			if(ar[i]<ar[j])
				swap(&ar[i],&ar[j]);
		}
	}
	printf("%d %d",avg,ar[2]);
}