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
struct Student
{
    int num,score1,score2;
    double sum;
    int Sum()
    {
        return score1+score2;
    }
    string judge()
    {
        return (score1+score2)>140&&sum>=80?"Excellent\n":"Not excellent\n";
    }
}x;
int main()
{
    int n;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d%d%d",&x.num,&x.score1,&x.score2),x.sum=x.score1*0.7+x.score2*0.3,cout<<x.judge();
    return 0;
}
