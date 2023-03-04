#include <stdio.h>
int max(int a,int b)
{
	return a>=b ? a:b;
}
int main()
{
	int n,i,a=0,b=0,c=0,MAX;
	char arr[100];
	scanf("%d",&n);
	scanf("%s",arr);
	for(i=0;i<n;i++)
	{
		if(i%3==0)
			if(arr[i]=='A')
				a++;
		if(i%3==1)
			if(arr[i]=='B')
				a++;
		if(i%3==2)
			if(arr[i]=='C')
				a++;
	}
	for(i=0;i<n;i++)
	{
		if(i%4==0)
			if(arr[i]=='B')
				b++;
		if(i%4==1)
			if(arr[i]=='A')
				b++;
		if(i%4==2)
			if(arr[i]=='B')
				b++;
		if(i%4==3)
			if(arr[i]=='C')
				b++;
	}
	for(i=0;i<n;i++)
	{
		if(i%6==0)
			if(arr[i]=='C')
				c++;
		if(i%6==1)
			if(arr[i]=='C')
				c++;
		if(i%6==2)
			if(arr[i]=='A')
				c++;
		if(i%6==3)
			if(arr[i]=='A')
				c++;
		if(i%6==4)
			if(arr[i]=='B')
				c++;
		if(i%6==5)
			if(arr[i]=='B')
				c++;
	}
	MAX=max(a,max(b,c));
	printf("%d\n",MAX);
	if(MAX==a)
		printf("Adrian\n");
	if(MAX==b)
		printf("Bruno\n");
	if(MAX==c)
		printf("Goran\n");
}
