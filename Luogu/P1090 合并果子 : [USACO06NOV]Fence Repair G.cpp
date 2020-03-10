//
//  main.cpp
//  合并果子
//
//  Created by 高飞 on 2018/8/8.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n,sum;
int main()
{
    scanf("%d",&n);
    int p,l;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        q.push(p);
    }
    sum=0;
    for(int i=1;i<=n-1;i++)
    {
        p=q.top();q.pop();
        l=q.top();q.pop();
        sum+=p+l;
        p+=l;
        q.push(p);
    }
    printf("%d",sum);
    return 0;
}
