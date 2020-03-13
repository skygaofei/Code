#include<bits/stdc++.h>
using namespace std;
int n,m,total;
void dfs(int x,int y)
{
	if(x==n&&y==m)
		total++;
	else
	{
		if(x>=0&&y>=0&&x<=n&&y<=m)
		{
			dfs(x+2,y+1);
			dfs(x+1,y+2);
			dfs(x-1,y+2);
			dfs(x-2,y+1);
		}
		else
			return ;
	}
}
int main()
{
	cin>>n>>m;
	dfs(0,0);
	cout<<total;
 	return 0;
}
