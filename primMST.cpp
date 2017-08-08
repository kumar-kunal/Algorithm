/*
	* First we take adjacency matrix as input.
	* we make a set called mstSet which store vertices of ST.
		* Initially there is no any element in mstSet.
		* At same time we give keyvalue to all vertices via. making array called 'key'
		  and initialise all vertices with INT_MAX except the starting vertices ,that's with zero.
		* At same time we store edges end and starting point in array parent ,with index of array as end and element as starting point.
	* Choose smallest amoung rest using key array,and add them in mstSet.
	* After choosing smallest, update key value of adjacent vertex with respective edge weight.
	* Do above operation for V-1 times,i.e. min edge for spanning tree.

*/


#include<bits/stdc++.h>
using namespace std;
const int m=20;
const int n=20;


int minKey(int key[],bool mstSet[],int v)
{
	int min=INT_MAX,min_index;
	for(int i=0;i<v;i++)
	{
		if(mstSet[i]==false && key[i]<min)
		{
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}


void primMST(int graph[m][n],int v)
{
	int parent[v];	        //To store (start and end of)  edge of ST.
	int key[v];             //To store key value of vertex.
	bool mstSet[v];			// To check whether vertex are in ST or outside.


	for(int i=0;i<v;i++)
	{
		key[i]=INT_MAX;     //Initialise with infinity.
		mstSet[i]=false;	// Initially all vertex are outside so it's false.
	}


	key[0]=0;               // Except first or starting vertex.
	parent[0]=-1;			// Ofcourse first vertex will not have any parent vertex.


	for(int i=0;i<v-1;i++)	// Loop run for v-1 (min edge) times.
	{
		int u=minKey(key,mstSet,v);	//Minimum value vertex from outside of ST.

		mstSet[u]=true;		//After adding make it true, so that it doest not come again as outsider.

		// Now we update adjacent of vertex u with it's edge with u weight.

		for(int j=0;j<v;j++)	//here we run loop in column , so that all edges strted from uth vertex can come under operation.
		{
			if(graph[u][j] !=0 && mstSet[j]==false && graph[u][j]<key[j])	// Edge end point can not be zero, must have edge weight.
			{																// End point must not be already in ST set.
																			// Edge weight must be less than key value.

				parent[j]=u;												
				key[j]=graph[u][j];
			}
		}


	}
	
	//........ Function to print MST........

	for(int i=1;i<v;i++)
	{
		cout<<"( Vertex = "<<parent[i]<<") -------------------- ( Weight= "<<graph[i][parent[i]]<<" ) -------------------- ( Vertex= "<<i<<")"<<endl;
	}

}	




int main()
{
	int graph[m][n];
	int v;
	cout<<"Enter the no. of vertices:\n";
	cin>>v;
	cout<<"Enter adjacency matrix of graph:\n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cin>>graph[i][j];
		}
	}
	primMST(graph,v);


	return 0;
}
