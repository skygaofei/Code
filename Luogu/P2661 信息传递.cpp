//
//  main.cpp
//  信息传递
//
//  Created by 高飞 on 2018/8/6.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,num[200005],vis[200005],ans=0x3f3f3f3f,tim;
void dfs(int x)
{
    if(!num[x])
        return ;
    tim++;
    if(tim>vis[x]&&vis[x]!=0)
    {
        ans=min(ans,tim-vis[x]);
        num[x]=0;
        vis[x]=0;
        return;
    }
    vis[x]=tim;
    dfs(num[x]);
    vis[x]=0;
    num[x]=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;i++)
        dfs(i);
    printf("%d",ans);
    return 0;
}
