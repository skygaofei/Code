//
//  次短路.cpp
//  
//
//  Created by 高飞 on 2018/7/27.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define maxn 10005
using namespace std;
int n,m,dis[maxn];vector<int> son[maxn],v[maxn];
bool bein[maxn];
queue<int> q;
void Set(int prt,int to,int d)
{
    son[prt].push_back(to),v[prt].push_back(d);
}
void Spfa(int S)
{
    memset(dis,0x3f,sizeof(dis));
    dis[S]=0,q.push(S),bein[S]=true;
    while(!q.empty())
    {
        int rt=q.front();q.pop(),bein[rt]=false;
        for(int i=0;i<son[rt].size();i++)
        {
            int to=son[rt][i];
            if(dis[to]>dis[rt]+v[rt][i])
            {
                dis[to]=dis[rt]+v[rt][i];
                if(!bein[to])
                    q.push(to),bein[to]=true;
            }
        }
    }
}
struct Node
{
    int x,d;
    bool operator < (const Node &a)const{
        return d+dis[x]>a.d+dis[a.x];
    }
};priority_queue<Node> Q;
int Astar(int S,int T)
{
    Q.push((Node){S,0});
    while(!Q.empty())
    {
        Node prt=Q.top();Q.pop();
        int rt=prt.x;
        if(rt==T&&prt.d>dis[S])
            return prt.d;
        for(int i=0;i<son[rt].size();i++)
            Q.push((Node){son[rt][i],prt.d+v[rt][i]});
    }
}
int main()
{
    //freopen("dota.in","r",stdin);
    //freopen("dota.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x,y,z,p;
    while(m--)
        scanf("%d%d%d",&x,&y,&z),Set(x,y,z),Set(y,x,z);
    Spfa(n);
    printf("%d\n",Astar(1,n));
    return 0;
}