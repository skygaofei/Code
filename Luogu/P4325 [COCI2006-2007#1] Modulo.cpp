//
//  main.cpp
//  Modulo
//
//  Created by 高飞 on 2018/5/4.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
using namespace std;
int a[50];
int main()
{
    int x;
    int s=0;
    for(int k=1;k<=10;k++)
    {
        cin>>x;
        if(!a[x%42])
        {
            s++;
            a[x%42]=1;
        }
    }
    cout<<s;
    return 0;
}
