#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[1000];
	while(n--)
	{
		int m;
		scanf("%d",&m);
		int sum=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		double avg=(double)sum/m;
		int num=0;
		for(int i=0;i<m;i++)
		{
			if(arr[i]>avg)
				num++;
		}
		printf("%.3f%%\n",(double)num/m*100);
	}
}