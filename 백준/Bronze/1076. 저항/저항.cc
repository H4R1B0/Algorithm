#include <iostream>
//#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    string a[]={"black", "brown" ,"red"	,"orange"	,"yellow",	"green",	"blue",	"violet",	"grey",	"white"};
    string b[]={"0","1","2","3","4","5","6","7","8","9"};    
    string c[]={"1","10","100","1000","10000","100000","1000000","10000000","100000000","1000000000"};
    string a1,a2,a3,n;
    int i;
	long long int k;
    cin>>a1>>a2>>a3;
    for(i=0;i<10;i++)
    {
        if(a1==a[i])  
            n=b[i];      
    }
    for(i=0;i<10;i++)
    {
        if(a2==a[i])  
            n+=b[i];      
    }
	k=atoi(n.c_str());
    for(i=0;i<10;i++)
    {
        if(a3==a[i])  
			k*=atoi(c[i].c_str());      
    }
    cout<<k;
}
