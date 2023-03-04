#include <stdio.h>
int main()
{
    int n,m;
    int i;
    int sum=0,max;
    int arr[100000];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<m;i++)
        sum+=arr[i];
    max=sum;
    for(i=1;i<=n-m;i++)
    {
        sum+=-arr[i-1]+arr[i+m-1];
        if(max<sum)
            max=sum;
    }
    printf("%d",max);
}