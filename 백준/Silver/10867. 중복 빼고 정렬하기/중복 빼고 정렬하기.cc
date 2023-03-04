#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int arr[100000];
	int n,i,num;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	num=arr[0];
	cout<<arr[0];
	for(i=0;i<n;i++)
	{
		if(num!=arr[i])
		{
			num=arr[i];
			cout<<' '<<arr[i];
		}
	}
}