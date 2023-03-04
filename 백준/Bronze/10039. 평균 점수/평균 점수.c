#include <stdio.h>
int main()
{
    int i=5,arr[5],sum=0;
	for(;i--;)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<40)
			sum+=40;
		else
			sum+=arr[i];
	}
	printf("%d",sum/5);
}
