#include <iostream>
#include <algorithm>
using namespace std;
int n,M;
int arr[101];
int fo(int pos,int sum, int x)
{
	if(sum>M || x>3)
		return -987654321;
	if(pos==n)
		if(x==3)
			return sum;
		else
			return -987654321;
	return max(fo(pos+1,sum,x),fo(pos+1,sum+arr[pos],x+1));
}
int main()
{
	int i;
	cin>>n>>M;
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<fo(0,0,0);
}
