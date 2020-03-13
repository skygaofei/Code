#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <iostream>
#define re register
#define maxm 1000005
#define getid(a,b) (a-1)*m+b 
#define maxn 250005
using namespace std;
int point[maxn],nex[maxm],to[maxm],cnt;
bool val[maxm];
char mp[505][505];
int n,m;
inline void addedge(int x,int y,int v)
{
	nex[++cnt]=point[x];
	to[cnt]=y;
	val[cnt]=v;
	point[x]=cnt;
}
int nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}},tx,ty;
struct Node
{
	int x,dis;
	bool operator < (const Node &a)const
	{
		return dis>a.dis;
	}
};priority_queue<Node> q;
int dis[maxn],sx,sy,px,py;bool vis[maxn];
inline void init()
{
	memset(point,0,sizeof(point));
	cnt=0;
}
void Dijkstra(int S)
{
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[S]=0,q.push((Node){S,0});
	while(!q.empty())
	{
		Node prt=q.top();q.pop();
		int rt=prt.x;
		if(vis[rt])
			continue;
		vis[rt]=true;
		for(re int i=point[rt];i;i=nex[i])
		{
			if(dis[to[i]]>dis[rt]+val[i])
			{
				dis[to[i]]=dis[rt]+val[i];
				q.push((Node){to[i],dis[to[i]]});
			}
		}	
	}
}
int main()
{
	//freopen("test.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		if(n==0&&m==0)
			return 0;
		for(re int i=1;i<=n;++i)
    		scanf("%s",mp[i]+1);
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j)
				for(re int k=0;k<4;++k)
				{
					tx=i+nxt[k][0];
					ty=j+nxt[k][1];
					if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
						addedge(getid(i,j),getid(tx,ty),(mp[i][j]!=mp[tx][ty]));
				}
		scanf("%d%d%d%d",&sx,&sy,&px,&py);
		sx++,sy++,px++,py++;
		Dijkstra(getid(sx,sy));
		printf("%d\n",dis[getid(px,py)]);
	}
	return 0;
}
