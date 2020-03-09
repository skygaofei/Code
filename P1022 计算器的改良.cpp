//
//  main.cpp
//  计算器的改良
//
//  Created by 高飞 on 2018/8/4.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
double num=0,xs=0;
char in,temp;
int number[205],leng=1,midd,sign;
int main()
{
    sign=1;
    while(in!='=')
    {
        in=getchar();
        if(in=='-')
        {
            leng++;
            sign=-1;
        }
        else if(in=='+')
        {
            leng++;
            sign=1;
        }
        if(in>='0'&&in<='9')
        {
            if(!number[leng])
                number[leng]=(in-'0')*sign;
            else
                number[leng]=number[leng]*10+(in-'0')*sign;
        }
        if(in>='a'&&in<='z')
        {
            temp=in;
            if(number[leng]!=0)
            {
                xs+=number[leng];
                number[leng]=0;
            }
            else
                xs+=sign;
            leng--;
        }
    }
    midd=leng;leng++;sign=1;
    while(in!='\n')
    {
        in=getchar();
        if(in=='-')
        {
            leng++;
            sign=-1;
        }
        else if(in=='+')
        {
            leng++;
            sign=1;
        }
        if(in>='0'&&in<='9')
        {
            if(!number[leng])
                number[leng]=(in-'0')*sign;
            else
                number[leng]=number[leng]*10+(in-'0')*sign;
        }
        if(in>='a'&&in<='z')
        {
            temp=in;
            if(number[leng]!=0)
            {
                xs-=number[leng];
                number[leng]=0;
            }
            else
                xs-=sign;
            leng--;
        }
    }
    for(int i=1;i<=leng;i++)
    {
        if(i<=midd)
            num-=number[i];
        else
            num+=number[i];
    }
    if(!(num/xs))
        printf("%c=0.000",temp);
    else
        printf("%c=%.3lf",temp,num/xs);
    return 0;
}
