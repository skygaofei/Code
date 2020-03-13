#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define maxn 1005
#define re register
using namespace std;
int link[maxn],vis[maxn],n,m,tmp1,tmp2,timemark=1,cnt=0,ans[maxn];
vector<int> son[maxn];
bool find(int x)
{
    for(re int i=0;i<son[x].size();++i)
    {
        int p=son[x][i];
        if(vis[p]!=timemark)
        {
            vis[p]=timemark;
            if(!link[p]||find(link[p]))
            {
                link[p]=x;ans[x]=p;
                return true;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=m;++i)
    {
        scanf("%d%d",&tmp1,&tmp2);
        son[i].push_back(tmp1);
        son[i].push_back(tmp2);
    }
    for(re int i=1;i<=m;++i)
    {
        if(find(i))
            cnt++;
        else
            break;
        timemark++;
    }
    printf("%d\n",cnt);
    for(re int i=1;i<=cnt;++i)
        printf("%d\n",ans[i]);
    return 0;
}