//
//  AT2084 CF.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/2/13.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string a;
    cin>>a;
    int pos1=a.find_first_of('C'),pos2=a.find_last_of('F');
    if(pos1>=0&&pos1<a.length()&&pos2>=0&&pos2<a.length())
    {
        if(pos1<pos2)
            printf("Yes");
        else
            printf("No");
    }
    else
        printf("No");
    return 0;
}
