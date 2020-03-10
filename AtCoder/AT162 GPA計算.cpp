//
//  AT162 GPA計算.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/10.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
using namespace std;
int n;
char op;
double ans;
int main()
{
    scanf("%d",&n);
    scanf("%c",&op);
    for(re int i=1;i<=n;++i)
    {
        op=getchar();
        switch(op)
        {
            case 'A': ans+=4;break;
            case 'B': ans+=3;break;
            case 'C': ans+=2;break;
            case 'D': ans+=1;break;
        }
    }
    ans=(ans+0.0000000)/(double)((double)n+0.00000000);
    printf("%.14lf",ans);
    return 0;
}
