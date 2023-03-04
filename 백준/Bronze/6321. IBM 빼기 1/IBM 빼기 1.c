#include <stdio.h>
int main()
{
	char arr[60];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",arr);
		j=0;
		while(arr[j]!=NULL)
		{
			if(arr[j]=='Z')
				arr[j]='A';
			else
				arr[j]+=1;
			j++;
		}
		printf("String #%d\n",i+1);
		printf("%s\n\n",arr);
	}

}