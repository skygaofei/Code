#include<bits/stdc++.h>
using namespace std;
int n,a[10001];
void shuchu()
{
	cout<<a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=0)
			cout<<'+'<<a[i];
	}
	cout<<endl;
}
void dfs(int x,int s)
{
	if(x==0)
	{ 
		shuchu();
	} 
	for(int i=a[s-1];i<=n;i++)
	{
		if(i<=x&&i!=0&&i!=n)
		{
			x=x-i;
			a[s]=i;
			dfs(x,s+1);
			a[s]=0;
			x=x+i;
		}
	}
}
int main()
{
	cin>>n;
	dfs(n,1);
 	return 0;
}
