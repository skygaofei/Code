//
//  main.cpp
//  小木棍
//
//  Created by 高飞 on 2018/8/5.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,num[70],x,sum=0,length,m;
bool used[70];
int minn=70,maxn=-70,p;
void dfs(int cnt,int ans,int x,int rest)
{
    if(cnt==0)
    {
        printf("%d",x);
        exit(0);
    }
    if(ans==x)
        dfs(cnt-1,0,x,maxn);
    for(int i=rest;i>=minn;i--)
    {   if(num[i]&&i+ans<=x)
        {
            num[i]--;
            dfs(cnt,ans+i,x,i);
            num[i]++;
            if(ans==0||ans+i==x)
                break;
        }
    }
    return ;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x<=50){
            p++;
            num[x]++;
            sum+=x;
            maxn=max(maxn,x);
            minn=min(minn,x);
        }
    }
    x=sum>>1;
    for(int i=maxn;i<=x;i++)
        if(sum%i==0)
            dfs(sum/i,0,i,maxn);
    printf("%d",sum);
    return 0;
}
