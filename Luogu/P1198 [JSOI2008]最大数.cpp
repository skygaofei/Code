//
//  main.cpp
//  luogu 1198 最大数
//
//  Created by 高飞 on 2018/7/30.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 200005
using namespace std;
struct point
{
    int l,r,mx;
}tr[maxn*4];
int m,d,lastans,cnt;
char op[10];
void buildtree(int x,int l,int r)
{
    tr[x].l=l;
    tr[x].r=r;
    if(l==r)
        return;
    int lch=x*2,rch=x*2+1;
    int mid=(l+r)/2;
    buildtree(lch,l,mid);
    buildtree(rch,mid+1,r);
}
void modify(int x,int pos,int val)
{
    if(tr[x].r==tr[x].l)
    {
        tr[x].mx=val;
        return;
    }
    int mid=(tr[x].l+tr[x].r)/2;
    if(pos<=mid)
        modify(x*2,pos,val);
    else
        modify(x*2+1,pos,val);
    tr[x].mx=max(tr[x*2].mx,tr[x*2+1].mx);
}
int query(int x,int l,int r)
{
    if(l<=tr[x].l&&tr[x].r<=r)
        return tr[x].mx;
    int mid=(tr[x].l+tr[x].r)/2;
    int ans=0;
    if(l<=mid)
        ans=max(ans,query(x*2,l,r));
    if(r>mid)
        ans=max(ans,query(x*2+1,l,r));
    return ans;
}
int main()
{
    scanf("%d%d",&m,&d);
    buildtree(1,1,m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s",op);
        if(op[0]=='Q')
        {
            int L;
            scanf("%d",&L);
            lastans=query(1,cnt-L+1,cnt);
            printf("%d\n",lastans);
        }
        else
        {
            int n;
            scanf("%d",&n);
            modify(1,++cnt,((long long)n+lastans)%d);
        }
    }
    return 0;
}
