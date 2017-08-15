#include<bits/stdc++.h>

using namespace std;

const int m=100;

int min(int a,int b,int c)
{
	return (a>b?(b<c?b:c):(a<c?a:c));
}



int minCost(int matrix[m][m],int x,int y )
{
	int cost[x+1][y+1];
	for(int i=0;i<x+1;i++)
	{
		for(int j=0;j<y+1;j++)
		{
			if(i==0 && j==0)
			{
				cost[i][j]=matrix[i][j];
			}
			else if(i==0 && j!=0)
			{
				//First row
				cost[i][j]=cost[i][j-1]+matrix[i][j];
			}
			else if(j==0 && i!=0)
			{
				//First column
				cost[i][j]=cost[i-1][j]+matrix[i][j];
			}
			else
			{
				cost[i][j]=matrix[i][j]+min(cost[i-1][j],cost[i][j-1],cost[i-1][j-1]);
			}
		}
	}
	return cost[x][y];
}


int main()
{
	int matrix[m][m];
	printf("Enter the size of the matrix:\n");
	int n;
	scanf("%d",&n);
	printf("Enter cost in matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	int x,y;
	printf("Enter final index as x and y:\n");
	scanf("%d %d",&x,&y);

	printf("So here is our result: ");
	printf("%d\n",minCost(matrix,x,y));
}