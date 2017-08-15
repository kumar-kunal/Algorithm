/*
	* You have given different type of coin.
	* and total amount , which you have to change
	* You have to output the no of way in which 
	* you can change.(So output is no of ways to change ta)
*/



#include<bits/stdc++.h>
using namespace std;


int coinCount(int coin[],int n,int ta)
{
	int count[ta+1][n];

	for(int i=0;i<ta+1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0)
			{
				count[i][j]=1;
			}
			else
			{
				count[i][j]=((j>=1)?count[i][j-1]:0)+((i>=coin[j-1])?count[i-coin[j-1]][j]:0);
			}
		}
	}
	return count[ta][n-1];
}


int main()
{
	int ta;  //total amount
	int coin[100];  //type of coin
	printf("Enter the no of type of coin:\n");
	int n;
	scanf("%d",&n);
	printf("Enter the list of coin type:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&coin[i]);
	}
	printf("Enter the total amount of money:\n");
	scanf("%d",&ta);

	printf("So here is your total no of way to change: ");
	printf("%d\n",coinCount(coin,n,ta));

}