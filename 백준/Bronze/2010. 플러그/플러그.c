#include <stdio.h>
int main()
{
	int a,i,n,sum=0,c=0;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&n);
		sum+=n;
		c++;
	}
	printf("%d",sum-c+1);
}