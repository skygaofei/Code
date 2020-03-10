#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]==a[i])
			ans++;
		else
		{
			cout<<a[i-1]<<' '<<ans<<endl;
			ans=1;	
		}	
	}
	cout<<a[n]<<' '<<ans<<endl;
	return 0;
}