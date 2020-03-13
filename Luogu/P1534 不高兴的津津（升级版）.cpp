//
//  main.cpp
//  不高兴的津津
//
//  Created by 高飞 on 2018/8/7.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,x,y,hpp,h;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        hpp+=x+y-8;
        h+=hpp;
    }
    printf("%d",h);
    return 0;
}
