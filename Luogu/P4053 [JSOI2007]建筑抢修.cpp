//
//  main.cpp
//  建筑抢修
//
//  Created by 高飞 on 2018/10/5.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int n;
struct building
{
    int t1,t2;
}a[150005];
priority_queue<int> q;
bool cmp(building a,building b)
{
    return a.t2<b.t2;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].t1,&a[i].t2);
    sort(a+1,a+n+1,cmp);
    int tim=0;
    int answer=0;
    for(int i=1;i<=n;i++)
    {
        if(tim+a[i].t1>a[i].t2)
        {
            if(a[i].t1<q.top())
            {
                tim-=q.top();
                q.pop();
                q.push(a[i].t1);
                tim+=a[i].t1;
            }
        }
        else
        {
            q.push(a[i].t1);
            answer++;
            tim+=a[i].t1;
        }
    }
    printf("%d",answer);
    return 0;
}
