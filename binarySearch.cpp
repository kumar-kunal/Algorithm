#include<bits/stdc++.h>
using namespace std;


//!!!................Recursive algorithm......................!!!


int rbinSearch(int arr[],int s,int e,int temp) // s= start index of array  e= end index of array
{
	int mid;
	
	if(e>s)
	{
		mid=s+(e-s)/2;
		if(arr[mid]==temp)
		{
			return mid;
		}
		else if(arr[mid]>temp)
		{
			return rbinSearch(arr,s,mid-1,temp);
		}
		else
		{
			return rbinSearch(arr,mid+1,e,temp);
		}	
	}
	else
	return -1;
}


//!!!......................Iterartive algorithm.................!!!


int ibinSearch(int arr[],int s,int e,int temp)
{
	int mid;
	while(e>s)
	{
		mid= s+(e-s)/2;
		if(arr[mid]==temp)
		{
			return mid;
		}
		else if(arr[mid]>temp)
		{
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return -1;
}


int main()
{
	int checkElement,n;
	cout<<"Enter the no element in array"<<endl;
	cin>>n;
	int list[n];
	cout<<"Enter the elements of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>list[i];
	}
	cout<<"Enter the element for index..."<<endl;
	cin>>checkElement;
	int rindex,iindex;
	rindex=rbinSearch(list,0,n-1,checkElement);
	iindex=ibinSearch(list,0,n-1,checkElement);
	cout<<"Element " << checkElement<< " is at "<<rindex << " index."<<endl;
	cout<<"Element "<<checkElement<<" is at "<<iindex << " index."<<endl;
	
}
