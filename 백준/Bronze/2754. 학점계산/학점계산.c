#include <stdio.h>
int main()
{
	char n,m;
	scanf("%c",&n);
	if(n=='A' || n=='B' || n=='C' || n=='D')
		scanf("%c",&m);
	if(n=='A')
	{
		if(m=='+')
			printf("4.3");
		else if(m=='0')
			printf("4.0");
		else if(m=='-')
			printf("3.7");
	}
	if(n=='B')
	{
		if(m=='+')
			printf("3.3");
		else if(m=='0')
			printf("3.0");
		else if(m=='-')
			printf("2.7");
	}
	if(n=='C')
	{
		if(m=='+')
			printf("2.3");
		else if(m=='0')
			printf("2.0");
		else if(m=='-')
			printf("1.7");
	}
	if(n=='D')
	{
		if(m=='+')
			printf("1.3");
		else if(m=='0')
			printf("1.0");
		else if(m=='-')
			printf("0.7");
	}
	if(n=='F')
		printf("0.0");
	return 0;
}