/*
 * sort all edges in increasing order of weight
 * pick smallest edge and check whether it form cycle with 
   spanning tree so far,if not then include otherwise
   discard;
 * Repeat untill spanning tree has v-1 edges
 */

#include<bits/stdc++.h>
using namespace std;

const int m=20;
const int n=20;

struct subset
{
	int parent,rank;
};

int find(struct subset subsets[],int i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent=find(subsets,subsets[i].parent);
	return subsets[i].parent;
}

void Union(struct subset subsets[],int x,int y)
{
	int xroot=find(subsets,x);
	int yroot=find(subsets,y);
	if(subsets[xroot].rank<subsets[yroot].rank)
	{
		subsets[yroot].parent=xroot;
	}
	else if(subsets[xroot].rank>subsets[yroot].rank)
	{
		subsets[xroot].parent=yroot;
	}
	else
		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
}

//main program

void kruskalmst(int adjacencyMatrix[m][n],int v)
{
	int result[m][n];
	for(int k=0;k<m;k++)
	{
		for(int j=0;j<n;j++)
		{
			result[k][j]=0;
		}
	}
	int e=0,i=0;
	//sort according to weight
	struct subset *subsets=(struct subset*)malloc(v * sizeof(struct subset));

	for(int j=0;j<v;j++)
	{
		subsets[j].parent=j;
		subsets[j].rank=0;
	}

	while(e<v-1)
	{   
		int temp=1000;
		int rtemp,ctemp;
		//cout<<"temp"<<endl;
		for(int j=0;j<v;j++)
		{
			for(int k=0;k<j;k++)
			{
				if(temp>=adjacencyMatrix[j][k] && adjacencyMatrix[j][k]!=0)
				{
					temp=adjacencyMatrix[j][k];
					rtemp=j;
					ctemp=k;
				}
			}
		}

		int x = find(subsets,rtemp);
		int y = find(subsets,ctemp);
		if(x!=y)
		{

			result[rtemp][ctemp]=temp;
			e++;
			Union(subsets,x,y);
		}
		adjacencyMatrix[rtemp][ctemp]=0;

	}
	cout<<"\n\nMatrix representation of mst is:\n";
	for(int k=0;k<v;k++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<result[k][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\n";
	cout<<"\n";
	for(int k=0;k<v;k++)
	{
		for(int j=0;j<v;j++)
		{
			if(result[k][j]!=0)
			{
				cout<<"Edge with weight " <<result[k][j]<<" lies between vertex index "<< k <<" and vertex index "<< j<<endl;
			}
		}
	}

}



int main()
{
	int v;
	cout<<"Enter no of vertex in graph:\n";
	cin>>v;

	cout<<"Enter the adjacency matrix of graph:\n";
	int adjacencyMatrix[m][n];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cin>>adjacencyMatrix[i][j];
		}
	}
	kruskalmst(adjacencyMatrix,v);
}
