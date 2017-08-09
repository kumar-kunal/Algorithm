#include<bits/stdc++.h>

using namespace std;
const int u=100;
const int v=100;


bool check(int row,int col,int sol[u][v],int n)
{
	int i,j;
	//row check

	for(i=0;i<col;i++)
	{
		if(sol[row][i]==1)
		{
			return false;
		}
	}

	//upper diagonal

	for(i=row ,j=col; i>=0 && j>=0; i--,j--)
	{
		if(sol[i][j]==1)
		{
			return false;
		}
	}

	//lower diagonal

	for(i=row,j=col; i<n && j>=0; i++,j-- )
	{
		if(sol[i][j]==1)
		{
			return false;
		}
	}
	return true;
}


bool queenCastle(int sol[u][v],int n,int col)
{
	if(col==n)
	{
		return true;
	}
	for(int i=0;i<n;i++)
	{
		if(check(i,col,sol,n)==true)
		{
			sol[i][col]=1;

			if(queenCastle(sol,n,col+1)==true)
			{
				return true;
			}
		}
		sol[i][col]=0;
		
	}
	return false;
}



int main()
{
	int n;
	cout<<"Enter size of the chess board:\n";
	cin>>n;
	int sol[u][v];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sol[i][j]=0;
		}
	}

	int col=0;

	if(queenCastle(sol,n,col)==false)
	{
		cout<<"No Solution!!!\n";
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<sol[i][j]<<"  ";
			}
			cout<<"\n";
		}
	}


}