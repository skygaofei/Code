//
//  ha.cpp
//  10.6考试
//
//  Created by 高飞 on 2018/10/6.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#define ll long long
#define maxn 200005
using namespace std;
int n,a,b;
ll sum=0,ans=0;
struct Node
{
    ll x,y;
}arr[maxn];
bool cmp(Node a,Node b)
{
    return a.x-a.y>b.x-b.y;
}
int main()
{
    //freopen("ha.in","r",stdin);
    //freopen("ha.out","w",stdout);
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&arr[i].x,&arr[i].y);
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(i<=b)
            sum+=max(arr[i].x,arr[i].y);
        else
            sum+=arr[i].y;
    }
    ans=sum;
    for(int i=1;i<=b;i++)
        ans=max(ans,sum-max(arr[i].x,arr[i].y)+(arr[i].x<<a));
    sum=sum-max(arr[b].x,arr[b].y)+arr[b].y;
    for(int i=b+1;i<=n&&(b!=0);i++)
        ans=max(ans,sum-arr[i].y+(arr[i].x<<a));
    printf("%lld",ans);
    return 0;
}
