#include<bits/stdc++.h>
using namespace std;

void swap(char *str1,char *str2)
{
	char temp;
	temp=*str1;
	*str1=*str2;
	*str2=temp;
	//cout<<str1<<str2<<endl;

}

void permute(char *str,int s,int e)
{
	if(s==e)
	{
		cout<<str<<endl;
	}
	
	else
	{
		for(int i=s;i<=e;i++)
		{

			swap(str+s,str+i);
			permute(str,s+1,e);
			swap(str+s,str+i);
		}
	}
}

int main()
{
	char str[100];
	cin>>str;
	int n=strlen(str);
	permute(str,0,n-1);
}