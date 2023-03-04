#include <stdio.h>
int main()
{
	int i,arr[4],sum=0;
	for(i=0;i<3;i++)
	{
		scanf("%d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3]);
		sum=arr[0]+arr[1]+arr[2]+arr[3];
		if(sum==0)
			printf("%c\n",'D');
		else if(sum==1)
			printf("%c\n",'C');
		else if(sum==2)
			printf("%c\n",'B');
		else if(sum==3)
			printf("%c\n",'A');
		else if(sum==4)
			printf("%c\n",'E');
	}
}