#include <stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d %d %d",&a,&b,&c);
	d=c/60;
	e=c%60;
	printf("%d %d",(a+d+(b+e)/60)%24,(b+e)%60);
}
