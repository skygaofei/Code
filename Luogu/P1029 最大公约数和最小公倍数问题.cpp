//
//  main.cpp
//  P1029
//
//  Created by 高飞 on 2018/8/8.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int ans=0;
    for(int i=1;i<=sqrt(y*x);i++)
    {
        if((x*y)%i==0)
            if(gcd((y*x)/i,i)==x)
                ans++;
    }
    printf("%d",ans*2);
    return 0;
}
