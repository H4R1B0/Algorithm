#include <stdio.h>
int main()
{
    int a,i,b,j;
    char c[100];
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d %s",&b,c);
        for(j=0;c[j]!=0;j++)
        {
            if(j!=b-1)
             printf("%c",c[j]);       
        }
        printf("\n");
    }
	return 0;
}
