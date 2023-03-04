#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(char arr[])
{
    int j=0;
    while(arr[j]!=NULL)
    {
        if(arr[j]=='+')
            return j;
        j++;
    }
}
int main()
{
    char arr[1000];
    int n,i,j,k;
    int ap;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	char arr2[1000]={0},arr3[1000]={0};
        j=0;
        k=0;
        scanf("%s",arr);
        if(!strcmp(arr,"P=NP"))
            printf("skipped\n");
        else
        {
            while(arr[j]!=NULL)
            {
                if(j<f(arr))
                    arr2[j]=arr[j];
                else if(j>f(arr))
                {
                    arr3[k]=arr[j];
                    k++;
                }
                j++;
            }
            ap=atoi(arr2)+atoi(arr3);
            printf("%d\n",ap);
        }
             
    }
 
}