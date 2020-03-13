//
//  main.cpp
//  抓住那头牛
//
//  Created by 高飞 on 2018/8/5.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool vis[1000005];
struct que
{
    int x,step;
}tx;
int main() {
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        queue<que> q;
        scanf("%d%d",&x,&y);
        q.push((que){x,0});
        while(!q.empty())
        {
            tx=q.front();
            vis[tx.x]=true;
            if(tx.x==y)
            {
                printf("%d\n",tx.step);
                break;
            }
            q.pop();
            if(tx.x*2<=500000)
                if(!vis[tx.x*2])
                    q.push((que){tx.x*2,tx.step+1});
            if(tx.x-1<=500000&&tx.x>=0)
                if(!vis[tx.x-1])
                    q.push((que){tx.x-1,tx.step+1});
            if(tx.x+1<=500000)
                if(!vis[tx.x+1]  )
                    q.push((que){tx.x+1,tx.step+1});
        }
    }
    return 0;
}