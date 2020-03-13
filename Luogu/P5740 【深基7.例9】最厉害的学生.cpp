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
#define re register
#define ll long long
using namespace std;
struct student
{
    char name[10];
    int ch,ma,en,sum;
}stu[1005];
int ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%s%d%d%d",stu[i].name,&stu[i].ch,&stu[i].ma,&stu[i].en),stu[i].sum=stu[i].ch+stu[i].ma+stu[i].en;
    for(re int i=1;i<n;++i)
        for(re int j=i+1;j<=n;++j)
            if(stu[i].sum<stu[j].sum)
                swap(stu[i],stu[j]);
    printf("%s %d %d %d",stu[1].name,stu[1].ch,stu[1].ma,stu[1].en);
    return 0;
}
