#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i,j,s=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<0<<' ';
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j])
				s++;
		}
		cout<<s<<' ';
		s=0; 
	}
	return 0;
}
