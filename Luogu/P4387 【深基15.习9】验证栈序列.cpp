//
//  深基.cpp
//  Algorithm
//
//  Created by skygao on 2020/1/30.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#define re register
#define ll long long
using namespace std;
int n,a[100005],b[100005];
stack<int> s;int k;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(re int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(re int i=1;i<=n;++i)
            scanf("%d",&b[i]);
        while(!s.empty()) s.pop();
        k=1;
        for(re int i=1;i<=n;++i)
        {
            s.push(a[i]);
            while(!s.empty()&&s.top()==b[k])
                s.pop(),k++;
        }
        if(!s.empty())
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
