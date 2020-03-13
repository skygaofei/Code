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
using namespace std;
const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int y,m;
    scanf("%d%d",&y,&m);
    if(m==2)
    {
        if(y%4==0&&y%100!=0)
            printf("%d",month[m]+1);
        else if(y%4==0&&y%400==0)
            printf("%d",month[m]+1);
        else
            printf("%d",month[m]);
    }
    else
        printf("%d",month[m]);
    return 0;
}
