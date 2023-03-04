#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c;
	double x,y,tmp;
	scanf("%d %d %d",&a,&b,&c);
	tmp=(double)a*a*c*c/(b*b+c*c);
	x=sqrt(tmp);
	y=(double)b/c*x;
	printf("%d %d",(int)y,(int)x);
}
