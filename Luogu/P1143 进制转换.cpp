// luogu-judger-enable-o2
#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char a[1010];
    int s[1010];
    char *stop;
    scanf("%s",a);
    int m;
    scanf("%d",&m);
    int c;
    int l=0;
    long p=strtol(a,&stop,n);
    while(p!=0)//数制转换，结果存入数组s[m]  
    {  
        c=p%m;  
        p=p/m;  
        l++;
        s[l]=c;   //将余数按顺序存入数组s[m]中   
    }    
    for(int k=l;k>=1;k--)//输出转换后的序列  
    {  
        if(s[k]>=10) //若为十六进制等则输出相对应的字母  
            cout<<(char)(s[k]+55);  
        else         //否则直接输出数字  
            cout<<s[k];
}
    return 0;
}
