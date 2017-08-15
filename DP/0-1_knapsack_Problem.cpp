#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}

/*

//Recursive approach

int solution(int value[],int weight[],int w,int n)
{
	if(w==0 || n==0)
	{
		return 0;
	}
	if(weight[n-1]>w)
	{
		return solution(value,weight,w,n-1);
	}
	else
	{
		return max(value[n-1]+solution(value,weight,w-weight[n-1],n-1),solution(value,weight,w,n-1));
	}
}
*/

//DP approach

int solution(int value[],int weight[],int w,int n)
{
	int result[n+1][w+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0 || j==0)
			{
				result[i][j]=0;
			}
			
			else if(weight[i-1]>w)
			{
				result[i][j]=result[i-1][j];
			}
			else
			{
				result[i][j]=max( value[i-1]+result[i-1][j-weight[i-1]] , result[i-1][j]);
			}
		}
	}
	return result[n][w];
}

int main()
{
	int value[100],weight[100],w;
	printf("Enter the no of item:\n");
	int n;
	scanf("%d",&n);
	printf("Enter the value of items:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&value[i]);
	}
	printf("Enter the weight of items:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	printf("Enter the capacity of knapsack:\n");
	scanf("%d",&w);

	printf("Here is your result: ");
	printf("%d\n",solution(value,weight,w,n));
}