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
#include <map>
#define re register
#define ll long long
using namespace std;
string mp[55]={"XXX","X.X","X.X","X.X","XXX","..X","..X","..X","..X","..X","XXX","..X","XXX","X..","XXX","XXX","..X","XXX","..X","XXX","X.X","X.X","XXX","..X","..X","XXX","X..","XXX","..X","XXX","XXX","X..","XXX","X.X","XXX","XXX","..X","..X","..X","..X","XXX","X.X","XXX","X.X","XXX","XXX","X.X","XXX","..X","XXX"};
string ans[6];
void print(int x)
{
    for(re int i=x*5;i<=x*5+4;++i)
        ans[i%5+1]+=mp[i];
}
void add()
{
    for(re int i=1;i<=5;++i)
        ans[i]+='.';
}
int main()
{
    int n;
    scanf("%d",&n);
    int x;
    scanf("%1d",&x);
    print(x);
    for(re int i=2;i<=n;++i)
        scanf("%1d",&x),add(),print(x);
    for(re int i=1;i<=5;++i)
        cout<<ans[i]<<endl;
    return 0;
}
