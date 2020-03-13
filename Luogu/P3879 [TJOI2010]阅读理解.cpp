//
//  P3879 [TJOI2010]阅读理解.cpp
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
#include <set>
#define re register
using namespace std;
int n,m,k;
map<string,set<int> > book;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>n;
    for(re int i=1;i<=n;++i)
    {
        cin>>k;
        for(re int j=1;j<=k;++j)
            cin>>s,book[s].insert(i);
    }
    cin>>m;
    for(re int i=1;i<=m;++i)
    {
        cin>>s;
        if(book[s].empty())
            goto end;
        for(re set<int>::iterator it=book[s].begin();it!=book[s].end();++it)
            printf("%d ",*it);
        end:
            printf("\n");
    }
    return 0;
}
