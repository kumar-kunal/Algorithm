#include<bits/stdc++.h>
using namespace std;

int checkIndex(int max,std::vector<int>track,int n;)
{
	for(int i=0;i<n;i++)
	{
		if(track[i]==max)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	std::vector<int> v;
	std::vector<int> :: iterator i;
	std::vector<int> :: reverse_iterator ir;
	int n;
	cout<<"Enter size of the array\n";
	cin>>n;
	cout<<"Enter the elements of the array:\n";
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	std::vector<int> track;
	for(int j=0;j<n;j++)
	{
		track.push_back(1);
	}
	
	int k=1;
	while(k!=9) {
	    
	    int j=0;
	    while(j!=k) {
	    
		    if(v[j]<v[k] && track[k]<track[j]+1)
		    {
		    	track[k]=track[j]+1;
		    }
		    j++;
		}
		k++;
	}
	int max=0;

	for(int j=0;j<n;j++)
	{
		if(max<track[j])
		{
			max=track[j];
		}

	}

	cout<<"Longest increasing subsequence has length "<<max<<endl;

	while(max)
	{
		cout<<v[checkIndex(max,track,n)]<<'\t';
		max--;
	}

}