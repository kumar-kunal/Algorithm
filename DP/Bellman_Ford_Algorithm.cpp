#include<bits/stdc++.h>
using namespace std;

const int m=100;

struct edges
{
	int s,d,w;
};

struct edges edge[m];
int e=0;

//Make edge list so that we can travel ....


void collect_edge(int graph[m][m],int v)
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(graph[i][j]!=0)
			{
				edge[e].s=i;
				edge[e].d=j;
				edge[e].w=graph[i][j];
				e++;
			}
		}
	}
}



void BellmanFord(int graph[m][m],int v,int src)
{
	int distance[v];
	int parent[v];
	for(int i=0;i<v;i++)
	{
		distance[i]=INT_MAX;
		parent[i]=-1;
	}
	distance[src]=0;

	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int a=edge[j].s;
			int b=edge[j].d;
			int weight=edge[j].w;
			if(distance[a]!=INT_MAX && distance[a]+weight<distance[b])
			{
				distance[b]=distance[a]+weight;
				//parent[b]=a;
			}
		}
	}

	//check for -ve cycle
	//run algo one more time.. if there is relaxation with any edge ,that means cycle.

	for(int j=0;j<e;j++)
	{
		int a=edge[j].s;
		int b=edge[j].d;
		int weight=edge[j].w;
		if(distance[a]!=INT_MAX && distance[a]+weight<distance[b])
		{
			printf("O hello... your graph has negative weight cycle!!!");
		}
	}

	printf("Vertex        Distance from source\n");

	for(int i=0;i<v;i++)
	{
		if(distance[i]==INT_MAX)
		{
			printf("%d\t\tThere is no way from source\n",i);
		}
		else
			printf("%d\t\t%d\n",i,distance[i]);
	}


}


int main()
{
	int v;
	printf("Enter the no of vertices in the graph:\n");
	scanf("%d",&v);
	int graph[m][m];
	printf("Enter the adjacency matrix of the graph:\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	int src;
	printf("Enetr source\n");
	scanf("%d",&src);
	collect_edge(graph,v);

	BellmanFord(graph,v,src);

}