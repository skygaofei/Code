//
//   Mirror String.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/13.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string a,b;
    cin>>b;
    a=b;
    reverse(b.begin(),b.end());
    for(re int i=0;i<b.length();++i)
        switch(b[i])
        {
            case 'b':b[i]='d';break;
            case 'd':b[i]='b';break;
            case 'p':b[i]='q';break;
            case 'q':b[i]='p';break;
        }
    if(a==b)
        printf("Yes");
    else
        printf("No");
    return 0;
}
