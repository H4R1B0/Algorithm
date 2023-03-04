#include <stdio.h>
int year1[]={31,28,31,30,31,30,31,31,30,31,30,31};
int year2[]={31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int year=2014,month=4,day=2;
    int n;
    scanf("%d",&n);
	int k=day+n-1;
    while(1)
    {
 
        if(year%4==0 && year%100!=0 || year%400==0)
        {
            if(k<=year2[month-1])
                break;
            else{
                     
                k-=year2[month-1];
                if(day==0)
                    day++;
            }
             
            month+=1;
            if(month>12)
            {
                month%=12;
                year++;
            }
 
        }
 
        else
        {
            if(k<=year1[month-1])
                break;
            else{
 
                k-=year1[month-1];
                if(day==0)
                    day++;
            }
 
            month+=1;
            if(month>12)
            {
                month%=12;
                year++;
            }
        }
         
    }
    day=k; 
    if(month>0&&month<10)
    {
        if(day>0 && day<10)
            printf("%d-0%d-0%d",year,month,day);
        else
            printf("%d-0%d-%d",year,month,day);
    }
    else
    {
        if(day>0 && day<10)
            printf("%d-%d-0%d",year,month,day);
        else
            printf("%d-%d-%d",year,month,day);
    }
 
}