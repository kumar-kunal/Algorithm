#include<bits/stdc++.h>
using namespace std;

const int r=100;
const int c=100;

int n,m;


bool check(int a,int b,int maze[r][c])
{
	if(a>=0 && a<n && b>=0 && b<m && maze[a][b] == 1)
	{
		//cout<<"i am ok\n";
		return true;
	}
	else
		return false;
}


bool ratPathFinder(int xPresent,int yPresent,int sol[r][c],int maze[r][c])
{
		if(xPresent==n-1 && yPresent==m-1)
		{
			sol[xPresent][yPresent]=1;
			return true;
		}
		if(check(xPresent,yPresent,maze)==true)
		{
			sol[xPresent][yPresent]=1;
			if(ratPathFinder(xPresent+1,yPresent,sol,maze)==true)
			{
				return true;
			}
			if(ratPathFinder(xPresent,yPresent+1,sol,maze)==true)
			{
				return true;
			}
			else
			{
				sol[xPresent][yPresent]=0;
				return false;
			}
		}
		return false;
	
}



int main()
{
	cout<<"Enter size of maze as n as row and m as column:\n";
	cout<<"Enter n  as row first:\n";
	cin>>n;
	cout<<"Enter m as column:\n";
	cin>>m;
	int maze[r][c];
	cout<<"Now Enter the maze:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>maze[i][j];
		}
	}

	int sol[r][c];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sol[i][j]=0;
		}
	}
	//int xPresent=0,yPresent=0;
	if(ratPathFinder(0,0,sol,maze)==false)
	{
		cout<<"No Solution\n";
	}
	else
	{
		cout<<"The path for rat is :\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
			{
				//cout<<"yes"<<endl;
				cout<<sol[i][j]<<"  ";
			}
			cout<<"\n";
		}
	}

}