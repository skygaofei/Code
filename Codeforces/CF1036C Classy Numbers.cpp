//
//  main.cpp
//  miracle
//
//  Created by 高飞 on 2018/10/4.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> num;
void precaul(int index,int cnt,long long sum)
{
    if(index>=18)
    {
        num.push_back(sum);
        return ;
    }
    precaul(index+1,cnt,sum*10);
    if(cnt<3)
        for(int i=1;i<=9;i++)
            precaul(index+1,cnt+1,sum*10+i);
    
}
int main()
{
    int t;
    scanf("%d",&t);
    precaul(0, 0, 0);
    num.push_back(1000000000000000000);
    long long l,r;
    for(int o=1;o<=t;o++)
    {
        scanf("%lld%lld",&l,&r);
        printf("%d\n",upper_bound(num.begin(),num.end(),r)-lower_bound(num.begin(),num.end(),l));
    }
    return 0;
}
