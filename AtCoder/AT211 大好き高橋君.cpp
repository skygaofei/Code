//
//  AT211 大好き高橋君.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/14.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;string s;
    cin>>n;
    int ans=0;
    for(re int i=1;i<=n;++i)
    {
        cin>>s;
        if(s=="TAKAHASHIKUN"||s=="Takahashikun"||s=="takahashikun"||s=="takahashikun."||s=="Takahashikun."||s=="TAKAHASHIKUN.")
            ans++;
            
    }
    printf("%d\n",ans);
    return 0;
}
