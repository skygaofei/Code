//
//  特技飞行.cpp
//  10.5晚上作业
//
//  Created by 高飞 on 2018/10/5.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
int n,k;
int c[305];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&c[i]);
    sort(c+1,c+k+1,cmp);
    int ans=0;
    int t1=1,t2=n;
    for(int i=1;i<=k;i++)
    {
        ans+=(t2-t1)*c[i];
        t2--;t1++;
        if(t1>=t2)
            break;
    }
    printf("%d",ans);
    return 0;
}
