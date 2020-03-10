// luogu-judger-enable-o2
//
//  exgcd.cpp
//  7.20集训
//
//  Created by skygao on 2019/7/20.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> exgcd(int a,int b)
{
    if(a==1&&b==0)
        return make_pair(1,0);
    pair<int,int> tmp=exgcd(b,a%b);
    return make_pair(tmp.second,tmp.first-(a/b)*tmp.second);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    pair<int,int> ans=exgcd(a,b);
    printf("%d",(ans.first%b+b)%b);
    return 0;
}
