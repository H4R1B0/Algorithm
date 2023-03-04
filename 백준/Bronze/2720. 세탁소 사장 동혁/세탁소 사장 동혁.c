#include <stdio.h>
int main()
{
	int a,n,i;
	int x,y,z,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		x=a/25;
		a-=x*25;
		y=a/10;
		a-=y*10;
		z=a/5;
		a-=z*5;
		k=a;
		printf("%d %d %d %d\n",x,y,z,k);
	}
}
