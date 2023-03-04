#include <stdio.h>
int n=0;
void f(int a)
{
	int i,m=0;
	for(i=1;i<=a;i++)
    {
        if(a%i==0)
		{
			m++;

		}
    }
	if(m==2)
		n++;
	
}
int main()
{
    int a,b,i;
	scanf("%d",&a);
    for(i=0;i<a;i++)
	{
		scanf("%d",&b);
		f(b);
	}
	printf("%d",n);
    return 0;
}