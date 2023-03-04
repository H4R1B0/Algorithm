#include <stdio.h>
int main()
{
	int i,arr[10];
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<10;i++)
		arr[0]-=arr[i];
	printf("%d",arr[0]);
}