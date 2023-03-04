#include <stdio.h>
#include <string.h>
int f(int n)
{
	int i,k=1;
	for(i=0;i<n;i++)
		k*=16;
	return k;
}
int main()
{
	char arr[7];
	int i,sum=0,len;
	gets(arr);
	len=strlen(arr);
	for(i=0;len--;i++)
	{
		if(arr[len]>='0' && arr[len]<='9')
			sum+=(arr[len]-'0')*f(i);
		else if(arr[len]=='A')
			sum+=10*f(i);
		else if(arr[len]=='B')
			sum+=11*f(i);
		else if(arr[len]=='C')
			sum+=12*f(i);
		else if(arr[len]=='D')
			sum+=13*f(i);
		else if(arr[len]=='E')
			sum+=14*f(i);
		else if(arr[len]=='F')
			sum+=15*f(i);
	}
	printf("%d",sum);
}