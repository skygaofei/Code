//
//  main.cpp
//  乘积最大3
//
//  Created by 高飞 on 2018/5/4.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
using namespace std;
int a[1000010];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        a[i]=n/m;
    for(int i=m;i>m-n%m;i--)
        a[i]++;
    for(int i=1;i<=m;i++)
        cout<<a[i]<<' ';
    return 0;
}
