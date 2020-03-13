//
//  main.cpp
//  luogu 3372 线段树
//
//  Created by 高飞 on 2018/7/30.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 100005
using namespace std;
struct point
{
    long long l,r,val,mark;
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
void release(int x)
{
    if(tr[x].mark&&tr[x].l<tr[x].r)
    {
        int lch=x*2,rch=x*2+1;
        tr[lch].val+=tr[x].mark*((long long)tr[lch].r-tr[lch].l+1);
        tr[lch].mark+=tr[x].mark;
        tr[rch].val+=tr[x].mark*((long long)tr[rch].r-tr[rch].l+1);
        tr[rch].mark+=tr[x].mark;
    }
    tr[x].mark=0;
}
void modify(int x,int l,int r,long long k)
{
    release(x);
    if(l<=tr[x].l&&tr[x].r<=r)
    {
        tr[x].val+=k*((long long)tr[x].r-tr[x].l+1);
        tr[x].mark+=k;
        return;
    }
    long long mid=(tr[x].l+tr[x].r)/2;
    if(l<=mid)
        modify(x*2,l,r,k);
    if(mid<r)
        modify(x*2+1,l,r,k);
    tr[x].val=tr[x*2].val+tr[x*2+1].val;
}
long long query(int x,int l,int r)
{
    release(x);
    if(l<=tr[x].l&&tr[x].r<=r)
        return tr[x].val;
    long long mid=(tr[x].l+tr[x].r)/2;
    long long ans=0;
    if(l<=mid)
        ans+=query(x*2,l,r);
    if(r>mid)
        ans+=query(x*2+1,l,r);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    buildtree(1,1,n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            modify(1,x,y,k);
        }
        else
        {
            scanf("%d%d",&b,&c);
            printf("%lld\n",query(1,b,c));
        }
    }
    return 0;
}
