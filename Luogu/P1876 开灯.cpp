#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s=0;
	for(int i=1;i*i<=n;i++)
	{
		if(i*i<=n)
			cout<<i*i<<' ';
	}
	return 0;
}