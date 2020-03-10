#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001],c[1001],d[1001],n,sum;
void shuchu()
{
	sum++;
	if(sum<=3)
	{
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
}
void dfs(int s)
{
	for(int i=1;i<=n;i++)
	{
		if(!b[i]&&!c[s+i]&&!d[s-i+n-1])
		{
			a[s]=i;
			b[i]=1;
			c[s+i]=1;
			d[s-i+n-1]=1;
			if(s==n)
				shuchu();
			else
				dfs(s+1);
			b[i]=0;
			c[s+i]=0;
			d[s-i+n-1]=0;
		}	
	}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<sum;
 	return 0;
}
