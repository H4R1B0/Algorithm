#include <iostream>
#include<cstring>
using namespace std;
int abc;
void f(int a[])
{
    int i,max,k=0;
    max=a[0];
    for(i=1;i<26;i++)
        if(a[i]>max)
        {
            max=a[i];
            abc=i;
        }
    for(i=0;i<26;i++)
        if(max==a[i])
            k++;
    if(k==1)
        cout<<(char)('A'+abc);
    else
        cout<<'?';
}
int main()
{
    int i,arr[26]={0},len;
	int j;
    char s[1000000];
    cin>>s;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
		for(j=0;j<26;j++)
		{
			if(s[i]==(char)('a'+j) || s[i]==(char)('A'+j))
				arr[j]++;
		}
		
    }
    f(arr);
}
