/*
	* Input graph and source.
	* Add source in visited list 'sptSet' and update all adjacent vertex with total weight from source.
	* Find minimum distance vertex and countinue till all vertex is getting travelled.
*/

#include<bits/stdc++.h>
using namespace std;
const int m=20;
const int n=20;


int minDist(int dist[],bool sptSet[],int v)
{
	int min=INT_MAX,min_index;
	for(int i=0;i<v;i++)
	{
		if(sptSet[i]==false && min>dist[i])
		{
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}



void dijkstra(int graph[m][n],int v,int src)
{
	int dist[v];
	bool sptSet[v];

	for(int i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
		sptSet[i]=false;
	}

	dist[src]=0;

	for(int i=0;i<v-1;i++)
	{
		int u=minDist(dist,sptSet,v);
		sptSet[u]=true;
		for(int j=0;j<v;j++)
		{
			if(graph[u][j]!=0 && sptSet[j]==false && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j])
			{
				dist[j]=dist[u]+graph[u][j];
			}
		}

	}

	//...............function to print shortest path...................

	
	cout<<"Vertex                Distence from source\n";
	for(int i=0;i<v;i++)
	{
		cout<<"  "<<i<<"..........................."<<dist[i]<<endl;
	}


}



int main()
{
	int v;
	cout<<"Enter the no of vertices of graph:\n";
	cin>>v;
	cout<<"Enter the adjacency matrix of graph:\n";
	int graph[m][n];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cin>>graph[i][j];
		}
	}
	int src;
	cout<<"Enter the source point:\n";
	cin>>src;

	dijkstra(graph,v,src);
}
