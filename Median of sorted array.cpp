#include<bits/stdc++.h>
using namespace std;

const int v=100005;

int median(int list[],int n)
{
	if(n%2==1)
	{
		return list[n/2];
	}
	if(n%2==0)
	{
		return (list[n/2]+list[n/2-1])/2;
	}
}

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
		return b;
}

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int median_finder(int list1[],int list2[],int n)
{
	if(n<=0)
	{
		return -1;
	}
	if(n==1)
	{
		return (list1[0]+list2[0])/2;
	}
	if(n==2)
	{
		return ((max(list1[0],list2[0])+min(list1[1],list2[1]))/2);
	}

	int median1=median(list1,n);
	int median2=median(list2,n);

	if(median1==median2)
	{
		return median1;
	}

	if(median1>median2)
	{
		if(n%2==0)
		{
			return median_finder(list2+n/2-1,list1,n-n/2+1);
		}
		return median_finder(list2+n/2,list1,n-n/2);
	}
	if(median1<median2)
	{
		if(n%2==0)
		{
			return median_finder(list1+n/2-1,list2,n-n/2+1);
		}
		return median_finder(list1+n/2,list2,n-n/2);
	}

	return -1;


}

int main()
{
	int list1[v],list2[v];
	int n;
	cout<<"Enter the same size of list-1 and lis-2:\n";
	cin>>n;
	cout<<"Enter elements of list-1:\n";
	for(int i=0;i<n;i++)
	{
		cin>>list1[i];
	}
	cout<<"Enter elements of list-2:\n";
	for(int i=0;i<n;i++)
	{
		cin>>list2[i];
	}

	if(median_finder(list1,list2,n)==-1)
	{
		cout<<"NO SOLUTION!!!\n";
	}
	else
	{
		cout<<median_finder(list1,list2,n)<<endl;
	}



}