#include<bits/stdc++.h>
using namespace std;
const int v=100;




bool check(int x,int y,int sol[v][v],int n)
{
	return (x>=0 && x<n && y>=0 && y<n && sol[x][y]==-1);
}



bool solveKT(int x,int y,int movei,int sol[v][v],int xmove[],int ymove[],int n)
{
	int next_x,next_y;
	if(movei==n*n)
	{
		return true;
	}
	else
	{
		for(int k=0;k<8;k++)
		{
			next_x=x+xmove[k];
			next_y=y+ymove[k];

			if(check(next_x,next_y,sol,n))
			{
				sol[next_x][next_y]=movei;
				if(solveKT(next_x,next_y,movei+1,sol,xmove,ymove,n)==true)
				{
					return true;
				}
				else
				{
					sol[next_x][next_y]=-1;
				}
			}
		}
	}
	return false;
}


int main()
{
	int n;
	cout<<"Enter the size of chess board:\n";
	cin>>n;
	int sol[v][v];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sol[i][j]=-1;
		}
	}

	int xmove[]={2,1,-1,-2,-2,-1,1,2};
	int ymove[]={1,2,2,1,-1,-2,-2,-1};

	sol[0][0]=0;
	if(solveKT(0,0,1,sol,xmove,ymove,n)==false)
	{
		cout<<"NO Solution\n";
		return 0;
	}
	else
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<"\n";
		}

}