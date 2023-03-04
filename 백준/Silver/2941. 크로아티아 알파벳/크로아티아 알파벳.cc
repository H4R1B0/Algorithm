#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char* C[]={"c=","c-","dz=","d-","lj","nj","s=","z="};
	char arr[101];
	cin>>arr;
	int sum=0;
	int i=0;
	int len=strlen(arr);
	while(arr[i]!=NULL)
	{
		for(int j=0;j<8;j++)
		{
			if(j==2)
			{
				if(!strncmp(arr+i,C[j],3))
				{
					sum++;
					i+=2;
					len-=3;
				}
			}
			else
				if(!strncmp(arr+i,C[j],2))
				{
					sum++;
					i+=1;
					len-=2;
				}
		}
		i++;
	}
	cout<<sum+len;
}