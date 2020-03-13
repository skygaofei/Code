#include<bits/stdc++.h>
using namespace std;
int sy,sx,fy,fx,s=0,a[5][5];
int n,m,t;
int move[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
void dfs(int x,int y)
{
	if(a[x][y]==1)
		return;
	if(x==fx&&y==fy)
	{
		s++;
		return ;
	}
	else
	{
		for(int i=0;i<=3;i++)
		{
			if(x==fx&&y==fy)
			{
				s++;
				return;
			}
			if(x>=0&&y>=0&&x<n&&y<m)
			{
				a[x][y]=1;
				dfs(x+move[i][0],y+move[i][1]);
				a[x][y]=0;
			}	
		}
	}
}
int main()
{
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	sx=sx-1;sy=sy-1;fy=fy-1;fx=fx-1;
	a[fx][fy]=2;
	int i;
	for(i=1;i<=t;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x-1][y-1]=1;
	}
	dfs(sx,sy);
	cout<<s;
 	return 0;
}