#include <stdio.h>
int main()
{
	int a,b,i,sum=0,j=1;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&b);
		if(b==1)
		{
			sum+=j;
		}
		j++;
		if(b==0)
			j=1;
		
	}
	printf("%d",sum);
}
