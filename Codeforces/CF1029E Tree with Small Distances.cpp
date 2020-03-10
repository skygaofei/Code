#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#define N 201001
#define ll long long
using namespace std;
vector<int>e[N];
int n;
int f[N][3];
void dfs(int x,int fa)
{
    int m=9999999;
    for(int i=0;i<e[x].size();i++)
        if(e[x][i]!=fa)
        {
            dfs(e[x][i],x);
            f[x][0]+=f[e[x][i]][1];
            f[x][1]+=f[e[x][i]][1];
            f[x][2]+=f[e[x][i]][0];
            m=min(m,f[e[x][i]][2]-f[e[x][i]][1]);
        }
    f[x][2]++;
    f[x][1]=min(f[x][1]+m,f[x][2]);
    f[x][0]=min(f[x][0],f[x][1]);
}
int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    cin >> n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    int ans=0;
    for(int i=0;i<e[1].size();i++)
        ans+=f[e[1][i]][2]-1;
    cout << ans << endl;
    return 0;
    
}
