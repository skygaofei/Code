//
//  main.cpp
//  数的划分
//
//  Created by 高飞 on 2018/8/5.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,k,ans;
void dfs(int rest,int last,int cnt)
{
    if(cnt>k){
        if(rest==0)
            ans++;
        return;
    }
    for(int i=last;i<=rest;i++)
        dfs(rest-i,i,cnt+1);
}
int main()
{
    scanf("%d%d",&n,&k);
    dfs(n,1,1);
    printf("%d",ans);
    return 0;
}
