#include <stdio.h>
int k=0;
int a,b,arr[20];
int f(int pos,int sum)
{
	if(pos==a)
	{
		if(sum==b)
			return 1;
		return 0;
	}
	return f(pos+1,sum)+f(pos+1,sum+arr[pos]);
}
int main()
{

	int i;
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++)
		scanf("%d",&arr[i]);
	printf("%d",f(0,0)-(b==0));

}