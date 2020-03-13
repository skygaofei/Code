// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 25005
#define re register
using namespace std;
vector<int> son[maxn],v[maxn];
inline void add(int x,int y,int z) {
    son[x].push_back(y);
    v[x].push_back(z);
}
deque<int> q;
int n,m1,m2,src;
int dis[maxn];
bool vis[maxn];
void spfa(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0,vis[s]=true,q.push_back(s);
    while(!q.empty())
    {
        int now=q.front();q.pop_front();
        for(re int i=0;i<son[now].size();++i)
        {
            if(dis[son[now][i]]>dis[now]+v[now][i]){
                dis[son[now][i]]=dis[now]+v[now][i];
                if(!vis[son[now][i]])
                {
                   if(!q.empty()&&dis[son[now][i]]>=dis[q.front()])
                       q.push_back(son[now][i]);
                   else
                       q.push_front(son[now][i]);
                   vis[son[now][i]]=true;
                 }
            }
        }
        vis[now]=false;
    }
}
int main() {
    int x,y,z;
    scanf("%d%d%d%d",&n,&m1,&m2,&src);
    for(re int i=1;i<=m1;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    for(re int i=1;i<=m2;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    spfa(src);
    for(re int i=1;i<=n;++i)
    {
        if(dis[i]==0x3f3f3f3f)
            printf("NO PATH\n");
        else {
            printf("%d\n",dis[i]);
        }
    }
    return 0;
}
