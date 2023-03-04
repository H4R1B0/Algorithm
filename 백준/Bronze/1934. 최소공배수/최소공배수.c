#include <stdio.h>
int min(int a, int b)
{
	if(a>b)
		return b;
	else 
		return a;
}
int max(int a,int b)
{
	int i;
	for(i=min(a,b);i>=1;i--)
	{
		if(a%i==0 && b%i==0)
			return i;
	}
}

int main()
{
	int a,b,c,i;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&b,&c);
		printf("%d\n",b*c/max(b,c));
	}
}