#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100],i,s=0;
	for(i=0;i<100;i++)
	{
		cin>>a[i];
		s++;
		if(a[i]==0)
			break;
	}
	for(i=s-2;i>=0;i--)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}
