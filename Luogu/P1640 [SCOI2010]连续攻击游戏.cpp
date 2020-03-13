// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define maxn 1000005
#define re register
using namespace std;
int link[maxn],vis[maxn],n,tmp1,tmp2,timemark=1,cnt=0;
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
                link[p]=x;
                return true;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
    {
        scanf("%d%d",&tmp1,&tmp2);
        son[tmp1].push_back(i);
        son[tmp2].push_back(i);
    }
    for(re int i=1;i<=n;++i)
    {
        if(find(i))
            cnt++;
        else
            break;
        timemark++;
    }
    printf("%d",cnt);
    return 0;
}