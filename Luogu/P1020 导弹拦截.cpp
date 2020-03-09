//
//  main.cpp
//  LIS nlogn算法
//
//  Created by 高飞 on 2018/8/7.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int num[100005];
int f[100005];
int main()
{
    int x,s=0;
    while(scanf("%d",&x)!=EOF)
        num[++s]=x;
    f[0]=0x3f3f3f3f;
    int ans=0;
    for(int i=1;i<=s;i++)
    {
        if(f[ans]>=num[i])
        {
            f[ans+1]=num[i];
            ans++;
        }
        else
        {
            int l=0,r=ans,mid;
            while(l<r)
            {
                mid=(l+r)/2;
                if(f[mid]>=num[i])
                    l=mid+1;
                else
                    r=mid;
            }
            if(l!=0)
                f[l]=num[i];
        }
    }
    printf("%d\n",ans);
    ans=0;
    memset(f,-1,sizeof(f));
    for(int i=1;i<=s;i++)
    {
        if(f[ans]<num[i])
        {
            f[ans+1]=num[i];
            ans++;
        }
        else
        {
            int l,r,mid;
            l=0;r=ans;
            while(l<r)
            {
                mid=(l+r)/2;
                if(f[mid]>=num[i])
                    r=mid;
                else
                    l=mid+1;
            }
            f[l]=num[i];
        }
    }
    printf("%d",ans);
    return 0;
}