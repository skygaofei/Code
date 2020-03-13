//
//  P5149 会议座位.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/8.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#define re register
using namespace std;
inline int lowbit(int x){return x&(-x);}
int n,t[100005];string a;
map<string,int> book;
inline void add(int x)
{
    for(;x<=n;x+=lowbit(x))
        t[x]++;
}
inline int Query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=t[x];
    return res;
}
int main()
{
    long long result=0;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(re int i=1;i<=n;++i)
        cin>>a,book[a]=i;
    for(re int i=1;i<=n;++i)
        cin>>a,add(book[a]),result+=i-Query(book[a]);
    printf("%lld",result);
    return 0;
}
