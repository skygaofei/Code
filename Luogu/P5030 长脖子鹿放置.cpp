#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#define maxn 205
#define re register
using namespace std;
vector<int> son[maxn*maxn];
int vis[maxn*maxn],timemark,link[maxn*maxn];
int n,able[maxn][maxn],_n;
int target[maxn*maxn];
int counter;
int nxt[8][2]={{1,3},{-1,3},{1,-3},{-1,-3},{3,1},{-3,1},{3,-1},{-3,-1}};
inline bool find(int x)
{
    for(re int i=0;i<son[x].size();++i)
    {
        int p=son[x][i];
        if(vis[p]!=timemark)
        {
            vis[p]=timemark;
            if(!link[p]||find(link[p]))
            {
                link[p]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int k,m;
    scanf("%d%d%d",&n,&m,&k);
    int x,y;
    for(re int i=1;i<=k;++i)
        scanf("%d%d",&x,&y),able[x][y]=-1;
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=m;++j)
            if(able[i][j]!=-1)
                able[i][j]=++_n;
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=m;++j)
            if(able[i][j]!=-1&&i%2==0)
            {
                for(re int k=0;k<8;k++)
                    if(i+nxt[k][0]>=1&&i+nxt[k][0]<=n&&j+nxt[k][1]>=1&&j+nxt[k][1]<=m&&able[i+nxt[k][0]][j+nxt[k][1]]!=-1)
                        son[able[i][j]].push_back(able[i+nxt[k][0]][j+nxt[k][1]]);
                target[++counter]=able[i][j];
            }
    int ans=0;
    for(re int i=1;i<=n*m;++i)
    {
        timemark++;
        if(find(i))
            ans++;
    }
    printf("%d",n*m-ans-k);
    return 0;
}