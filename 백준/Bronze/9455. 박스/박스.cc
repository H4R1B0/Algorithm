#include <iostream>
using namespace std;
int main()
{
	int arr[100][100];
	int a,b;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		cin>>a>>b;
		for(int j=0;j<a;j++)
			for(int k=0;k<b;k++)
				cin>>arr[j][k];
		int m=a;
		while(m)
		{
			for(int j=a-2;j>=0;j--)
			{
				for(int k=0;k<b;k++)
				{
					if(arr[j][k]==1 && arr[j+1][k]==0)
					{
						arr[j][k]=0;
						arr[j+1][k]=1;
						cnt++;
					}
				}
			}
			m--;
		}
		cout<<cnt<<endl;
	}
}

