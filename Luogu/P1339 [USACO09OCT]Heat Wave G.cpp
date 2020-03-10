// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 10005
#define re register
using namespace std;
vector<int> son[maxn],v[maxn];
inline void add(int x,int y,int z) {
    son[x].push_back(y);
    v[x].push_back(z);
}
int n,m,src;
int dis[maxn];
struct Node {
    int x,dis;
    bool operator < (const Node &a)const {
        return dis>a.dis;
    }
};priority_queue<Node> q;
int vis[maxn],tim;
void Dijikstra(int S)
{
    memset(dis,0x3f,sizeof(dis));
    dis[S]=0,tim++;q.push((Node){S,0});
    while (!q.empty()) {
        Node prt=q.top();q.pop();
        int rt=prt.x;
        if(vis[rt]==tim)
            continue;
        vis[rt]=tim;
        for(re int i=0;i<son[rt].size();++i) {
            int to=son[rt][i];
            if(dis[to]>dis[rt]+v[rt][i])
                dis[to]=dis[rt]+v[rt][i],q.push((Node){to,dis[to]});
        }
    }
}
int main() {
    int x,y,z;
    src=0;
    int src1;
    scanf("%d%d%d%d",&n,&m,&src,&src1);
    for(re int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    Dijikstra(src);
    printf("%d",dis[src1]);
    return 0;
}
