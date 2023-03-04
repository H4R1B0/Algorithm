#include <stdio.h>
int main()
{
	int a[8],i,k=0,j=0;
	for(i=0;i<8;i++)
		scanf("%d",&a[i]);
	for(i=0;i<8;i++)
	{
		if(a[i]==i+1)
			k++;
		
		if(a[i]==8-i)
			j++;
		
	}
	if(k==8)
		printf("ascending");
	else if(j==8)
		printf("descending");
	
	else
		printf("mixed");
}
