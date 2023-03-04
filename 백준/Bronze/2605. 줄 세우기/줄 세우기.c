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
	int arr[100],i,j,a,b;
	for(i=0;i<100;i++)
		arr[i]=i+1;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&b);
		if(b==0)
			continue;
		else
		{
			for(j=0;j<b;j++)
				swap(&arr[i-j],&arr[i-j-1]);
		}
	}
	for(i=0;i<a;i++)
		printf("%d ",arr[i]);
}
