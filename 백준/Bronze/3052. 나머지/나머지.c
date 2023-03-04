#include <stdio.h>
int main()
{
	int arr[10],i,brr[42]={0,},k=0;
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<10;i++)
		brr[arr[i]%42]++;
	for(i=0;i<42;i++)
		if(brr[i])
			k++;
	printf("%d",k);
}
