//
//  花匠.cpp
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
#define maxn 1000005
#define re register
using namespace std;
int n,height[maxn],ans=1;
bool flag;
int main()
{
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&height[i]);
    if(height[2]>=height[1])
        flag=true;
    for(re int i=1;i<=n;++i)
    {
        if(!flag&&i==n)
        {
            ans++;
            break;
        }
        if(flag)
            if(height[i+1]<height[i])
            {
                ans++;
                flag=false;
                continue;
            }
        if(!flag)
            if(height[i+1]>height[i])
            {
                ans++;
                flag=true;
                continue;
            }
    }
    printf("%d",ans);
    return 0;
}
