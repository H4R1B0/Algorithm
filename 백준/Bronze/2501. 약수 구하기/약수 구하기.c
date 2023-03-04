#include <stdio.h>
int main()
{
	int a,b,i,j=0,k;
	scanf("%d %d",&a,&b);
	for(i=1;i<=a;i++)
	{
		if(a%i==0)
		{
			b--;
			j++;
		}
		if(b==0)
		{
			printf("%d",i);
			break;
		}

	}
	if(b!=0)
		printf("0");
}
