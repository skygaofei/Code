//
//  main.cpp
//  每日打卡心情好
//
//  Created by 高飞 on 2018/8/8.
//  Copyright © 2018年 高飞. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int N,t=0,number,ans=0,temp=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&number);
        if(number==1)
        {
            if(temp>0)
                ans=ans-pow(2,temp-1);
            if(ans<0)
                ans=0;
            t++;
            ans++;
            temp=0;
            if(ans>=3)
                t++;
            if(ans>=7)
                t++;
            if(ans>=30)
                t++;
            if(ans>=120)
                t++;
            if(ans>=365)
                t++;
        }
        else if(number==0)
            temp++;
    }
    printf("%d\n",t);
    return 0;
}
