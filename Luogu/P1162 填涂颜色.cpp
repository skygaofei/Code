#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],sx,sy,tx,ty,step[4][2]={{1,0},{0,1},{-1,0},{0,-1}},h=1,t=1;
int n;
struct que
{
	int x,y;
}q[10001];
void clean()
{
	h=1;t=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==2)
				a[i][j]=-1;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	bool f;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0&&a[i-1][j]==1&&a[i][j+1]==1)
			{
				sx=i;
				sy=j;
			}
		}
	q[t].x=0;
	q[t].y=0;
	a[0][0]=-1;
	t++;
	while(h<=t)
	{
		sx=q[h].x;
		sy=q[h].y;
		for(i=0;i<=3;i++)
		{
			tx=sx+step[i][0];
			ty=sy+step[i][1];
			if(a[tx][ty]==0&&tx>=0&&tx<=n+1&&ty>=0&&ty<=n+1)
			{
				a[tx][ty]=-1;
				q[t].x=tx;
				q[t].y=ty;
				t++;
			}
		}
		h++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==-1)
				cout<<0<<' ';
			else if(a[i][j]==0)
				cout<<2<<' ';
			else
				cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}