#include <stdio.h>
int main()
{
	int a,arr[1000],i,j,brr[1000]={0,},max,sum=0,avg;
	for(i=0;i<1000;i++)
	{
		arr[i]=(i+1)*10;
	}
	for(i=0;i<10;i++)
	{
		scanf("%d",&a);
		sum+=a;
		for(j=0;j<1000;j++)
		{
			if(arr[j]==a)
			{
				brr[j]++;
			}
		}
	}
	max=brr[0];
	for(i=0;i<1000;i++)
	{
		if(max<brr[i])
		{
			max=brr[i];
			j=i;
		}
	}
	avg=sum/10;
	printf("%d\n%d\n",avg,arr[j]);
	return 0;
}