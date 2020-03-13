//
//  main.cpp
//  互不侵犯King
//
//  Created by 高飞 on 2018/9/15.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
long long n,k;
long long maxn;
long long f[10][105][512];
bool book1[1005],book2[1005][1005];
long long value[1005];
long long cal(long long x)
{
    long long p=0;
    while(x)
    {
        if(x&1)
            p++;
        x>>=1;
    }
    return p;
}
int main()
{
    scanf("%lld%lld",&n,&k);
    maxn=(1<<n)-1;
    for(int i=0;i<=maxn;i++)
    {
        value[i]=cal(i);
        f[1][value[i]][i]=1;
    }
    for(int i=0;i<=maxn;i++)
        if((i&(i<<1))==0)
            book1[i]=true;
    for(int i=0;i<=maxn;i++)
        for(int j=0;j<=maxn;j++)
            if((i&j)==0&&(i&j>>1)==0&&(i&(j<<1))==0)
                book2[i][j]=true;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=maxn;j++)
        {
            if(book1[j])
            {
                for(int p=0;p<=maxn;p++)
                {
                    if(book1[p]&&book2[j][p])
                    {
                        for(long long temp=value[j];temp+value[p]<=k;temp++)
                            f[i][temp+value[p]][p]+=f[i-1][temp][j];
                    }
                }
            }
        }
    long long answer=0;
    for(int i=0;i<=maxn;i++)
        answer+=f[n][k][i];
    printf("%lld",answer);
    return 0;
}