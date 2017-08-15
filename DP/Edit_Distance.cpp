#include<bits/stdc++.h>

using namespace std;

int min(int a,int b,int c)
{
	return ((a>b)?(b<c?b:c):(c>a?a:c));
}

int minED(char str1[],char str2[],int l1,int l2)
{
	int ed[l1+1][l2+1];
	for(int i=0;i<l1+1;i++)
	{
		for(int j=0;j<l2+1;j++)
		{
			if(i==0)
			{
				ed[i][j]=j;
			}
			else if(j==0)
			{
				ed[i][j]=i;
			}
			else if(str1[i-1]==str2[j-1])
			{
				ed[i][j]=ed[i-1][j-1];
			}
			else
			{
				ed[i][j]=1+min(ed[i][j-1],ed[i-1][j],ed[i-1][j-1]);
			}

		}
	}
	return ed[l1][l2];
}


int main()
{
	int tt;
	printf("Enter the two string\n");

	char str1[100];
	char str2[100];
	scanf("%s",str1);
	scanf("%s",str2);
	int l1,l2;
	for(l1=0;str1[l1];l1++){}
	for(l2=0;str2[l2];l2++){}

	printf("Edit cost is:\n");

	printf("%d\n",minED(str1,str2,l1,l2));

}