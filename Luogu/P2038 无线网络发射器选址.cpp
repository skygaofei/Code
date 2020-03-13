//
//  无线网络发射器选址.cpp
//  qdojxyz刷题
//
//  Created by skygao on 2019/8/15.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 130
#define lowbit(x) (x&(-x))
#define re register
using namespace std;
int c[MAXN][MAXN];
int ans=0,maxn=-0x3f3f3f3f;
void add(int x,int y,int k)
{
    for(re int i=x;i<MAXN;i+=lowbit(i))
        for(re int j=y;j<MAXN;j+=lowbit(j))
            c[i][j]+=k;
}
int query(int x,int y)
{
    int ans=0;
    for(re int i=x;i>=1;i-=lowbit(i))
        for(re int j=y;j>=1;j-=lowbit(j))
            ans+=c[i][j];
    return ans;
}
int main()
{
    int d,n;
    scanf("%d%d",&d,&n);
    for(re int i=1;i<=n;i++)
    {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        add(x+1,y+1,k);
    }
    for(re int i=1;i<MAXN;i++)
        for(re int j=1;j<MAXN;j++)
        {
            int i1=i-d;
            if(i1<=0)
                i1=1;
            int i2=i+d;
            if(i2>=MAXN)
                i2=MAXN-1;
            int j1=j-d;
            if(j1<=0)
                j1=1;
            int j2=j+d;
            if(j2>=MAXN)
                j2=MAXN-1;
            int ans1=query(i2,j2)-query(i2,j1-1)-query(i1-1,j2)+query(i1-1,j1-1);
            if(ans1>maxn)
                ans=1,maxn=ans1;
            else if(ans1==maxn)
                ans++;
        }
    cout<<ans<<" "<<maxn;
    return 0;
}
