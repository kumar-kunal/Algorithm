#include<iostream>
using namespace std;
int main()
{
	int checkElement,n;
	cin>>n;
	cin>>checkElement;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==checkElement)
		{
			cout<<i<<endl;
			break;
		}
	}
}
