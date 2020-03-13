#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int x[10005],y[10005];
bool vis[10005][10005];
int n,m,r,ans;
double dis(int x1,int x2,int y1,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>r;
    for(int i=1;i<=m;i++)
    {
    	cin>>x[i]>>y[i];
    	for(int j=1;j<=n;j++)
    		for(int k=1;k<=n;k++)
    		{
    			double temp=dis(x[i],j,y[i],k);
    			if(temp<=r)
    				vis[j][k]=true;
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(vis[i][j])
				ans++;
	cout<<ans;
    return 0;
}