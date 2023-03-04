#include <stdio.h>
int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(b==(a+c))
			printf("does not matter\n");
		else if((a+c)<b)
			printf("advertise\n");
		else if((a+c)>b)
			printf("do not advertise\n");
	}
}
