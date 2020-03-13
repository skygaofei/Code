#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
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
char s[maxn];
int nxt[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
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
        scanf("%s",s);
        for(re int j=0;j<n;++j)
        {
            if(s[j]=='0')
                able[i][j+1]=++_n;
            else
                able[i][j+1]=-1;
        }
    }
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=n;++j)
            if(able[i][j]!=-1&&(i+j)%2==0)
            {
                for(re int k=0;k<8;k++)
                    if(i+nxt[k][0]>=1&&i+nxt[k][0]<=n&&j+nxt[k][1]>=1&&j+nxt[k][1]<=n&&able[i+nxt[k][0]][j+nxt[k][1]]!=-1)
                        son[able[i][j]].push_back(able[i+nxt[k][0]][j+nxt[k][1]]);
                target[++counter]=able[i][j];
            }
    int ans=0;
    for(re int i=1;i<=counter;++i)
    {
        timemark++;
        if(find(target[i]))
            ans++;
    }
    printf("%d",_n-ans);
    return 0;
}