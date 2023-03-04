#include <stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int a,i,j,n[1000];
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&n[i]);
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		{
			if(n[i]<n[j])
				swap(&n[i],&n[j]);
		}
	}
	for(i=0;i<a;i++)
	{
		printf("%d ",n[i]);
	}
}