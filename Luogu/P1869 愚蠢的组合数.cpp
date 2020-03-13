//
//  main.cpp
//  parity
//
//  Created by 高飞 on 2018/8/10.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int a,b;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {scanf("%d%d",&a,&b);
    if((a&b)==b)
        printf("1\n");
    else
        printf("0\n");}
    return 0;
}
