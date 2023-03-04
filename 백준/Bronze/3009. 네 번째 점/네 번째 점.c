#include <stdio.h>
int main()
{
    int arr[3][2],i,j;
    for(i=0;i<3;i++)
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    if(arr[0][0]==arr[1][0])
    {
        if(arr[0][1]==arr[2][1])
            printf("%d %d",arr[2][0],arr[1][1]);
        else if(arr[1][1]==arr[2][1])
            printf("%d %d",arr[2][0],arr[0][1]);
    }
    if(arr[0][0]==arr[2][0])
    {
        if(arr[0][1]==arr[1][1])
            printf("%d %d",arr[1][0],arr[2][1]);
        else if(arr[1][1]==arr[2][1])
            printf("%d %d",arr[1][0],arr[0][1]);
    }
    if(arr[1][0]==arr[2][0])
    {
        if(arr[0][1]==arr[1][1])
            printf("%d %d",arr[0][0],arr[2][1]);
        else if(arr[0][1]==arr[2][1])
            printf("%d %d",arr[0][0],arr[1][1]);
    }
}
