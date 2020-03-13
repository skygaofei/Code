//
//  P2184 贪婪大陆.cpp
//  7.24集训
//
//  Created by skygao on 2019/7/24.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 100005
#define lowbit(x) x&(-x)
#define re register
using namespace std;
int n,m;
int tr1[maxn],tr2[maxn];
inline void add_front(int x)
{
    while(x<=n)
    {
        ++tr1[x];
        x+=lowbit(x);
    }
}
inline void add_back(int x)
{
    while(x<=n)
    {
        ++tr2[x];
        x+=lowbit(x);
    }
}
inline int sum_front(int x)
{
    int s=0;
    while(x>0)
    {
        s+=tr1[x];
        x-=lowbit(x);
    }
    return s;
}
inline int sum_back(int x)
{
    int s=0;
    while(x>0)
    {
        s+=tr2[x];
        x-=lowbit(x);
    }
    return s;
}
int main()
{
    int ans=0;
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=m;++i)
    {
        int x,y,op;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            add_front(x);
            add_back(y);
        }
        else
        {
            ans=sum_front(y)-sum_back(x-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
