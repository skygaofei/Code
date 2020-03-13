//
//  main.cpp
//  luogu 3368 树状数组2
//
//  Created by 高飞 on 2018/7/30.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int c[500005],n,m,a[500005],x,y,z,s[500005];
int lowbit(int x)
{
    return x&-x;
}
int query(int x)
{
    int ans=0;
    while(x)
    {
        ans+=c[x];
        x=x-lowbit(x);
    }
    return ans;
}
void modify(int x,int value)
{
    while(x<=n)
    {
        c[x]+=value;
        x=x+lowbit(x);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        s[i]=a[i]-a[i-1];
        modify(i,s[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d%d%d",&x,&y,&z);
            modify(x,z);
            modify(y+1,-z);
        }
        else if(x==2)
        {
            scanf("%d",&y);
            printf("%d\n",query(y));
        }
    }
    return 0;
}
