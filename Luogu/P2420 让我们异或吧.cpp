#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#define maxn 1100000
#define maxm 2100000

using namespace std;

struct edge{
	int next,to,val;
}e1[maxm],e2[maxm];

int n,m[maxn],point1[maxn],point2[maxn],cnt1,cnt2,q;

void addedge1(int s,int t,int v)
{
	e1[++cnt1].to=t;
	e1[cnt1].val=v;
	e1[cnt1].next=point1[s];
	point1[s]=cnt1;
}

void addedge2(int s,int t,int v)
{
	e2[++cnt2].to=t;
	e2[cnt2].val=v;
	e2[cnt2].next=point2[s];
	point2[s]=cnt2;
}

void dfs(int fa,int x)
{
	for(int i=point1[x];i;i=e1[i].next)
	{
		int y=e1[i].to;
		if(y==fa)
			continue;
		addedge2(x,y,e1[i].val);
		dfs(x,y);
	}
}

void find(int x,int val)
{
	m[x]=val;
	for(int i=point2[x];i;i=e2[i].next)
		find(e2[i].to,e2[i].val^m[x]);
}

int main()
{
	//freopen("fish.in","r",stdin);
	//freopen("fish.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addedge1(a,b,c);
		addedge1(b,a,c);
	}
	dfs(0,1);
	find(1,0);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",m[a]^m[b]);
	}
    return 0;
}

