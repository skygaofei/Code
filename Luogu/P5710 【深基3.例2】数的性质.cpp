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
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d %d %d %d",(!(x&1)&&(x>4&&x<=12)),(!(x&1)||(x>4&&x<=12)),(!(x&1)^(x>4&&x<=12)),((x&1)&&!(x>4&&x<=12)));
    return 0;
}
