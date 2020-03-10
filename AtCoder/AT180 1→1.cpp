//
//  AT180 1→1.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/14.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define re register
using namespace std;
int a[90005],b[90005];
int step[30006];bool vis[30005];
queue<int> q;
int main()
{
    int m,n,prt,rt;
    scanf("%d%d",&m,&n);
    for(re int i=1;i<=m;++i)
        scanf("%d%d",&a[i],&b[i]);
    q.push(1);
    vis[1]=true,step[1]=1;
    while(!q.empty())
    {
        prt=q.front();q.pop();
        if(prt==n)
        {
            printf("%d\n",step[prt]);
            return 0;
        }
        for(re int i=1;i<=m;++i)
            if(prt>=a[i])
            {
                rt=prt-a[i]+b[i];
                if(rt>=0&&rt<=n+305&&!vis[rt])
                    q.push(rt),vis[rt]=true,step[rt]=step[prt]+1;
            }
    }
    printf("-1\n");
    return 0;
}
