#include <stdio.h>
int main()
{
	int a,b,k,c,d,e;
	scanf("%d %d",&a,&b);
	c=a/100;
	d=a%100/10;
	e=a%10;
	a=e*100+d*10+c;
	c=b/100;
	d=b%100/10;
	e=b%10;
	b=e*100+d*10+c;
	if(a>b)
		printf("%d",a);
	else
		printf("%d",b);
}
