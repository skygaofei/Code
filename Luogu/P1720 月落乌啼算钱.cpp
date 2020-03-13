//
//  main.cpp
//  月落乌啼算钱
//
//  Created by 高飞 on 2018/2/7.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    long long x;
    cin>>x;
    if(x==0)
    {
        cout<<"0.00";
        return 0;
    }
    long long f[101];
    f[1]=1;
    f[2]=1;
    f[3]=2;
    for(int i=4;i<=x;i++)
        f[i]=f[i-1]+f[i-2];
    printf("%.2lf",double(f[x]));
    return 0;
}
