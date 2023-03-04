#include <stdio.h>
int main()
{
	char a[8][8];
	int i,j,n=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			scanf(" %c",&a[i][j]);
		}
	}
	for(i=0;i<8;i+=2)
	{
		for(j=0;j<8;j+=2)
		{
			if(a[i][j]=='F')
				n++;
		}
	}
	for(i=1;i<8;i+=2)
	{
		for(j=1;j<8;j+=2)
		{
			if(a[i][j]=='F')
				n++;
		}
	}
	printf("%d",n);
}