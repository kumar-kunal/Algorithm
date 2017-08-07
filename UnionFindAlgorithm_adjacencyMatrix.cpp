#include<bits/stdc++.h>
using namespace std;
const int m=20;
const int n=20;


int find(int parent[],int i)
{
	if(parent[i]==-1)
		return i;
	return find(parent,parent[i]);
}
void Union(int parent[],int x,int y)
{
	int xset=find(parent,x);
	int yset=find(parent,y);
	parent[xset]=yset;
}


//main function to check cycle

int isCycle(int adjacencyMatrix[m][n],int k)
{
	int *parent=(int*) malloc(k * sizeof(int));
	memset(parent,-1,sizeof(int)*k);
	for(int i=0;i<k;++i)
	{
		for(int j=0;j<i;j++)
		{
			if(adjacencyMatrix3[i][j]==1)
			{
				int x=find(parent,i);
				int y=find(parent,j);
				if(x==y)
				{
					return 1;
				}
				Union(parent,x,y);
			}
		}
	}
	
	return 0;
}

int main()
{
	int k;
	cout<<"Enter no of vertices in graph\n";
	cin>>k;

	int adjacencyMatrix[m][n];
	cout<<"Enter adjacency Matrix\n";
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			cin>>adjacencyMatrix[i][j];
		}
	}

	if(isCycle(adjacencyMatrix,k))
		printf("graph contains cycle\n");
	else
		printf("graph doesn't contain cycle\n");

	return 0;

}