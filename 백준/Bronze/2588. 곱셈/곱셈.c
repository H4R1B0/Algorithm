#include <stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d %d",&a,&b);
	c=a*(b%10);
	d=a*((b%100)/10);
	e=a*(b/100);
	printf("%d\n%d\n%d\n%d",c,d,e,a*b);
}