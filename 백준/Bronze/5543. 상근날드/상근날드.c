#include <stdio.h>
int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
int main()
{
	int a,b,c,d,e,min1,min2;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	min1=min(a,min(b,c));
	min2=min(d,e);
	printf("%d",min1+min2-50);
}