// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 1005
#define re register
using namespace std;
struct Node
{
    int key,val;
    Node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
};
vector<int> son[maxn];
queue<Node> q;
int tot[maxn];
int s[maxn];
bool vis[maxn][maxn],judge[maxn];
void add(int x,int y)
{
    son[x].push_back(y);
    tot[y]++;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int k;
    for(re int t=1;t<=m;++t)
    {
        scanf("%d",&k);
        memset(judge,0,sizeof(judge));
        for(re int i=1;i<=k;++i)
            scanf("%d",&s[i]),judge[s[i]]=true;
        for(re int i=s[1];i<=s[k];++i)
        {
            if(judge[i])
                continue;
            for(re int j=1;j<=k;++j)
                if(!vis[i][s[j]])
                    add(i,s[j]),vis[i][s[j]]=true;
        }
    }
    for(re int i=1;i<=n;++i)
        if(!tot[i])
            q.push(Node(i,1));
    int ans=1;
    while(!q.empty())
    {
        Node prt=q.front();q.pop();
        for(re int i=0;i<son[prt.key].size();++i)
        {
            int to=son[prt.key][i];
            --tot[to];
            if(!tot[to])
                q.push(Node(to,prt.val+1)),ans=max(ans,prt.val+1);
        }
    }
    printf("%d",ans);
    return 0;
}
