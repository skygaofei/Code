//
//  main.cpp
//  P3374 【模板】树状数组 1 线段树
//
//  Created by 高飞 on 2018/7/30.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 500005
using namespace std;
struct point
{
    int l,r,val;
}tr[maxn*4];
int m,n,cnt,a,b,c,p[maxn];
char op[10];
void buildtree(int x,int l,int r)
{
    tr[x].l=l;
    tr[x].r=r;
    if(l==r)
    {
        tr[x].val=p[l];
        return;
    }
    int lch=x*2,rch=x*2+1;
    int mid=(l+r)/2;
    buildtree(lch,l,mid);
    buildtree(rch,mid+1,r);
    tr[x].val=tr[x*2].val+tr[x*2+1].val;
}
void modify(int x,int pos,int val)
{
    if(tr[x].r==tr[x].l)
    {
        tr[x].val+=val;
        return;
    }
    int mid=(tr[x].l+tr[x].r)/2;
    if(pos<=mid)
        modify(x*2,pos,val);
    else
        modify(x*2+1,pos,val);
    tr[x].val=tr[x*2].val+tr[x*2+1].val;
}
int query(int x,int l,int r)
{
    if(l<=tr[x].l&&tr[x].r<=r)
        return tr[x].val;
    int mid=(tr[x].l+tr[x].r)/2;
    int ans=0;
    if(l<=mid)
        ans+=query(x*2,l,r);
    if(r>mid)
        ans+=query(x*2+1,l,r);
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    buildtree(1,1,n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d%d",&b,&c);
            modify(1,b,c);
        }
        else
        {
            scanf("%d%d",&b,&c);
            printf("%d\n",query(1,b,c));
        }
    }
        
    return 0;
}
