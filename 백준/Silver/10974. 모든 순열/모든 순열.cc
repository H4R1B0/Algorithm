#include<iostream>
using namespace std;
int n;
bool s[10]={};
int pick[10];
void solve(int pos)
{
	int i;
	if(pos==n)
	{
		for(i=0;i<n;i++)
			cout<<pick[i]<<' ';
		cout<<endl;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(s[i]==false)
		{
			s[i]=true;
			pick[pos]=i;
			solve(pos+1);
			s[i]=false;
		}
	}

}
int main()
{
	cin>>n;
	solve(0);
}