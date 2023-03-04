#include <iostream>
using namespace std; 
int MAX(int a,int b,int c)
{
	int max=a;
	if(a<b)
		max=b;
	if(max<c)
		max=c;
	return max;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b && b==c && a==c)
		cout<<10000+a*1000;
	else if(a==b && a!=c)
		cout<<1000+a*100;
	else if(a==c && a!=b)
		cout<<1000+a*100;
	else if(c==b && c!=a)
		cout<<1000+b*100;
	else 
		cout<<100*MAX(a,b,c);
}
