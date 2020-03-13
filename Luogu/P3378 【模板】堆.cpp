//
//  main.cpp
//  模板【堆】
//
//  Created by 高飞 on 2018/8/7.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > q;
    int a,x,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d",&x);
            q.push(x);
        }
        else if(a==2)
            printf("%d\n",q.top());
        else if(a==3)
                q.pop();
    }
    return 0;
}
