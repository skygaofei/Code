//
//  main.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/9.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
double a,b,c,d;
double x1,x2,x3;
double A,B,C,delta;
double k;
double t,_ceta,ceta;
int main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    A=b*b-3*a*c;
    B=b*c-9*a*d;
    C=c*c-3*b*d;
    delta=B*B-4*A*C;
    if(A==B&&A==0)
        x1=x2=x3=(-b)/(3*a);
    else if(delta==0)
    {
        k=B/A;
        x1=(-b)/a+k;
        x2=x3=(-k)/2;
    }
    else if(delta<0)
    {
        t=(2*A*b-3*a*B)/(2*A*sqrt(A));
        _ceta=acos(t);
        ceta=_ceta/3;
        x1=(-b-2*sqrt(A)*cos(ceta))/(3*a);
        x2=(-b+sqrt(A)*(cos(ceta)+sqrt(3)*sin(ceta)))/(3*a);
        x3=(-b+sqrt(A)*(cos(ceta)-sqrt(3)*sin(ceta)))/(3*a);
    }
    if(x1>x2) swap(x1,x2);
    if(x1>x3) swap(x1,x3);
    if(x2>x3) swap(x2,x3);
    printf("%.2lf %.2lf %.2lf",x1,x2,x3);
    return 0;
}
