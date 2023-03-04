#include <stdio.h>
int sib(int n)
{
	int i=0,num=1;
	for(i=0;i<n;i++)
		num*=10;
	return num;
}
int main()
{
    int a,b,k,arr[10],i;
    while(1)
    {
        k=0;
        scanf("%d %d",&a,&b);
		if(a==0 &&b==0)
			return 0;
        for(i=0;i<10;i++)
		{
			if(i==0)
				arr[i]=(a%sib(i))/sib(i-1)+(b%sib(i))/sib(i-1);
			else
				arr[i]=(a%sib(i))/sib(i-1)+(b%sib(i))/sib(i-1)+arr[i-1]/10;
			if(arr[i]>=10)
				k++;
		}
        printf("%d\n",k);
    }
}
