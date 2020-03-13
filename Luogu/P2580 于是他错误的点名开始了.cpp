//
//  P2580 于是他错误的点名开始了.cpp
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
map<string,int> m;
int n,q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    string a;
    for(re int i=1;i<=n;++i)
        cin>>a,m[a]=1;
    cin>>q;
    for(re int i=1;i<=q;++i)
    {
        cin>>a;
        if(m[a]==1)
            printf("OK\n"),m[a]=2;
        else if(m[a]==2)
            printf("REPEAT\n");
        else
            printf("WRONG\n");
    }
    return 0;
}
