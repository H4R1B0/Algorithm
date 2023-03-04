#include <stdio.h>
int main()
{
	char m[][4]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int a,b,i,sum=0;
	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d",&a,&b);
	for(i=0;i<a-1;i++)
		sum+=arr[i];
	sum+=b;
	printf("%s",m[sum%7]);
	
}