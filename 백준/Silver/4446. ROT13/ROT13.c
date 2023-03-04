#include <stdio.h>
char mo[]="aiyeou";
char ja[]="bkxznhdcwgpvjqtsrlmf";
int main()
{
	int cha='a'-'A';
	char a[101];
	while(gets(a))
	{
		
		for(int i=0;a[i]!=NULL;i++)
		{
			if(a[i]>='A' && a[i]<='Z')
			{
				a[i]|=cha;
				if(a[i]=='a'||a[i]=='i'||a[i]=='y'||a[i]=='e'||a[i]=='o'||a[i]=='u')
				{
					for(int j=0;mo[j]!=NULL;j++)
					{
						if(a[i]==mo[j])
						{
							a[i]=mo[(j+3)%6]-cha;
							break;
						}
					}
				}
				else
				{
					for(int j=0;ja[j]!=NULL;j++)
					{
						if(a[i]==ja[j])
						{
							a[i]=ja[(j+10)%20]-cha;
							break;
						}
					}
				}
			}
			else if(a[i]>='a'&&a[i]<='z')
			{
				if(a[i]=='a'||a[i]=='i'||a[i]=='y'||a[i]=='e'||a[i]=='o'||a[i]=='u')
				{
					for(int j=0;mo[j]!=NULL;j++)
					{
						if(a[i]==mo[j])
						{
							a[i]=mo[(j+3)%6];
							break;
						}
					}
				}
				else
				{
					for(int j=0;ja[j]!=NULL;j++)
					{
						if(a[i]==ja[j])
						{
							a[i]=ja[(j+10)%20];
							break;
						}
					}
				}
			}
		}
		printf("%s\n",a);
	}
	
}