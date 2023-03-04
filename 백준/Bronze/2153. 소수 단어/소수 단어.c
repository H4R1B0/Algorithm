#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,m=0,sum=0;
    char arr[20];
    scanf("%s",arr);
    for(i=0;i<strlen(arr);i++)
    {
        if(arr[i]>='a' && arr[i]<='z')
        {
            for(j='a';j<='z';j++)
            {
                if(arr[i]==j)
                    sum+=j-96;
            }
        }
        else
        {
            for(j='A';j<='Z';j++)
            {
                if(arr[i]==j)
                    sum+=j-38;
            }
        }
    }
    for(i=1;i<=sum;i++)
    {
        if(sum%i==0)
        {
            m++;
        }
    }
    if(m==2 || sum==1)
        printf("It is a prime word.");
    else
        printf("It is not a prime word.");
    return 0;
}