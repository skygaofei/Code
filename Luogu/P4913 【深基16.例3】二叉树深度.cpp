//
//  深基.cpp
//  Algorithm
//
//  Created by skygao on 2020/1/30.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define re register
#define ll long long
#define maxn 1000005
using namespace std;
vector<int> son[maxn];
int in[maxn],depth[maxn];
int ans=-1,root;
void addedge(int x,int y)
{
    son[x].push_back(y);
}
void dfs(int x,int S)
{
    depth[x]=depth[S]+1;
    ans=max(ans,depth[x]);
    for(re int i=0;i<son[x].size();++i)
    {
        int rt=son[x][i];
        if(rt==S)
            continue;
        dfs(rt,x);
    }
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        if(x==0&&y==0)
            continue;
        addedge(i,x),addedge(i,y);
        in[x]++,in[y]++;
    }
    for(re int i=1;i<=n;++i)
        if(in[i]==0)
        {
            root=i;
            break;
        }
    dfs(root,root);
    printf("%d",ans);
    return 0;
}
