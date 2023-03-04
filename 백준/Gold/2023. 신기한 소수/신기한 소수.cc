#include<iostream>
#include <cmath>
using namespace std;
int maxlen;
bool isPrime(int n)
{
	if(n<=1)
		return false;
	if(n==2)
		return true;
	if(n%2==0)
		return false;

	int sqrtn =(int)sqrt((double)n);
	for(int div=3;div<=sqrtn;div+=2)
		if(n%div==0)
			return false;
	return true;
}
void find(int num,int len)
{
	if(!isPrime(num))
		return ;
	if(len==maxlen)
	{
		cout<<num<<endl;
		return;
	}
	find(num*10+1,len+1);
	find(num*10+3,len+1);
	find(num*10+7,len+1);
	find(num*10+9,len+1);
}
int main()
{
	int i;
	cin>>maxlen;
	for(i=1;i<10;i++)
		find(i,1);
}