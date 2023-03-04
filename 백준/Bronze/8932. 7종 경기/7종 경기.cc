#include <iostream>
#include <cmath>
using namespace std;
double A[]={9.23076,1.84523,56.0211,4.99087,0.188807,15.9803,0.11193};
double B[]={26.7,75,1.5,42.5,210,3.8,254};
double C[]={1.835,1.348,1.05,1.81,1.41,1.04,1.88};

int main()
{
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=0;j<7;j++)
		{
			cin>>a;
			if(j==0||j==3||j==6)
				sum+=A[j]*pow(fabs(B[j]-a),C[j]);
			
			else
				sum+=A[j]*pow(fabs(a-B[j]),C[j]);
		}
		cout<<sum<<endl;
	}
}