//
//  main.cpp
//  螺旋矩阵
//
//  Created by 高飞 on 2018/8/4.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int i,j;
    int n,x,y;
    cin>>n>>i>>j;
    if(i>n/2)
        y=n-i+1;
    else
        y=i;
    if(j>n/2)
        x=n-j+1;
    else
        x=j;
    int m=min(x,y);
    int leftcorner=1;
    for(int k=1;k<m;k++)
    {
        leftcorner+=(n-1)*4;
        n-=2;
    }
    int x2=i-m+1,y2=j-m+1;
    if(x2==1)
        cout<<leftcorner+y2-1;
    else if(y2==1)
        cout<<leftcorner+4*(n-1)-1-x2+2;
    else if(y2>x2)
        cout<<leftcorner+n-1+x2-1;
    else if(x2>y2)
        cout<<leftcorner+4*(n-1)-1-n+2-y2+1;
    return 0;
}
