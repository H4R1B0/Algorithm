#include <stdio.h>
char* grade[9]={"A+","A","B+","B","C+","C","D+","D","F"};
int num[]={97,90,87,80,77,70,67,60,0};
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a=0,b;
		char s[10];
		scanf("%s %d",&s,&b);
		while(num[a]>b)
			a++;
		printf("%s %s\n",s,grade[a]);
	}
}