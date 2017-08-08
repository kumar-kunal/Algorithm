#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


struct indexCal{     
    int flag;
	float value;
};


bool comparison(indexCal index1,indexCal index2)
{
	return (index1.value>index2.value);
}

int main()
{
	int n;
	cout<<"Enter the no of job ,shoemaker have:\n";
	cin>>n;
	float t[n],s[n];
	cout<<"Enter time taken T and fine S for each job respectively:\n";
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
		cin>>s[i];
	}
	struct indexCal index[n];
	for(int i=0;i<n;i++)
	{
		index[i].value=s[i]/t[i];
		index[i].flag=i;
		
	}
	
	sort(index,index+n,comparison); //sort algorithm from STL.

	cout<<"Shoemaker should work in following order of index:\n ";
	for(int i=0;i<n;i++)
	{
		cout<<index[i].flag+1<<endl;
	}


}