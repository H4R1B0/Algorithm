#include <stdio.h>
int gan[]={1,2,3,3,4,10};
int sa[]={1,2,2,2,3,5,10};
int main()
{
	int N;
	scanf("%d",&N);
	int get;
	for(int i=0;i<N;i++)
	{
		int sumg=0,sums=0;
		for(int j=0;j<6;j++)
		{
			scanf("%d",&get);
			sumg+=get*gan[j];
		}
		for(int j=0;j<7;j++)
		{
			scanf("%d",&get);
			sums+=get*sa[j];
		}
		if(sumg==sums)
			printf("Battle %d: No victor on this battle field\n",i+1);
		else if(sumg>sums)
			printf("Battle %d: Good triumphs over Evil\n",i+1);
		else
			printf("Battle %d: Evil eradicates all trace of Good\n",i+1);
	}
}